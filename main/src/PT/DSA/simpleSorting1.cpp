#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. A text file contains student data regarding class options. This file is 10,000 lines long and contains 2 lines for each student: 
the sutudent's name on line 1, and four codes for each subject on the second line. Knowing that there are 5,000 students and no name is longer than 35 characters:
    - read and store the data in an array of 5,000 elements and of layout: name, optional1, optional2, optional3, optional4
    - Using shakersort, display the student names in ascending and in then in descending order by name and display the number of comparisons and interchanges done.
    - Using insertion sort, display the student classes in ascending descending order by name.
*/

#define N 5000

typedef struct Student{
    // full name of student
    char name[35];

    // the 4 optionals for the student
    char optional1[2];
    char optional2[2];
    char optional3[2];
    char optional4[2];

}student;

// function to read data from the file and store it in an array 
void readData(FILE* fp, student s[N]){
    char* tempOptionals;

    for (int i = 0; i < N; i++)
    {
        // the first line is the name and the second the optionals
        fgets(s[i].name, 35, fp);
        fgets(tempOptionals, 12, fp);

        // split the optionals
        char* token = strtok(tempOptionals, " ");
        strcpy(s[i].optional1, token);
        token = strtok(NULL, " ");
        strcpy(s[i].optional2, token);
        token = strtok(NULL, " ");
        strcpy(s[i].optional3, token);
        token = strtok(NULL, "\n");
        strcpy(s[i].optional4, token);
        
    }
    
}

// function to print the student array data
void printData(student s[N]){
    for (int i = 0; i < N; i++)
    {
        printf("%s\n%s %s %s %s\n", s[i].name, s[i].optional1, s[i].optional2, s[i].optional3, s[i].optional4);
    }
    
}

int main(int argc, char** argv){
    // open the file then check if it was opened
    FILE* fp = fopen("Studenti1.txt", "r");

    if (!fp)
    {
        printf("Couldn't open the text file\n");
        return -1;
    }

    // students array
    student s[N];

    readData(fp, s);
    printData(s);

    return 0;
}