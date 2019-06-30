#include <stdio.h>
#include <stdlib.h>

#include "HasDestructorC.h"

void(*ErrorHandler)(int32_t errCode) = NULL;

extern void do_unwind(int32_t);

void Work() {
    printf("Doing work...\n");
    if (ErrorHandler != NULL) {
        printf("Calling injected error handler\n");
        (*ErrorHandler)(42);
    }
    else {
        printf("Calling statically-linked error handler");
        // TODO: resolve link error
        // do_unwind(-42);
    }
}

void Entry(void(*onErr)(int32_t errCode)) {
    ErrorHandler = onErr;
    DoSomeWork(&Work);
}
