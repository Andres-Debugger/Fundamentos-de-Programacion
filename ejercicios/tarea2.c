#include<stdio.h>

int main(){

    float arista, arista_al_cubo;
    printf("Ingrese el valor de la aristata: \n ");
    scanf("%g", &arista);

    arista_al_cubo = (arista*arista*arista);

    printf("El volumen del cubo es de: %.4f\n", arista_al_cubo);

    return 0;
}