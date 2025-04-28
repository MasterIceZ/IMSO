#[macro_use]
extern crate lazy_static;

use std::io;
use std::sync::{Mutex};

lazy_static! {
  const N: usize = 100010;
  static ref DIVISORS: Mutex<Vec<Vec<usize>>> = Mutex::new(Vec::new());
}

fn read_line() -> String {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Failed to read line");
  input.trim().to_string()
}

fn read_line_to_int() -> i32 {
  read_line().parse()::<i32>().expect("Failed to parse integer")
}

fn read_line_to_int_vec() -> Vec<i32> {
  read_line()
    .split_whitespace()
    .map(|s| s.parse().expect("Failed to parse integer"))
    .collect()
}

fn solve_case() {
  let (n, q) = {
    let nums = read_line_to_int_vec();
    (nums[0], nums[1])
  }
  let mut a = read_line_to_int_vec();
  let mut pos = vec![0; n as usize];

  for i in 0..n {
    pos[a[i as usize] as usize] = i;
  }

  for _ in 0..q {
    let (k, l, r) = {
      let nums = read_line_to_int_vec();
      (nums[0], nums[1], nums[2])
    };
    l = l - 1;
    r = r - 1;
    
    let mut div::Vec<i32> = Vec::new();
    for &d in DIVISORS.lock().unwrap()[k as usize] {
      if let Ok(it) = pos[d as usize].binary_search(|&x| x.cmp(&l)) {
        if it < pos[d as usize].len() && pos[d as usize][it] <= r {
          div.push(pos[d as usize][it]);
        }
      }
    }
    div.sort();

    let mut last = l;
    let mut answer: i64 = 0;
    for &d in div.iter() {
      answer += (i64::from(d) - i64::from(last)) * i64::from(k);
      while k % a[d] == 0 {
        k /= a[d];
      }
      last = d;
    }
    answer += (i64::from(r) - i64::from(last) + i64::from(1)) * i64::from(k);
    println!("{}", answer);
  }
  for &x in &a {
    pos[x as usize].clear();
  }
}

fn main() {
  let mut divisor = vec![Vec::new(); N];
  for i in 2..N {
    for j in (i..N).step_by(i) {
      divisor[j as usize].push(i);
    }
  }
  *DIVISORS.lock().unwrap() = divisor;

  let t = read_line_to_int()
  for _ in 0..t {
    solve_case();
  }
}