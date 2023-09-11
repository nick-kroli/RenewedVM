#!/bin/bash

# Directory containing the input files
input_dir="ParserInputTest"

# Directory to store the ascii output files
output_dir="ParserOutputTest"

#Directory to store the binary output files
binary_output_dir="ParserBinaryOut"


# Executable file
executable="./parser"

# Clear the output directory before processing
rm -f "$output_dir"/*
rm -f "$binary_output_dir"/*

# Iterate over each file in the input directory
for file in "$input_dir"/*; do
    # Check if the file is a regular file
    if [ -f "$file" ]; then
        # Extract the file name and extension
        filename=$(basename "$file")
        filename="${filename%.*}"
        
        # Define the output file path
        ascii_output_file="$output_dir/$filename.pout"
        bin_output_file="$binary_out_dir/$filename.bin"
        
        # Run the executable with the current file as input and redirect the output to the output file
        "$executable" "$file"
        
        # echo "Processed: $file"
        # echo "Output file: $output_file"
        # echo "---------------------------"
    fi
done

