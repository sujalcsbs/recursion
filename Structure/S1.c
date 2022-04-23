#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    unsigned long int roll;
    char name[30];
    char stream[30];
}s_details;
 
int main(int argc, char *argv[])
{
    s_details *class;
    char dump;
    int n;
    printf("Enter the number of student details you want to store: ");
    scanf("%d",&n);
    class = (s_details *)malloc(sizeof(s_details) * n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the roll of the student : "); scanf("%lu%c",&(class[i].roll), &dump);
        printf("Enter the name of the student : "); fgets(class[i].name, sizeof(class[i].name), stdin);
        printf("Enter the stream of the student : ");   fgets(class[i].stream, sizeof(class[i].stream), stdin);
    }
    for(int i = 0; i  < n ;i++)
    {
        printf("%lu\t%s\t%s\n",class[i].roll, class[i].name, class[i].stream);
    }
    return 0;
}