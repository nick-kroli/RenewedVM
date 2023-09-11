#!/bin/bash

# Directory containing the input files
input_dir="VMInputTest"

bin_input_dir="VMBinaryInput"

# Directory to store the output files
output_dir="VMOutputTest"

# Executable file
executable="./vm"


for file in "$input_dir"/*; do

    if [ -f "$file" ]; then
 
        filename=$(basename "$file")
        filename="${filename%.*}"
        
 
        output_file="$output_dir/$filename.pout.vout"
        bin_in="$bin_input_dir/$filename.bin"
        "$executable" "$file" "$bin_in"
    fi
done