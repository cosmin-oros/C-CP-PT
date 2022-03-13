#include <stdio.h>
#include <string.h>

/*
Write a program to show the top students from a class given
their names and grades. The program should read the names of
the students and their grades from the keyboard. The program
will display a menu and allow the user to sort the students by
alphabetic order or by grades. For example the menu can look like
this:
0. Exit program
1. Give N, number of students
2. Enter the students
3. Display class in alphabetic order
4. Display class creating a top based on grades
5. Display the first 3 students according to their grades
but feel free to improve.
*/

struct student{
    char name[10];
    unsigned grade;
}students[100];

void sortAlphab(struct student students[],unsigned stdNr){
    char temp[100];
    unsigned tmp;
    for(unsigned i=0;i<(stdNr-1);i++){
        for(unsigned j=i+1;j<stdNr;j++){
            if(strcmp(students[i].name,students[j].name)>0){
                strcpy(temp,students[i].name);
                tmp=students[i].grade;
                strcpy(students[i].name,students[j].name);
                students[i].grade=students[j].grade;
                strcpy(students[j].name,temp);
                students[j].grade=tmp;
            }
        }
    }
    if (students[0].grade==0)
    {
        for (unsigned i = 0; i < stdNr; i++)
        {
            strcpy(students[i].name,students[i+1].name);
            students[i].grade=students[i+1].grade;
        }
    }
    
}

void sortByGrade(struct student students[],unsigned stdNr){
    unsigned temp;
    char tmp[100];
    for (unsigned i = 0;i<(stdNr-1); i++)
    {
        for (unsigned j = i+1;j<stdNr; j++)
        {
            if (students[i].grade<students[j].grade)
            {
                temp=students[i].grade;
                strcpy(tmp,students[i].name);
                students[i].grade=students[j].grade;
                strcpy(students[i].name,students[j].name);
                students[j].grade=temp;
                strcpy(students[j].name,tmp);
            }
            
        }
        
    }
    if (students[0].grade==0)
    {
        for (unsigned i = 0; i < stdNr; i++)
        {
            strcpy(students[i].name,students[i+1].name);
            students[i].grade=students[i+1].grade;
        }
    }
    
}

int main(){
    unsigned control=1;
    unsigned N,nrOfStudentsAssigned=0,studentNr=1,studentsAssigned=0;
    while (control)
    {
        printf("----------------------\n");
        printf("0. Exit program\n1. Give N, number of students\n2. Enter the students\n3. Display class in alphabetic order\n4. Display class creating a top based on grades\n5. Display the first 3 students according to their grades\n");
        printf("----------------------\n");
        scanf("%d",&control);
        if (control==1 && nrOfStudentsAssigned==0)
        {
            printf("Enter the number of students:");
            scanf("%d",&N);
            nrOfStudentsAssigned=1;
        }
        else if (control==1 && nrOfStudentsAssigned)
        {
            printf("Sorry, you already chose the number of students!\n");
        }
        else if (control==2 && studentsAssigned==0)
        {
            studentsAssigned=1;
            while (N)
            {
                printf("\nStudent nr %d:",studentNr);
                scanf("%s %d",students[studentNr].name,&students[studentNr].grade);
                studentNr++;
                N--;
            }
            
        }
        else if (control==2 && studentsAssigned)
        {
            printf("Sorry, you already assigned the names and grades for the students!\n");
        }
        else if (control==3)
        {
            sortAlphab(students,studentNr);
            for (int i = 0; i<studentNr; i++)
            {
                if(students[i].grade!=0){
                    printf("%d. %s grade %d\n",(i+1),students[i].name,students[i].grade);
                }
            }
            
        }
        else if (control==4)
        {
            sortByGrade(students,studentNr);
            for (int i = 0; i<studentNr; i++)
            {
                if (students[i].grade!=0)
                {
                    printf("%d. %s grade %d\n",(i+1),students[i].name,students[i].grade);
                }
            }
        }
        else if (control==5)
        {
            sortByGrade(students,studentNr);
            for (int i = 0; (i < 3) && i<studentNr; i++)
            {
                if (students[i].grade!=0)
                {
                    printf("%d. %s grade %d\n",(i+1),students[i].name,students[i].grade);
                }
            }
            
        }
        else if (control>5)
        {
            printf("Wrong input try again!\n");
        }
    }
    
    return 0;
}