#[link(name = "DoWork", kind = "static")]
extern {
    fn Entry(err_code: Option<extern fn (i32)>);
}

#[no_mangle]
pub extern "C" fn do_unwind(err_code: i32) {
    panic!(format!("Panic from 'DoUnwind'; error code: {}", err_code));
}

fn main() {
    unsafe {
        // Entry(do_unwind);
        Entry(None);
    }
}
