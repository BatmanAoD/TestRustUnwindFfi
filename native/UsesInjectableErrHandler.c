#include <stdio.h>
#include <stdlib.h>

#include "HasDestructorC.h"

void(*ErrorHandler)(int32_t errCode) = NULL;

void do_unwind(int32_t);

void Work() {
    printf("Doing work...\n");
    if (ErrorHandler != NULL) {
        fprintf(stderr, "Calling injected error handler\n");
        (*ErrorHandler)(42);
    }
    else {
        fprintf(stderr, "Calling statically-linked error handler\n");
        do_unwind(-42);
    }
}

void Entry(void(*onErr)(int32_t errCode)) {
    ErrorHandler = onErr;
    DoSomeWork(&Work);
}
