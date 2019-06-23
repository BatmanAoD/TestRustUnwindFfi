use std::env;

fn main() {
    let project_dir = env::var("CARGO_MANIFEST_DIR").unwrap();

    println!("cargo:rustc-link-search={}/native", project_dir);
    // Needed on Mac OS for some reason...?
    println!("cargo:rustc-link-lib=c++");
}
