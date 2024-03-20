#include <stdlib.h>

#include "linked_list.h"
#include "closures.h"
#include "test.h"

// forward declarations
int iterativeP_iterativeD_sum(const int array_of_numbers[5]);
int recursiveP_recursiveD_sum(IntListPtr intList);
int iterativeP_recursiveD_sum(IntList intList);
int recursiveP_iterativeD_sum(const int array_of_numbers[5]);

// tests!
// we will implement functions with names like ${process}P_${definition}D_sum
// where ${process} and ${definition} may be "iterative" or "recursive"
int main() {
    const int array_of_numbers[] = {1, 2, 3, 4, 5} ;
    const int expectedSum = 1 + 2 + 3 + 4 + 5;
    int sum;

    sum = iterativeP_iterativeD_sum(array_of_numbers),
    report_if_not(expectedSum == sum, "iterativeP_iterativeD_sum", sum);

    //Recursion over arrays is hard, lists are more comfortable as they are a recursive type anyway.
    // List<T> = [] -- the unit of the monoid
    //         | prepend(t: T, l: List<T>): List<T> -- the monoid rule

    IntListPtr list_of_numbers = list_from_array(array_of_numbers);

    sum = recursiveP_recursiveD_sum(list_of_numbers);
    report_if_not(expectedSum == sum, "recursiveP_recursiveD_sum", sum);

    sum = iterativeP_recursiveD_sum(list_of_numbers);
    report_if_not(expectedSum == sum, "iterativeP_recursiveD_sum", sum);

    sum = recursiveP_iterativeD_sum(array_of_numbers);
    report_if_not(expectedSum == sum, "recursiveP_iterativeD_sum", sum);

    delete_list(list_of_numbers); //tidiness is important
    return EXIT_SUCCESS;
}


// domain functions
int iterativeP_iterativeD_sum(const int array_of_numbers[5]) {
    int sum = 0; // this is an iterative *process* because it has a name for the "sum so far"
    int index = 0;
    ITERATE: // a `for` loop is merely syntactic sugar for this
    if (index < 5) { // have to remember to get this right
        sum += array_of_numbers[index]; // have to hold this in mind to understand the loop
        index++;
        goto ITERATE; // this is an iterative *definition* because it explicitly repeats
    }

    return sum;
}

int recursiveP_recursiveD_sum(IntListPtr intList) {
    if(no_tail(intList)){
        return value_in_head(intList);
    } else { // this is a recursive *process* as there is no name for the partial sums
        return value_in_head(intList) + recursiveP_recursiveD_sum(tail_of(intList)); //recursive *definition*
    }
}

int sum_helper_iPrD(int partial_sum, IntList list);

int iterativeP_recursiveD_sum(IntList intList) {
    // provides the initial partial sum, 0, identity element of the monoid "natural numbers with addition"
    return sum_helper_iPrD(0, intList);
}

int sum_helper_iPrD(int partial_sum, IntList list) { // iterative *process*, names the partial sums
    // does the work, in the context of `iterativeP_recursiveD_sum`
    if (no_tail(list)) {
        return partial_sum + value_in_head(list);
    } else {
        // this branch is a *tail call* which the compiler may optimise to code which will run in constant
        // space even though it is a recursive call--that, is: no new stack frame will be created on subsequent calls
        // for `clang` the flag to turn this on is `-foptimize-sibling-calls`
        return sum_helper_iPrD( // recursive *definition*
                partial_sum + value_in_head(list),
                tail_of(list));
    }
}

int recursiveP_iterativeD_sum(const int array_of_numbers[5]) {
    ClosurePtr closure = returner(array_of_numbers[0]);
    for(int i = 1; i<5; i++){// iterative *definition*, explicit repetition
        closure = compose(adder(array_of_numbers[i]), closure); // recursive *process*, partial sums no t named
    }
    return closure->fn(closure, 0); // the implementation of this thing is horrid. There's reason that this is the least popular quadrant
}
