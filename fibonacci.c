#include<stdio.h>

int fib(int n){
    if(n == 2 || n == 3){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
 
int main(int argc, char *argv[])
{
    int n;
    printf("Enter the nth fibonacci number you want: ");
    scanf("%d",&n);
    printf("The fibonacci number is: %d",fib(n));
    return 0;
}
