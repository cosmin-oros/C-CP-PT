#include <stdio.h>
#include <stdlib.h>

int main()
{
   char name[50];
   int marks, i, num;

   printf("Enter number of students: ");
   scanf("%d", &num);

   FILE *fptr;
   fptr = (fopen("writeStudentsToFile.txt", "w"));
   if(!fptr)
   {
       printf("Error!\n");
       exit(1);
   }

   for(i = 0; i < num; ++i)
   {
      printf("For student %d\nEnter name: ", i+1);
      fgets(name,50,stdin);

      printf("\nEnter marks: ");
      scanf("%d", &marks);

      fprintf(fptr,"\nName: %s \nMarks=%d \n", name, marks);
   }

   fclose(fptr);
   return 0;
}