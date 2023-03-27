#include <stdio.h>

int main()
{
    int cant_paciente=0, i=0, edad=0, dia=0, mes=0, año=0, cedula=0, total_mujer=0, total_hombre=0, 
    total_menores=0, total_mayores=0, dia_actual=1, mes_actual=1, año_actual=0, total_descuent_mujer=0, total_descuent_hombre=0, edad_mal=0;
    char sexo;
    
    printf("¿ Cuantos pacientes desea ingresar ?\n");
    scanf("%d", &cant_paciente);
    while(cant_paciente <=0){
        printf ("\nDato no valido, ingrese nuevamente:\n");
        scanf("%d", &cant_paciente);
    }
    
    printf("¿ Que dia es hoy ?\n");
    scanf("%d", &dia_actual);
    while((dia_actual > 31)||(dia_actual <= 0)){
        printf ("\nDato no valido, ingrese nuevamente:\n");
        scanf("%d", &dia_actual);
    }
    
    printf("¿ En que mes estamos ?\n");
    scanf("%d", &mes_actual);
    while((mes_actual > 12)||(mes_actual <= 0)){
        printf ("\nDato no valido, ingrese nuevamente:\n");
        scanf("%d", &mes_actual);
    }
    
    printf("¿ En que año estamos ?\n");
    scanf("%d", &año_actual);
    while(año_actual <= 0){
        printf ("\nDato no valido, ingrese nuevamente:\n");
        scanf("%d", &año_actual);
    }

    
    for(i=1; i<=cant_paciente; i++){
        
        printf("¿ Cual es su sexo (h para hombre y m para mujeres) ?\n");
        scanf(" %c", &sexo);
        while((sexo != 'm')&&(sexo != 'h')){
            printf ("\nDato no valido, ingrese nuevamente:\n");
            scanf(" %c", &sexo);
        }
        
        if(sexo == 'm'){
           total_mujer = total_mujer + 1; 
        }else if(sexo == 'h'){
            total_hombre = total_hombre + 1;
        }
        
        printf("¿ Cual es su cedula ?\n");
        scanf("%d", &cedula);
        while(cedula <= 0){
            printf ("\nDato no valido, ingrese nuevamente:\n");
            scanf("%d", &cedula);
        }
        
        printf("¿ Cual es su edad ?\n");
        scanf("%d", &edad);
        while(edad < 0){
            printf ("\nDato no valido, ingrese nuevamente\n");
            scanf("%d", &edad);
        }
        
        if(edad < 18){
            total_menores = total_menores + 1;
        }else{
            total_mayores = total_mayores + 1;
        }
        
        printf("¿ Cual es su dia de naciemiento ?\n");
        scanf("%d", &dia);
        while((dia > 31)||(dia <= 0)){
            printf ("\nDato no valido, ingrese nuevamente:\n");
            scanf("%d", &dia);
        }
        
        printf("¿ Cual es su mes de naciemiento ?\n");
        scanf("%d", &mes);
        while((mes > 12)||(mes <= 0)){
            printf ("\nDato no valido, ingrese nuevamente:\n");
            scanf("%d", &mes);
        }
        
        printf("¿ Cual es su año de naciemiento ?\n");
        scanf("%d", &año);
        while(año <= 0){
            printf ("\nDato no valido, ingrese nuevamente:\n");
            scanf("%d", &año);
        }
        
        if((año_actual-año) != edad){
            edad_mal = 1;
        }else if((dia_actual-dia) < 0){
            edad_mal = 1;
        }else if((mes_actual-mes) < 0){
            edad_mal = 1; 
        }
        
        if(edad_mal = 1){
            printf ("\nSu fecha de naciemiento no coincide con su edad, por favor reinicie el programa e introduzca el dato correcto.\n");
            return 0;
        }
        
        if((((cedula%10)%2) == 0)&&(sexo = 'm')){
            total_descuent_mujer = total_descuent_mujer + 1;
        }else if(edad > 60){
            total_descuent_hombre = total_descuent_hombre + 1;
        }
        
        if((((cedula%10)%2) == 0)&&(sexo = 'm')){
            total_descuent_mujer = total_descuent_mujer + 1;
        }else if(edad > 60){
            total_descuent_hombre = total_descuent_hombre + 1;
        }
    }
    
    printf("\nHay %d pacientes femeninos.", total_mujer);
    printf("\nHay %d pacientes masculinos.", total_hombre);
    printf("\nHay %d pacientes mayores de edad.", total_mayores);
    printf("\nHay %d pacientes menores de edad.", total_menores);
    printf("\nHay %d pacientes femeninos que tienen un descuento del 15 porciento.", total_descuent_mujer);
    printf("\nHay %d pacientes masculinos que tienen un descuento del 3 porciento.", total_descuent_hombre);
    
    return 0;
}
