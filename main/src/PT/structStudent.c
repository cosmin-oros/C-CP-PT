#include<stdio.h>
/*Here, we are using nested structure*/
struct student
{
     int roll_num;
     char name[20];
     struct Date
     {
          int D;
          int M;
          int Y;
     }bd,ad;
};
int main()
{
     int r;
     struct student a;
     printf("\tEnter Student Details\n");
     printf("----------------------------------------------------\n");
     printf("Enter Roll-Number    : ");
     scanf("%d",&a.roll_num);
     printf("Enter Name      : ");
     scanf("%s",a.name);
     printf("Enter Birth-Date     : ");
     scanf("%d-%d-%d",&a.bd.D,&a.bd.M,&a.bd.Y);
     printf("Enter Admission-Date : ");
     scanf("%d-%d-%d",&a.ad.D,&a.ad.M,&a.ad.Y);
     r=a.ad.Y-a.bd.Y;
     printf("----------------------------------------------------\n");
     printf("\nApproximate Age of Student at the Time of Admission\n");
     printf("----------------------------------------------------\n");
     printf("\t%d Years\n",r);
     return 0;
}