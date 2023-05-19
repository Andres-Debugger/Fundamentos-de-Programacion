#include<stdio.h>

int main()
{

    float nota1, nota2, nota3, promedio_notas;
    printf("Ingrese la nota del 1er examen (maximo 4 decimales): ");
    scanf("%.4f",&nota1);
    printf("Ingrese la nota del 2do examen: ");
    scanf("%.4f",&nota2);
    printf("Ingrese la nota del 3er examen: ");
    scanf("%.4f",&nota3);
  
    promedio_notas = (nota1 + nota2 + nota3)/3;
    printf("El promedio de las notas es: %f \n", promedio_notas);
}