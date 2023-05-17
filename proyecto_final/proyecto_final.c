#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
int ci;
char nombre[50];
int departamento;
int cargo;
float sueldo;
char fecha_ingreso[20];
} Trabajador;   

Trabajador trabajador;


FILE *modulo_1(int num_registros) {
FILE *archivo;

int i;

archivo = fopen("trabajadores.in", "a");

for(i = 0; i < num_registros; i++){
    printf("Ingrese la cedula de identidad del trabajador: \n");
    scanf("%d", &trabajador.ci);
   
    fflush(stdin);
    printf("Ingrese el nombre:\n");
    gets( trabajador.nombre);

    printf("Ingrese el departamento del trabajador (1: RRHH, 2: Consultoria, 3: Diseno, 4: Produccion, 5: Calidad, 6: Distribucion): \n");
    scanf("%d", &trabajador.departamento);

    printf("Ingrese el cargo del trabajador (1: Gerente, 2: Supervisor, 3: Analista, 4: Diseñador, 5: Desarrollador, 6: Auditor): \n");
    scanf("%d", &trabajador.cargo);

    printf("Ingrese el sueldo del trabajador: \n");
    scanf("%f", &trabajador.sueldo);

    
    fflush(stdin);
    printf("Ingrese la fecha de ingreso del trabajador en formato dd/mm/aa, con las barras ");
    scanf("%s", trabajador.fecha_ingreso);
    

    fprintf(archivo, "%d %s %d %d %.2f %s\n", trabajador.ci, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
}


fclose(archivo);
printf("Datos registrados con exito! \n");

return archivo;

}

void modulo_2(int opcion){

    int found = 0, cedula, departamento, cargo, ci, role, depart, sort;
    char *nombre, *fecha_ingreso;
    float sueldo;
    FILE *file;

    switch(opcion) {
        case 1: 
            printf("Ingrese la Cédula de Identidad por la que desea consultar: ");
            scanf("%d", &cedula);

            file = fopen("trabajadores.in", "r");

            if (file == NULL) {
                printf("No se pudo abrir el archivo\n");
                exit(1);
            }

            while(!feof(file)) {
                fscanf(file, "%d,%s %d,%d,%f,%s,\n", &ci, nombre, &departamento, &cargo, &sueldo, fecha_ingreso);
                if (cedula == ci){
                    found = 1;
                    printf("CI: %d\n", ci);
                    printf("Nombre: %s\n", nombre);
                    printf("Departamento: %d\n", departamento);
                    printf("Cargo: %d\n", cargo);
                    printf("Sueldo: %f\n", sueldo);
                    printf("Fecha de Ingreso: %s\n", fecha_ingreso);
                    break;
                }
            }

            if(!found) {
                printf("La CI indicada no está asociada a ningún trabajador de la empresa.\n");
            }

            fclose(file);

            break;

        case 2:
            printf("Ingrese el numero del departamento por el que desea consultar: ");
            scanf("%d", &depart);

            file = fopen("trabajadores.in", "r");

            if (file == NULL) {
                printf("No se pudo abrir el archivo\n");
                exit(1);
            }

            while(!feof(file)) {
                fscanf(file, "%d,%s %d,%d,%f,%s,\n", &ci, nombre, &departamento, &cargo, &sueldo, fecha_ingreso);
                if (depart == departamento){
                    found = 1;
                    printf("CI: %d\n", ci);
                    printf("Nombre: %s\n", nombre);
                    printf("Departamento: %d\n", departamento);
                    printf("Cargo: %d\n", cargo);
                    printf("Sueldo: %f\n", sueldo);
                    printf("Fecha de Ingreso: %s\n", fecha_ingreso);
                    break;
                }
            }

            if(!found) {
                printf("El numero indicado no concuerda con ninguno de los departamentos de la empresa.\n");
            }

            fclose(file);

            break;

        case 3:
            printf("Ingrese el numero del cargo por el que desea consultar: ");
            scanf("%d", &cargo);

            file = fopen("trabajadores.in", "r");
if (file == NULL) {
                printf("No se pudo abrir el archivo\n");
                exit(1);
            }

            while(!feof(file)) {
                fscanf(file, "%d,%s %d,%d,%f,%s,\n", &ci, nombre, &departamento, &cargo, &sueldo, fecha_ingreso);
                if (cedula == ci){
                    found = 1;
                    printf("CI: %d\n", ci);
                    printf("Nombre: %s\n", nombre);
                    printf("Departamento: %d\n", departamento);
                    printf("Cargo: %d\n", cargo);
                    printf("Sueldo: %f\n", sueldo);
                    printf("Fecha de Ingreso: %s\n", fecha_ingreso);
                    break;
                }
            }

            if(!found) {
                printf("El numero indicado no concuerda con ninguno de los cargos de la empresa.\n");
            }

            fclose(file);

            break;

        case 4:
            printf("Ingrese 1 para ordenar los trabajadores de mayor a menor sueldo o 2 para ordenarlos de menor a mayor: ");
            scanf("%d", &sort);
            
            if(sort == 1){
                printf("qlq");
            } else if(sort == 2){
                printf("qlq2");
                
            } else {
                printf("\nEl numero indicado no concuerda con ninguno de las opciones.\n");
            }

            break;

        default:
            printf("Opción inválida\n");
    }
}
/* Modulo 3*/
void modulo_3(int ci_nueva){
FILE *archent;
int modificacion = 0,  cedula, departamento, cargo, ci, role, depart, sort;
    char *nombre, *fecha_ingreso;
    float sueldo;
    archent = fopen("trabajadores.in","r+");
  
   if (archent == NULL) {
                printf("No se pudo abrir el archivo\n");
                exit(1);
            }

    while(!feof(archent)) {
               
        fscanf(archent, "%d,%s %d,%d,%f,%s,\n", &ci, nombre, &departamento, &cargo, &sueldo, fecha_ingreso);
                if (ci_nueva == ci){           
        printf("que desea modificar?: 1.Nombre, 2.departamento, 3.cargo, 4. sueldo 5.fecha ingreso ");
       do{
        scanf("%d",modificacion);
        if(modificacion < 1 || modificacion > 5){
            printf("error escriba nuevamente");
        }
       }while(modificacion < 0 || modificacion > 5);

        if(modificacion == 1){
            fflush(stdin);
            printf("Ingrese el nuevo nombre:\n");
             gets( nombre);
            fprintf(archent,"%d,%s,%d,%d,%f,%s,\n", ci, nombre,departamento, cargo, sueldo, fecha_ingreso );
            }else{
                if(modificacion == 2){

            printf("Ingrese el nuevo departamento del trabajador (1: RRHH, 2: Consultoria, 3: Diseno, 4: Produccion, 5: Calidad, 6: Distribucion): \n");
             scanf("%d", &departamento);
             fprintf(archent,"%d,%s,%d,%d,%f,%s,\n", ci, nombre,departamento, cargo, sueldo, fecha_ingreso );

                }else{
                    if(modificacion == 3){
                    printf("Ingrese el nuevo cargo del trabajador (1: Gerente, 2: Supervisor, 3: Analista, 4: Diseñador, 5: Desarrollador, 6: Auditor): \n");
                    scanf("%d", &cargo);
                     fprintf(archent,"%d,%s,%d,%d,%f,%s,\n", ci, nombre,departamento, cargo, sueldo, fecha_ingreso );

                    }else{
                        if(modificacion == 4){
                             printf("Ingrese el nuevo sueldo del trabajador: \n");
                            scanf("%f", &sueldo);
                            fprintf(archent,"%d,%s,%d,%d,%f,%s,\n", ci, nombre,departamento, cargo, sueldo, fecha_ingreso );
                        }else{
                             fflush(stdin);
                            printf("Ingrese la nueva fecha de ingreso del trabajador en formato dd/mm/aa, con las barras ");
                            scanf("%s",&fecha_ingreso);
                        fprintf(archent,"%d,%s,%d,%d,%f,%s,\n", ci, nombre,departamento, cargo, sueldo, fecha_ingreso );
                        }
                    }
                }
            }

            
            
        }else{
            printf("no se ha encontrado la cedula");
            return;
        }
    }
}

/*Modulo 4*/

 void modulo_4(){
    
 }


int main() {

    int num_registros, n, opcion_inicio, opcion_modulo_2 = 0,nueva_cedula,opcion_modulo_3 = 0 ;
    char exit;

    do
    {
        printf( "\n   1.- Ingresar Empelado");
        printf( "\n   2.- Consultar");
        printf( "\n   3.- Modificar");
        printf( "\n   4.- Eliminar");
        printf( "\n   5.- Salir");

        printf( "\n\n   Introduzca opcion (1-5): ");
        scanf( "%d", &opcion_inicio);

        switch (opcion_inicio) {
            case 1: 
            printf("Ingrese el numero de nuevos trabajadores a registrar: ");
            scanf("%d", &num_registros);
            modulo_1(num_registros);

            break;

            case 2: 
            printf("Ingrese la opcion por la que desea consultar:");
            printf("\n 1.- Consulta por Cédula de Identidad. / 2.- Consulta por Departamento. / 3.- Consulta por cargo. / 4.- Consultar el trabajador con mayor y menor sueldo. \n");
            scanf("%d", &opcion_modulo_2);
            modulo_2(opcion_modulo_2);

            break;
            
            case 3:
            printf("ingrese la cedula del trabajador a modificar");
            scanf("%d",&nueva_cedula);
            modulo_3(nueva_cedula);
            break;

            case 4:
            break;

            case 5:
            exit = 's';
            break;

            default:
            printf("\n  Opción inválida, por favor intentelo nuevamnete. \n\n");
        }

    } while ((opcion_inicio != 4) && (exit != 's'));

    return 0;
}