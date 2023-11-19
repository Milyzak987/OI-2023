#!/bin/bash
g++ sat.cpp -std=c++20 -O3 -o sat
g++ satchk.cpp -std=c++20 -O3 -o satchk
for plik in tests/*; do
  ./sat < "$plik" > out
  echo -n "${plik#tests/}: "
  ./satchk < "$plik"
done
rm out sat satchk
