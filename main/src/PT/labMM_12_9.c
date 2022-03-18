#include <stdio.h>

/*
9. List ZIP file contents Write a program that lists the names of the files from a .zip archive (whose name is given on the commandline) 
in decreasing order of their uncompressed size. Here is a zip archive of sample programs written this semester.
The .zip file format is defined here. We will handle a simplified case; additional checks should be added for a robust program.
All integer values are stored in binary, in little-endian byte order. Since the x86 architecture is little-endian, 
they will be placed in memory in the correct byte order when read with fread.
*/

int main(int argc,char** argv){
    FILE* zip = fopen(argv[1],"r");
    //...
    return 0;  
}