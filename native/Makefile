UsesInjectableErrHandler.o: UsesInjectableErrHandler.c HasDestructorC.h
	clang -fexceptions -c UsesInjectableErrHandler.c

HasDestructor.o: HasDestructor.cpp HasDestructorC.h
	clang++ -c HasDestructor.cpp

libDoWork.a: HasDestructor.o UsesInjectableErrHandler.o
	ar -rv libDoWork.a HasDestructor.o UsesInjectableErrHandler.o

.PHONY: all
all: libDoWork.a

.PHONY: clean
clean:
	rm -f *.a *.o
