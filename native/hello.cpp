#include <iostream>

struct Foo {
    ~Foo() { std::cout << "~Foo" << std::endl; }
};

int main() {
    std::cout << "Hello, world!" << std::endl;
}
