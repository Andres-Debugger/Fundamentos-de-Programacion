#include <stdio.h>

int main(){

    int n = 0, j = 0, l = 0, tres_veces_valor = 0, factorial = 0, resultado_cubo = 0;
    float sumatoria=0, resultado=0;

    printf("Por favor ingrese un número entero:\n");
    scanf("%d",&n);

    for(j=2; j<=n; j++){

        factorial=1;

        for(l=1;l<=j;l++){
            factorial = factorial * l;
        }

        tres_veces_valor = factorial * (3*(j+1));

        resultado_cubo = ((j-1) * (j-1) * (j-1));

        sumatoria = sumatoria + (tres_veces_valor/resultado_cubo);
    }

    resultado = sumatoria*5;
    printf("El resultado es: %.2f\n", resultado);
}