#include <stdio.h>
#include <string.h>

struct student_college_detail{
    int college_id;
    char college_name[50];
};

struct student_detail{
    int id;
    char name[20];
    float percentage;
    struct student_college_detail clg_data;
} stu_data, *stu_data_ptr;

int main(){
    struct student_detail stu_data = {1,"Ion",90.5,81231,"UPT"};
    stu_data_ptr=&stu_data;
    printf("ID is: %d\n",stu_data_ptr->id);
    printf("Name is: %s\n",stu_data_ptr->name);
    printf("Percentage is: %f\n",stu_data_ptr->percentage);
    printf("College ID is: %d\n",stu_data_ptr->clg_data.college_id);
    printf("College name is: %s\n",stu_data_ptr->clg_data.college_name);
    return 0;
}