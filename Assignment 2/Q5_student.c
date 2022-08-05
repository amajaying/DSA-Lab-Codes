#include <stdio.h>
#include <stdlib.h>
struct student{
    int rollno;
    char name[20];
    char gender;
    float cgpa;
    int placed;
};  
int main(){
    struct student *ptr, stu;
    ptr = &stu;
    char *filename = "students.txt";
    FILE *fp = fopen(filename, "r");

    fscanf(ptr,"%d",&ptr->rollno);
    fscanf(ptr,"%s",&ptr->name);
    fscanf(ptr,"%c",&ptr->gender);
    fscanf(ptr,"%f",&ptr->cgpa);
    fscanf(ptr,"%d",&ptr->placed);  

    printf("%d", ptr->rollno);
}