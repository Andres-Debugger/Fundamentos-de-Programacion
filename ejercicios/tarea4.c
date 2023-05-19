#include <stdio.h>

int main()
{
    int hora, minutos, segundos, total;

    printf("Ingrese la hora: ");
    scanf("%d", &hora);
    printf("Ingrese los minutos:");
    scanf("%d", &minutos);
    printf("Ingrese los segundos: ");
    scanf("%d", &segundos);

    total = hora*3600 + minutos*60 + segundos;

    printf("La cantidad de segundosundos que han pasado desde las 00:00:00 hasta las %d:%d:%d es %d segundosundos\n", hora,minutos,segundos,total);

}