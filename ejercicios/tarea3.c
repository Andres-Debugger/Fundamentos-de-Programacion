#include<stdio.h>

int main()
{
    float euros, dolares, azucar=3.0, cafe=0.72;

    printf("Ingrese el monto (en euros): \n");
    scanf("%f", &euros);

    dolares = euros*1.06;
    printf("Con %.4f euros se puede comprar %.4f kilos de azucar \n", euros, ((dolares/2)/azucar));
    printf("Se puede comprar %.4f kilos en cafe \n", ((dolares/2)/3/cafe));
    printf("Su saldo restante es: %.4f \n", (dolares/2)-((dolares/2)/3));    
}