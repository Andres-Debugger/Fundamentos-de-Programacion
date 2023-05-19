#include <stdio.h>

int main()
{
    int valor_a , valor_b, valor_c;

    printf("Ingrese el valor de a: ");
    scanf("%d",&valor_a);
    printf("Ingrese el valor de b: ");
    scanf("%d",&valor_b);
    printf("Ingrese el valor de c: ");
    scanf("%d",&valor_c);

    if(valor_a <= valor_c && valor_b <= valor_c)
    {
        printf("El mayor de los tres numeros es c: %d\n", valor_c);
    }
    else if(valor_a <= valor_b && valor_c <= valor_b)
    {
        printf("El mayor de los tres numeros es b: %d\n", valor_b);
    }
    else
    {
        printf("El mayor de los tres numeros es a: %d\n", valor_a);

    }
}