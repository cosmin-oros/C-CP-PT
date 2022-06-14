#include <stdio.h>

/*
1. A simple classification of stars is as follows:
(a) Main Sequence Stars characterized by: age category (an integer
value between 1 and 4) and color (a character array of at most
12 characters)
(b) Binary Stars rotating around a mass center characterized by:
rotation radius for the first and the second star
(c) Variable Light Stars characterized by: lowest luminosity, highest luminosity and light periodicity measured in Earth days
All stars have a name of arbitrary length. Use composite variables
and bit fields and write a program that reads data about a star and
then prints it back on the screen.
*/

#define N 1000

struct stars{
    enum type{
        MainSequence=1,
        Binary=2,
        VariableLight=3
    }starType;
    unsigned exists;
    union{
        struct{
            unsigned int ageCateg : 2;  //<-- segmentation fault
            char color[12];
            char name[20];
        }mainSeq;
        struct{
            float rotRadiusFirst;
            float rotRadiusSecond;
            char name[20];
        }binary;
        struct{
            float lowLuminosity;
            float highLuminosity;
            float lightPeriodicity;
            char name[20];
        }varLight;

    }characteristics;

}s[N];

void read(struct stars* s){
    unsigned key=1;
    unsigned size=0;
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    while (key)
    {
        printf("Enter the type of star, '1' for a main sequence star, '2' for a binary star,\n'3' for a variable light star ,if you want to exit out of the program enter '0'.\n\n");
        scanf("%u",&key);
        if (key==1)
        {
            s[size].exists=1;
            printf("Enter the age of the star (1-4), the color and the name\n");
            scanf("%u %s %s",s[size].characteristics.mainSeq.ageCateg,s[size].characteristics.mainSeq.color,s[size].characteristics.mainSeq.name);
        }
        else if (key==2)
        {
            s[size].exists=0;
            printf("Enter the rotation radius of the first and second star and the name\n");
            scanf("%f %f %s",&s[size].characteristics.binary.rotRadiusFirst,&s[size].characteristics.binary.rotRadiusSecond,s[size].characteristics.binary.name);
        }
        else if (key==3)
        {
            s[size].exists=0;
            printf("Enter the lowest luminosity, highest luminosity, the light periodicity and the name\n");
            scanf("%f %f %f %s",&s[size].characteristics.varLight.lowLuminosity,&s[size].characteristics.varLight.highLuminosity,
            &s[size].characteristics.varLight.lightPeriodicity,s[size].characteristics.varLight.name);
        }
        else if (!key)
        {
            break;
        }
        
        else{
            printf("Wrong input\n\n");
        }
        size++;
    }
    s[size].exists=0;
}

void write(struct stars* s){
    int pos=1;
    for (int i = 0; s[i].exists; i++)
    {
        if (s[i].starType==MainSequence)
        {
            printf("Star %d) ",pos);
            printf("name: %s\nAge category: %u\nColor: %s\n",s[i].characteristics.mainSeq.name,s[i].characteristics.mainSeq.ageCateg,s[i].characteristics.mainSeq.color);
            pos++;
        }
        
    }
    pos=1;
    for (int i = 0; s[i].exists; i++)
    {
        if (s[i].starType==Binary)
        {
            printf("Star %d) ",pos);
            printf("name: %s\nRotation radius of the first star: %f\nRotation radius of the second star: %f\n",s[i].characteristics.binary.name,
            s[i].characteristics.binary.rotRadiusFirst,s[i].characteristics.binary.rotRadiusSecond);
            pos++;
        }
           
    }
    pos=1;
    for (int i = 0; s[i].exists; i++)
    {
        if (s[i].starType==VariableLight)
        {
            printf("Star %d) ",pos);
            printf("name: %s\nLowest luminosity: %f\nHighest luminosity: %f\nLight periodicity: %f\n",s[i].characteristics.varLight.name,
            s[i].characteristics.varLight.lowLuminosity,s[i].characteristics.varLight.highLuminosity,s[i].characteristics.varLight.lightPeriodicity);
            pos++;
        }
        
    }
    
}

int main(){
    read(s);
    write(s);
    return 0;
}