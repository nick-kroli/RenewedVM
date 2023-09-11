#!/bin/bash


input_dir="ParserInputTest"

output_dir="ParserOutputTest"

binary_output_dir="ParserBinaryOut"

executable="./parser"

rm -f "$output_dir"/*
rm -f "$binary_output_dir"/*


for file in "$input_dir"/*; do
    if [ -f "$file" ]; then

        filename=$(basename "$file")
        filename="${filename%.*}"
        ascii_output_file="$output_dir/$filename.pout"
        bin_output_file="$binary_out_dir/$filename.bin"
        
        "$executable" "$file"
    
    fi
done

