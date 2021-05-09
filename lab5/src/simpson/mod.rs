pub fn exp(x: f64) -> f64 {
    const MAX_ITER: i32 = 200; 
    let mut sum = 1.0;
    let mut term = 1.0;

    for n in 1..MAX_ITER {
    term *= x / n as f64;
    sum += term;
    };
return sum
}

fn probe_func_sec(x: f64, y: f64) -> f64 {
    return 2.0 * x.cos() / 
        (1.0 - (x.sin().powi(2)) * (y.cos().powi(2)));
}

pub fn probe_func_main(x: f64, y: f64, p: f64) -> f64 {
    return (4.0 / std::f64::consts::PI) * 
        (1.0 - exp(-p * probe_func_sec(x, y))) * 
        x.cos() * x.sin();
}


pub fn simpson(func: Box<dyn Fn(f64) -> f64>, a: f64, b: f64, num: usize) -> f64 {

    if num < 3 || num & 1 == 0 {
        panic!("Wrong num value!");
    }

    let h: f64 = (b - a) / (num - 1) as f64;

    let mut x: f64 = a;

    let mut res: f64 = 0.0;

    for n in 0..((num - 1) / 2) {
        res += func(x) + 4.0 * func(x + (h as f64)) + func(x + 2.0 * (h as f64));
        x += 2.0 * (h as f64);
    }
    return res * (h as f64 / 3.0);
}

