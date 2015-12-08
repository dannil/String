#!/bin/sh
g++ String.h String.cpp Main.cpp -o String -std=c++11
valgrind --leak-check=full ./String
rm String
