mod gauss;
mod simpson;

extern crate ndarray;
use ndarray::prelude::*;
use std::f64::consts::PI;

use std::io::{self, Read};

static lm: &'static [f64; 4] = &[0.0, PI / 2.0, 0.0, PI / 2.0];

type Iorfn = fn(Box<dyn Fn(f64) -> f64>, f64, f64, usize) -> f64;
type Iedfn = Box<dyn Fn(f64, f64) -> f64>;

fn Integrated(p: f64) -> Iedfn {
    fn sf(x: f64, y: f64) -> f64 {
        return 2.0 * x.cos() / 
            (1.0 - (x.sin().powi(2)) * (y.cos().powi(2)));
    }

    Box::new(move |x: f64, y: f64| -> f64 {
        
        (4.0 / std::f64::consts::PI) * 
            (1.0 - simpson::exp(-p * sf(x, y))) * 
            x.cos() * x.sin()
    })
}

fn fWrap(f: Box<dyn Fn(f64, f64) -> f64>, val: f64) -> Box<dyn Fn(f64) -> f64> {
    return Box::new(move |val1: f64| -> f64 {
        f(val, val1)
    }
                    ) 
}



fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let N: usize;
    let M: usize;
    let tao: f64;
    let f0: bool;
    let f1: bool;


    println!("Enter N, M, tao, outer integration method, inner integraion method:");
    stdin.read_line(&mut buffer).unwrap();


    let values = buffer
        .split_whitespace()
        .map(|x| x.parse::<f64>())
        .collect::<Result<Vec<f64>, _>>()
        .unwrap();

    N = values[0] as usize;
    M = values[1] as usize;
    tao = values[2]  as f64; 
    f0 = values[3] != 0.0; 
    f1 = values[4]  != 0.0; 

    println!("N: {} M: {} tao: {} om: {} im: {}", 
             N, M, tao, f0, f1);

    let inner: Box<dyn Fn(f64) -> f64>;
    let result: f64;
    if f0 { // false - gauss, simpson - elsewise
        inner = Box::new(move |x: f64| -> f64 {
            gauss::gauss(fWrap(Integrated(tao), x), lm[2], lm[3], M)
        });

    } else {
        inner = Box::new(move |x: f64| -> f64 {
            simpson::simpson(fWrap(Integrated(tao), x), lm[2], lm[3], M)
        });
        
    }

    if f1 {
        result = gauss::gauss(inner, lm[0], lm[1], N);
    } else {
        result =  simpson::simpson(inner, lm[0], lm[1], N);
    }


    println!("Result with {:.2} as a param is {}\n", tao, result);


    


}
