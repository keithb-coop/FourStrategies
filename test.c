//
// Created by Coop Workspace on 19/03/2024.
//

#include "closures.h"
#include "linked_list.h"
#include <printf.h>
#include <stdlib.h>
#include "test.h"

void report_if_not(bool b, const char *string, int actual) {
    if(! b) {
        printf("failed: %s  got: %d\n", string, actual);
    }
}