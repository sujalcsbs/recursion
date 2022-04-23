#include<stdio.h>

typedef struct{
    double real;
    double imaginary;
}compl;

compl *add(compl *, compl *);

int main()
{
    compl a, b, *ans;
    printf("Enter the real part of the first complex number: ");    scanf("%lf",&a.real);
    printf("Enter the imaginary part of the first complex number: ");   scanf("%lf",&a.imaginary);

    printf("Enter the real part of the second complex number: ");    scanf("%lf",&b.real);
    printf("Enter the imaginary part of the second complex number: ");   scanf("%lf",&b.imaginary);

    ans = add(&a ,&b);

    printf("The result is: %lf + i(%lf)\n", ans->real, ans->imaginary);
    return 0;
    
}

compl *add(compl *a, compl *b)
{
    static compl ans;
    ans.real = a->real + b->real;
    ans.imaginary = a->imaginary + b->imaginary;
    return &ans;
}