#include <iostream>

#include "HasDestructorC.h"

class HasDestructor {
    ~HasDestructor() {
        std::cout << "HasDestructor(" << this << ") called" << std::endl;
    }
};

extern "C" {
    void DoSomeWork(void(*work)(void)) {
        HasDestructor hd;
        (*work)();
    }
}
