#include<stdio.h>
#include<stdlib.h>

int bacteria(int days){
    if(days == 0){
        return 1;
    }
    return 2 * bacteria(days-1);
}
 
int main(int argc, char *argv[])
{
    printf("%d",bacteria(5));
    return 0;
}