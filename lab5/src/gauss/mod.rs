extern crate peroxide;

fn p2v(p: f64, c: f64, d: f64) -> f64 {
    return (d + c) / 2.0 + (d - c) * p / 2.0; 
}

pub fn gauss(func: Box<dyn Fn(f64) -> f64>, a: f64, b: f64, num: usize) -> f64 {

    println!("{}", num);

    let (x, w) = peroxide::special::legendre::gauss_legendre_table(num);

    let mut res: f64 = 0.0;
    

    for i in 0..num {
        res += (b - a) / 2.0 * w[i] * func(p2v(x[i], a, b)); 
    }

    return res;

}
