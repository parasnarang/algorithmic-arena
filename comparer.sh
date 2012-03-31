g++ $1.cpp -o bin/prog1
g++ $2.cpp -o bin/prog2
time ./bin/prog1 < bin/rinput > bin/out1
time ./bin/prog2 < bin/rinput > bin/out2
diff bin/out1 bin/out2
