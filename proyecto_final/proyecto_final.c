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