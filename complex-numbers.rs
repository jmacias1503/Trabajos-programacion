use std::io;
fn main() {
    println!("a=");
    let mut a = String::new();
    io::stdin().read_line(&mut a)
        .expect("Linea no valida");
}
