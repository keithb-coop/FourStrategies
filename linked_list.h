//
// Created by Coop Workspace on 19/03/2024.
//

#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H


typedef const int * IntPtr;

typedef struct IntListNode{
    IntPtr value;
    struct IntListNode * next;
    bool isBottom; // hurrah for C99!
} IntListNode;

typedef struct IntListNode * IntListPtr;
typedef IntListPtr IntList;

IntListPtr new_linked_list();

IntListPtr prepend(const int *value, IntListPtr old_head);

IntListPtr list_from_array(const int *array_of_numbers);

int value_in_head(IntListPtr intList);

bool no_tail(const struct IntListNode *intList);

IntListPtr tail_of(IntListPtr intList);

void delete_list(struct IntListNode *head);

#endif //UNTITLED_LINKED_LIST_H
