#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[40];
    int age;
    float gpa;
    printf("Enter your name.\n");
    //scanf("%39s",name);
    fgets(name, sizeof(name), stdin);
    name[strcspn(name,"\n")] = "\0";

    printf("Enter your age\n");
    scanf("%d",&age);

    printf("Enter your GPA\n");
    scanf("%f",&gpa);

    printf("Name: %s\nAge: %d\nGPA: %f\n",name,age,gpa);

    return 0;
}

