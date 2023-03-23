# Task Generating Template

echo "Compiling Generator"
g++ gen.cc -o gen
echo "Compiling Solution"
g++ sol.cc -o sol

echo "Creating Input File"
./gen 5 10 10 100 $(pwgen 12 1) > 1.in
./gen 5 10 20 100 $(pwgen 12 1) > 2.in
./gen 10 20 50 1000 $(pwgen 12 1) > 3.in
./gen 100 400 1000 10000 $(pwgen 12 1) > 4.in
./gen 400 600 1000 10000 $(pwgen 12 1) > 5.in
./gen 900 1000 2000 100000 $(pwgen 12 1) > 6.in
./gen 900 1000 2000 100000 $(pwgen 12 1) > 7.in
./gen 900 1000 2000 100000 $(pwgen 12 1) > 8.in
./gen 900 1000 2000 100000 $(pwgen 12 1) > 9.in
./gen 900 1000 2000 100000 $(pwgen 12 1) > 10.in


echo "Creating Output File"

for i in 1 2 3 4 5 6 7 8 9 10
do
	./sol < $i.in > $i.out
	echo "Generating #$i output"
done

echo "Finsihed"

echo "Removing Executables"
rm sol
rm gen

echo "Zipping Files"

zip testset.zip 1.in 1.out 2.in 2.out 3.in 3.out 4.in 4.out 5.in 5.out 6.in 6.out 7.in 7.out 8.in 8.out 9.in 9.out 10.in 10.out info

echo "Finished All work"
