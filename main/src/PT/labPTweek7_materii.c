#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct students{
    /*name of the students*/
    char name[20];  
    /*union for all the subjects*/
    union{
        /*struct for the grades for the history subject*/
        struct{
            int grade[3];
        }history;
        /*struct for the grades for the maths subject*/
        struct{
            int grade[3];
        }maths;
        /*struct for the grades for the romanian subject*/
        struct{
            int grade[3];
        }romanian;
    }subject;

}s[3];   

void getData(FILE* fptr){
    int c;
    int k=0,l=0;
    while ((c=fgetc(fptr))!=EOF)
    {
        for (int i = 0; c!='\n'; i++)
        {
            if (i==0)
            {
                while (c!=' ')
                {
                    s[k].name[i]=c; /*extract the name of the student*/
                    c=fgetc(fptr);
                    i++;
                }
                
            }
            else{
                if (c=='r')
                {
                    while (c!=' ')
                    {
                        c=fgetc(fptr);
                    }
                    while (l<3)
                    {
                        if (isdigit(c))
                        {
                            s[k].subject.romanian.grade[l]=c;
                            l++;
                        }
                        c=fgetc(fptr);
                        
                    }
                
                }else if (c=='h')
                {
                    while (c!=' ')
                    {
                        c=fgetc(fptr);
                    }
                    while (l<3)
                    {
                        if (isdigit(c))
                        {
                            s[k].subject.history.grade[l]=c;
                            l++;
                        }
                        c=fgetc(fptr);
                        
                    }
                }
                else if (c=='m')
                {
                    while (c!=' ')
                    {
                        c=fgetc(fptr);
                    }
                    while (l<3)
                    {
                        if (isdigit(c))
                        {
                            s[k].subject.maths.grade[l]=c;
                            l++;
                        }
                        c=fgetc(fptr);
                        
                    }
                }
                
            }
            l=0;
            
        }
        k=0;
            
        
    }
}

void printData(){
    for (int i = 0; i < 3; i++)
    {
        printf("%s ",s[i].name);    /*print the name of the student*/
        printf("maths");
        printf(" %d %d %d ",s[i].subject.maths.grade[0],
                          s[i].subject.maths.grade[1],
                          s[i].subject.maths.grade[2]); /*print the grades for the math subject*/
        printf("romanian");
        printf(" %d %d %d ",s[i].subject.romanian.grade[0],
                          s[i].subject.romanian.grade[1],
                          s[i].subject.romanian.grade[2]); /*print the grades for the romanian subject*/
        printf("history");
        printf(" %d %d %d ",s[i].subject.history.grade[0],
                          s[i].subject.history.grade[1],
                          s[i].subject.history.grade[2]); /*print the grades for the history subject*/
        printf("\n");
    }
    
}

int main(int argc,char** argv){
    FILE* fptr = fopen("subjectGrades.txt","r");
    if (argc<1)
    {
        printf("Not enough arguments\n");
        return -1;
    }
    char* sub = argv[1];
    printf("%s",sub);
    getData(fptr);
    printData();
    fclose(fptr);
    return 0;
}