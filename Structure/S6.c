#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    long unsigned int roll, phone;
    char name[30], stream[30];
}s_details;

int main()
{
    s_details *class, temp;
    int n, i;
    char buffer;

    printf("Enter the number of students: ");   scanf("%d",&n);

    class = (s_details *)malloc(sizeof(s_details) * n);
    for(i = 0; i < n ;i++)
    {
        printf("Enter the roll number of the student: ");   scanf("%lu%c",&temp.roll, &buffer);
        printf("Enter the name of the student: ");  fgets(temp.name, sizeof(temp.name), stdin);
        printf("Enter the stream of the student: ");    fgets(temp.stream, sizeof(temp.stream), stdin);
        printf("Enter the phone number of the student: ");  scanf("%lu",&temp.phone);
        class[i] = temp;
    }

    printf("Details of the stduents is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%lu\n%s%s%lu\n",class[i].roll, class[i].name, class[i].stream, class[i].phone);
    }
    return 0;
}