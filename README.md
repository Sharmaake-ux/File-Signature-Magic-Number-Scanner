# File Signature Scanner

## Overview
File extensions can be easily spoofed or lost during data corruption. This C++ utility reads the "magic numbers" (file signatures) stored in the first few bytes of a file's binary header to accurately determine the true file type. 

## How it Works
The program opens the target file in binary mode, extracts the first four bytes, and compares them against a database of known hexadecimal signatures for common formats like PDF, JPEG, and PNG.

## Usage
Compile the code:
`g++ main.cpp -o scanner`

Run the program:
`./scanner`
Provide the path to the file you want to analyze when prompted.
