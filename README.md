A combination of Rust, C, and C++ code that uses an "error handler"
function pointer to initiate a Rust `panic`. The panic may propagate
through both C++ and C stack frames, and the C++ frame includes a
class with a non-trivial destructor.

To build the C and C++ code, run `make all` in the `native` folder.
(Currently, this is not done automatically by `cargo`.)
