#!/bin/bash
date=$(date +%m-%d)
name="$2($date).cpp"
mkdir solutions
cp $1.cpp solutions/$name
git add solutions/$name
git commit -m "auto add: $name"
rm -rf solutions
