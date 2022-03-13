#include <stdio.h>
union empAdd{
char *ename;
char stname[20];
int pincode;
};

int main(){
    union empAdd employee,*pt;
    employee.ename="Cosmin-Cristian\0Oros";
    pt=&employee;
    printf(" %s %s\n\n",pt->ename,(*pt).ename);
    return 0;
}