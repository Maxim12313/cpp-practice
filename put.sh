#!/bin/bash

mkdir solutions
cp $1.cpp solutions/$2.cpp
git add solutions/$2.cpp
git commit -m "auto add: $2.cpp"
rm -rf solutions
