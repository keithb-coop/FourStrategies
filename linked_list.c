//
// Created by Coop Workspace on 19/03/2024.
//

#include <printf.h>
#include <stdlib.h>
#include "linked_list.h"

// the world is full of linked-list implementations in C because bashing this out from memory is
// easier than finding and installing a library
IntListPtr new_linked_list() {
    struct IntListNode * tail = malloc(sizeof(struct IntListNode));
    tail->value    = (const int *) NULL;
    tail->next     = (struct IntListNode *) NULL;
    tail->isBottom = true;
    return tail;
}

IntListPtr prepend(const int *value, IntListPtr old_head){
    struct IntListNode * new_head = malloc(sizeof(struct IntListNode));
    new_head->value    = value;
    new_head->next     = old_head;
    new_head->isBottom = false;
    return new_head;
}

IntListPtr list_from_array(const int *array_of_numbers) {
    struct IntListNode *list_of_numbers = new_linked_list();
    for (int i = 0; i < 5; i++){
        list_of_numbers = prepend(&array_of_numbers[i], list_of_numbers);
    }
    return list_of_numbers;
}

int value_in_head(const IntListPtr intList) { return *(intList->value); }

bool no_tail(const struct IntListNode *intList) { return intList->next->isBottom; }

IntListPtr tail_of(IntListPtr intList) { return intList->next; }

void delete_list(IntListPtr head){
    struct IntListNode * next = head->next;
    if(!next->isBottom){
       delete_list(next);
    }
    free(head);
}