#![feature(panic_runtime)]
#![crate_type = "rlib"]

#![no_std]
#![panic_runtime]

#[no_mangle]
pub extern fn __rust_maybe_catch_panic() {}

fn foo() {}

#[no_mangle]
pub extern "C" fn __rust_start_panic() {
    foo();
}

#[no_mangle]
pub extern fn rust_eh_personality() {}
