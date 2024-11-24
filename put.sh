#!/bin/bash
date=$(date +%m-%d)

# name in format name-m-d
name="$2-($date).cpp"

# get replace all bad characters with -
options=" /"
name=$(echo "$name" | sed "s:[$options]:-:g")

# create temp folder for github structure
mkdir -p solutions

# temporarily move to folder
cp $1.cpp "solutions/$name"

# add and push from folder
git add "solutions/$name"
git commit -m "auto add: $name"

# cleanup
rm -rf solutions
