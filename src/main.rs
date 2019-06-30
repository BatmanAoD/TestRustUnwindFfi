#[link(name = "DoWork", kind = "static")]
extern {
    fn Entry(err_code: extern fn (i32));
}

pub extern "C" fn _do_unwind(err_code: i32) {
    panic!(format!("Panic from 'DoUnwind'; error code: {}", err_code));
}


fn main() {
    unsafe {
        // Entry(do_unwind);
        Entry(std::mem::zeroed());
    }
}
