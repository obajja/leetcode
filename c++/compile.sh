#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

cpp_file="$1"
exe_directory=".exe"

if [ ! -f "$cpp_file" ]; then
    echo "File '$cpp_file' not found."
    exit 1
fi

# Create the exe directory if it doesn't exist
mkdir -p "$exe_directory"

base_name="$exe_directory/$(basename "$cpp_file" .cpp)"

g++ -o "$base_name" "$cpp_file"

if [ $? -eq 0 ]; then
    echo -e "Compilation successful. Running the program...\n"
    ./$base_name
else
    echo "Compilation error."
    exit 1
fi
