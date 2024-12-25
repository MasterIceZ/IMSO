use std::io::{self};

fn main() {
  let mut input = String::new();
  let _ = io::stdin().read_line(&mut input);
  let n: usize = input.trim().parse::<usize>().unwrap();

  let mut input = String::new();
  let _ = io::stdin().read_line(&mut input);
  let mut a: Vec<i32> = input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();

  let mut input = String::new();
  let _ = io::stdin().read_line(&mut input);
  let mut b: Vec<i32> = input.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).collect();
  
  a.sort();
  b.sort_by(|a, b| b.cmp(a));

  let mut c: Vec<i32> = Vec::new();
  for i in 0..n {
    c.push(a[i] + b[i]);
  }

  c.sort();
  let mut sum: i32 = 0;
  for i in 1..n {
    sum += c[i] - c[i - 1];
  }

  println!("{}", sum);
}