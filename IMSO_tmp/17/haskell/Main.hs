square x = x * x

add x y = x + y

mylen [] = 0
mylen (x:xs) = 1 + mylen xs

mysum [] = 0
mysum (x:xs) = x + (mysum xs)

-- append 1 [2, 3, 4, 5] => [2, 3, 4, 5, 1]

append x [] = [x]
append x (y:ys) = y:(append x ys)

rev [] = []
rev (x:xs) = append x (rev xs)

-- T(n) = T(n - 1) + O(n) => O(n^2)
rev2 xs = let
    rev_ [] ys = ys
    rev_ (x:xs) ys = rev_ xs (x:ys)
  in
    rev_ xs []
-- T(n) = T(n - 1) + O(1) => O(n)


merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys) = if x < y
  then x:(merge xs (y:ys))
  else y:(merge (x:xs) ys)

splitlist [] = ([], [])
splitlist (x:[]) = ([x], [])
splitlist (x:y:xs) = let
    (z1,z2) = splitlist xs
  in
    ((x:z1),(y:z2))

mergesort [] = []
mergesort [x] = [x]
mergesort xs = let
    (left, right) = splitlist xs
  in
    merge (mergesort left) (mergesort right)
