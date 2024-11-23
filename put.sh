#!/bin/bash

cp $1.cpp $2.cpp
git add $2.cpp
git commit -m "auto add: $2.cpp"
rm $2.cpp
