//
// Created by Coop Workspace on 19/03/2024.
//

#include "linked_list.h"
#include <printf.h>
#include <stdlib.h>
#include "closures.h"
#include "linked_list.h"

int theValue(ClosurePtr closure, int otherValue){
    return closure->value;
}

ClosurePtr returner(const int value) {
    return new_closure(value, &theValue);
}

int add_the_value(ClosurePtr closure, int otherValue){
    return otherValue + closure->value;
}

ClosurePtr adder(const int value) {
    return new_closure(value, &add_the_value);
}

Closure *new_closure(const int value, int (*fn)(ClosurePtr, int)) {
    Closure *aClosure = (Closure *) malloc(sizeof(Closure));
    aClosure->fn      = fn;
    aClosure->value   = value;
    return aClosure;
}

int right_then_left(ClosurePtr closure, const int n){
    return closure->left->fn(
            closure->left,
            closure->right->fn(
                    closure->right,
                    n));
}

ClosurePtr compose(ClosurePtr left, ClosurePtr right){
    Closure *closure = new_closure(0,&right_then_left);

    closure->right = right;
    closure->left  = left;

    return closure;
}
