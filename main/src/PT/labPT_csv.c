#include <stdio.h>

/*
 *Consider a text file in a CSV (Comma Separated Value) format containing information about rock songs. Write a C program that takes 2 arguments, 
 *the file-path of the CSV file and a year number. The program shall read the entire file and store the following information into an array of an appropriate data structure: 
 *song, artist, release year. 
 *The program shall then print on standard output only those songs that where released in the year that was given as second argument to the executable program.
 */

int main(){
    FILE* fptr = fopen("classic-rock-song-list.csv","r");
    //----homework----
    return 0;
}