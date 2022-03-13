#include <stdio.h>

#define SIZE 5

typedef struct student{
    char name[20];
    int grade;
}student;

int main(){
    int temp;
    char tempName[20];
    student students[SIZE];
    printf("Enter the name and grade of the students:\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%s%d",&students[i].name,&students[i].grade);
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; i < SIZE; i++)
        {
            if (students[j].grade<students[i].grade)
            {
                // tempName=students[j].name;
                // students[j].name=students[i].name;
                // students.name[i]=temp;
                temp=students[j].grade;
                students[j].grade=students[i].grade;
                students[i].grade=temp;
            }
            
        }
        
    }
    
    
    return 0;
}