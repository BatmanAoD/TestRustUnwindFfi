#![feature(unwind_attributes)]

#[link(name = "DoWork", kind = "static")]
extern {
    fn Entry(err_code: Option<extern fn (i32)>);
}

#[no_mangle]
#[unwind(allowed)]
pub extern "C" fn do_unwind(err_code: i32) {
    panic!(format!("Panic from 'DoUnwind'; error code: {}", err_code));
}

fn main() {
    unsafe {
        Entry(Some(do_unwind));
        // Entry(None);
    }
}
