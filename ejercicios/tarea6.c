#include<stdio.h>

int main(){

    float dolares, euros, tasa_cambio;

    printf("Ingrese el monto que desea convertir (en dolares): \n");
    scanf("%f", &dolares);

    tasa_cambio = 1.06;
    euros = dolares/tasa_cambio;
    printf("El equivalente de %.2f dolares en euros es de %.4f euros\n", dolares, euros);

    return 0;
}