//
// Created by Coop Workspace on 19/03/2024.
//

#ifndef UNTITLED_CLOSURES_H
#define UNTITLED_CLOSURES_H

typedef struct Closure{
    int value;
    struct Closure * right;
    struct Closure * left;

    int (*fn)(struct Closure *, int otherValue);
} Closure;

typedef Closure * ClosurePtr;

Closure *new_closure(int value, int (*fn)(ClosurePtr, int));

ClosurePtr returner(int value);
ClosurePtr adder(int value);
ClosurePtr compose(ClosurePtr left, ClosurePtr right);

#endif //UNTITLED_CLOSURES_H
