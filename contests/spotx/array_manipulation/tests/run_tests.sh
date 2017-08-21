#!/bin/sh
echo "TEST1";
cat ./tests/test1.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST2";
cat ./tests/test2.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST3";
cat ./tests/test3.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST4";
cat ./tests/test4.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST5";
cat ./tests/test5.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST6";
cat ./tests/test6.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST7";
cat ./tests/test7.txt | ./cmake-build-debug/bin/array_manipulation;
echo "\nTEST8";
cat ./tests/test8.txt | ./cmake-build-debug/bin/array_manipulation;
