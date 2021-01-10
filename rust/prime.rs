
fn main() {
    let max = 1000000;
    for n in (3..max).step_by(2) {
        let mut prime = 1;
        // let sqr = num::sqrt(n);
        let sqr = (n as f64).sqrt() as i32;
        
        for i in (3..sqr).step_by(2){
            if n%i == 0 {
                prime = 0;
                break;
            }
        }
        if prime==1{
            println!("{}", n)
        }
    }
  
}
