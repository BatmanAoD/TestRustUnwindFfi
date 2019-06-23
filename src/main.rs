#[link(name = "DoWork", kind = "static")]
extern {
    fn Entry(err_code: extern fn (i32));
}

extern "C" fn do_unwind(err_code: i32) {
    panic!(format!("Panic from 'DoUnwind'; error code: {}", err_code));
}


fn main() {
    unsafe {
        Entry(do_unwind);
    }
}
