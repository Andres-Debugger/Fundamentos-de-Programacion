#include <stdio.h>

int main()
{
    int primer_valor, segundo_valor;
    printf("Ingrese el primer valor: ");
    scanf("%d", &primer_valor);
    printf("Ingrese el segundo valor: ");
    scanf("%d", &segundo_valor);

    primer_valor = primer_valor + segundo_valor;
    segundo_valor = primer_valor - segundo_valor;
    primer_valor = primer_valor - segundo_valor;

    printf("El primer valor ahora es: %d \nY el segundo valor ahora es: %d\n", primer_valor, segundo_valor);
}