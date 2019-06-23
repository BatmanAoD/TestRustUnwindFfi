#include <stdio.h>
#include <stdlib.h>

#include "HasDestructorC.h"

void(*ErrorHandler)(int errCode) = NULL;

void Work() {
    printf("Doing work...\n");
    if (ErrorHandler != NULL) {
        printf("Calling injected error handler\n");
        (*ErrorHandler)(42);
    }
    else {
        printf("An error occurred, but no handler was injected.");
    }
}

void Entry(void(*onErr)(int errCode)) {
    ErrorHandler = onErr;
    DoSomeWork(&Work);
}
