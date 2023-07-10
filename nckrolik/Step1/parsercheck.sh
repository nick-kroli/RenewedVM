#!/bin/bash

# Directory containing the input files
input_dir="ParserInputTest"

# Directory to store the output files
output_dir="ParserOutputTest"

# Executable file
executable="./parser"

# Iterate over each file in the input directory
for file in "$input_dir"/*; do
    # Check if the file is a regular file
    if [ -f "$file" ]; then
        # Extract the file name and extension
        filename=$(basename "$file")
        filename="${filename%.*}"
        
        # Define the output file path
        output_file="$output_dir/$filename.pout"
        
        # Run the executable with the current file as input and redirect the output to the output file
        "$executable" "$file" > "$output_file"
        
        # echo "Processed: $file"
        # echo "Output file: $output_file"
        # echo "---------------------------"
    fi
done