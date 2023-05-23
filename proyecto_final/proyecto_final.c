#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOMBRE 50
#define TAM_MAX_FECHA 11

struct Trabajador {
    int cedula;
    char nombre[TAM_MAX_NOMBRE];
    int departamento;
    int cargo;
    float sueldo;
    char fecha_ingreso[TAM_MAX_FECHA];
};

void modulo_1(int num_registros) {
    FILE *archivo;
    struct Trabajador trabajador;
    int i;

    archivo = fopen("trabajadores.in", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo!\n");
        return;
    }

    for (i = 0; i < num_registros; i++) {
        printf("Ingrese la cedula de identidad del trabajador: ");
        scanf("%d", &trabajador.cedula);

        printf("Ingrese el nombre del trabajador: ");
        scanf("%s", trabajador.nombre);

        printf("Ingrese el departamento del trabajador (1: RRHH, 2: Consultoria, 3: Diseno, 4: Produccion, 5: Calidad, 6: Distribucion): ");
        scanf("%d", &trabajador.departamento);

        printf("Ingrese el cargo del trabajador (1: Gerente, 2: Supervisor, 3: Analista, 4: Diseñador, 5: Desarrollador, 6: Auditor): ");
        scanf("%d", &trabajador.cargo);

        printf("Ingrese el sueldo del trabajador: ");
        scanf("%f", &trabajador.sueldo);

        printf("Ingrese la fecha de ingreso del trabajador en formato dd/mm/aa (separados por las barras): ");
        scanf("%s", trabajador.fecha_ingreso);

        fprintf(archivo, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
    }

    fclose(archivo);
    printf("Datos registrados con exito!\n");
}

void modulo_2(int opcion){
    FILE *file;
    struct Trabajador trabajador;
    int encontrado = 0, cedula, depart, role, sort;
    float sueldo_max = 0, sueldo_min = 1000000000000000000;
    char nombre_max[50], nombre_min[50];

    switch(opcion) {
        case 1: 
            printf("Ingrese la Cédula de Identidad por la que desea consultar: ");
            scanf("%d", &cedula);


            file = fopen("trabajadores.in", "r");
            if (file == NULL) {
                printf("No se pudo abrir el archivo origen.\n");
                exit(1);
            }

            while (fscanf(file, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
                if (trabajador.cedula == cedula) {
                    encontrado = 1;
                    printf("CI: %d\n", trabajador.cedula);
                    printf("Nombre: %s\n", trabajador.nombre);
                    printf("Departamento: %d\n", trabajador.departamento);
                    printf("Cargo: %d\n", trabajador.cargo);
                    printf("Sueldo: %.2f\n", trabajador.sueldo);
                    printf("Sueldo: %s\n", trabajador.fecha_ingreso);
                    break;
                }
            }

            if (!encontrado) {
                printf("La CI indicada no está asociada a ningún trabajador de la empresa.\n");
            }

            fclose(file);

            break;

        case 2:
            printf("Ingrese el numero del departamento por el que desea consultar: ");
            scanf("%d", &depart);

            file = fopen("trabajadores.in", "r");
            if (file == NULL) {
                printf("No se pudo abrir el archivo origen.\n");
                exit(1);
            }

            while (fscanf(file, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
                if (trabajador.departamento == depart) {
                    encontrado = 1;
                    printf("CI: %d\n", trabajador.cedula);
                    printf("Nombre: %s\n", trabajador.nombre);
                    printf("Departamento: %d\n", trabajador.departamento);
                    printf("Cargo: %d\n", trabajador.cargo);
                    printf("Sueldo: %.2f\n", trabajador.sueldo);
                    printf("Sueldo: %s\n", trabajador.fecha_ingreso);
                    break;
                }
            }

            if (!encontrado) {
                printf("La departamento indicado no pertenece a esta empresa.\n");
            }

            fclose(file);

            break;

        case 3:
            printf("Ingrese el numero del cargo por el que desea consultar: ");
            scanf("%d", &role);

            file = fopen("trabajadores.in", "r");
            if (file == NULL) {
                printf("No se pudo abrir el archivo origen.\n");
                exit(1);
            }

            while (fscanf(file, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
                if (trabajador.cargo == role) {
                    encontrado = 1;
                    printf("CI: %d\n", trabajador.cedula);
                    printf("Nombre: %s\n", trabajador.nombre);
                    printf("Departamento: %d\n", trabajador.departamento);
                    printf("Cargo: %d\n", trabajador.cargo);
                    printf("Sueldo: %.2f\n", trabajador.sueldo);
                    printf("Sueldo: %s\n", trabajador.fecha_ingreso);
                    break;
                }
            }

            if (!encontrado) {
                printf("El cargo indicado no está asociado a ningún trabajador de la empresa.\n");
            }

            fclose(file);

            break;

         case 4:
             file = fopen("trabajadores.in", "r");
            if (file == NULL) {
                printf("No se pudo abrir el archivo origen.\n");
                exit(1);
            }
            
            while (fscanf(file, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6){
               
               
               if(sueldo_max <= trabajador.sueldo){
                    sueldo_max = trabajador.sueldo;
                    strcpy(nombre_max,trabajador.nombre);

               } 

               if(trabajador.sueldo < sueldo_min){
                sueldo_min = trabajador.sueldo;
                strcpy(nombre_min,trabajador.nombre);
               }   

            }


               
        printf("El sueldo maximo es: %f y le pertenece a: %s \n", sueldo_max,nombre_max);
        
        printf("El sueldo minimo es: %f y le pertenece a: %s", sueldo_min,nombre_min);

            break;

        default:
            printf("Opción inválida\n");
    }
}
/* Modulo 3*/

void modulo_3_nombre(int cedula, char* nuevo_nombre) {
    FILE *archivo_origen, *archivo_destino;
    struct Trabajador trabajador;
    int encontrado = 0;

    archivo_origen = fopen("trabajadores.in", "r");
    if (archivo_origen == NULL) {
        printf("No se pudo abrir el archivo origen.\n");
        exit(1);
    }

    archivo_destino = fopen("trabajadores2.in","w");
    if (archivo_destino == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    while (fscanf(archivo_origen, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
        if (trabajador.cedula == cedula) {
            if (nuevo_nombre != NULL) {
                strcpy(trabajador.nombre, nuevo_nombre);
            }
            encontrado = 1;
        }
        fprintf(archivo_destino, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
    }

    if (!encontrado) {
        printf("No se encontró ningún trabajador con la cédula indicada.\n");
    }

    fclose(archivo_origen);
    fclose(archivo_destino);
    remove("trabajadores.in");
    rename("trabajadores2.in", "trabajadores.in");
}


void modulo_3_departamento(int cedula, int nuevo_departamento) {
    FILE *archivo_origen, *archivo_destino;
    struct Trabajador trabajador;
    int encontrado = 0;

    archivo_origen = fopen("trabajadores.in", "r");
    if (archivo_origen == NULL) {
        printf("No se pudo abrir el archivo origen.\n");
        exit(1);
    }

    archivo_destino = fopen("trabajadores2.in","w");
    if (archivo_destino == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    while (fscanf(archivo_origen, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
        if (trabajador.cedula == cedula) {
            if (nuevo_departamento != -1) {
                trabajador.departamento = nuevo_departamento;
            }
            encontrado = 1;
        }
        fprintf(archivo_destino, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
    }

    if (!encontrado) {
        printf("No se encontró ningún trabajador con la cédula indicada.\n");
    }

    fclose(archivo_origen);
    fclose(archivo_destino);
    remove("trabajadores.in");
    rename("trabajadores2.in", "trabajadores.in");
}

void modulo_3_cargo(int cedula, int nuevo_cargo) {
    FILE *archivo_origen, *archivo_destino;
    struct Trabajador trabajador;
    int encontrado = 0;

    archivo_origen = fopen("trabajadores.in", "r");
    if (archivo_origen == NULL) {
        printf("No se pudo abrir el archivo origen.\n");
        exit(1);
    }

    archivo_destino = fopen("trabajadores2.in","w");
    if (archivo_destino == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    while (fscanf(archivo_origen, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
        if (trabajador.cedula == cedula) {
            if (nuevo_cargo != -1) {
                trabajador.cargo = nuevo_cargo;
            }
            encontrado = 1;
        }
        fprintf(archivo_destino, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
    }

    if (!encontrado) {
        printf("No se encontró ningún trabajador con la cédula indicada.\n");
    }

    fclose(archivo_origen);
    fclose(archivo_destino);
    remove("trabajadores.in");
    rename("trabajadores2.in", "trabajadores.in");
}

void modulo_3_sueldo(int cedula, float nuevo_sueldo) {
    FILE *archivo_origen, *archivo_destino;
    struct Trabajador trabajador;
    int encontrado = 0;

    archivo_origen = fopen("trabajadores.in", "r");
    if (archivo_origen == NULL) {
        printf("No se pudo abrir el archivo origen.\n");
        exit(1);
    }

    archivo_destino = fopen("trabajadores2.in","w");
    if (archivo_destino == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    while (fscanf(archivo_origen, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
        if (trabajador.cedula == cedula) {
            if (nuevo_sueldo != -1) {
                trabajador.sueldo = nuevo_sueldo;
            }
            encontrado = 1;
        }
        fprintf(archivo_destino, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
    }

    if (!encontrado) {
        printf("No se encontró ningún trabajador con la cédula indicada.\n");
    }

    fclose(archivo_origen);
    fclose(archivo_destino);
    remove("trabajadores.in");
    rename("trabajadores2.in", "trabajadores.in");
}

void modulo_3_fecha(int cedula, char* nueva_fecha_ingreso) {
    FILE *archivo_origen, *archivo_destino;
    struct Trabajador trabajador;
    int encontrado = 0;

    archivo_origen = fopen("trabajadores.in", "r");
    if (archivo_origen == NULL) {
        printf("No se pudo abrir el archivo origen.\n");
        exit(1);
    }

    archivo_destino = fopen("trabajadores2.in","w");
    if (archivo_destino == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    while (fscanf(archivo_origen, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
        if (trabajador.cedula == cedula) {
            if (nueva_fecha_ingreso != NULL) {
                strcpy(trabajador.fecha_ingreso, nueva_fecha_ingreso);
            }
            encontrado = 1;
        }
        fprintf(archivo_destino, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
    }

    if (!encontrado) {
        printf("No se encontró ningún trabajador con la cédula indicada.\n");
    }

    fclose(archivo_origen);
    fclose(archivo_destino);
    remove("trabajadores.in");
    rename("trabajadores2.in", "trabajadores.in");
}

/*Modulo 4*/

void modulo_4(int cedula, int motivo, char *nueva_fecha){
    FILE *archivo_origen, *archivo_destino, *archivo_extrabajadores;
    struct Trabajador trabajador;
    int encontrado = 0, desicion;

    archivo_origen = fopen("trabajadores.in", "r");
    if (archivo_origen == NULL) {
        printf("No se pudo abrir el archivo origen.\n");
        exit(1);
    }

    archivo_destino = fopen("trabajadores2.in","w");
    if (archivo_destino == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    archivo_extrabajadores = fopen("extrabajadores.txt","w");
    if (archivo_extrabajadores == NULL) {
        printf("No se pudo crear el archivo destino.\n");
        exit(1);
    }

    while (fscanf(archivo_origen, "%d %s %d %d %f %s", &trabajador.cedula, trabajador.nombre, &trabajador.departamento, &trabajador.cargo, &trabajador.sueldo, trabajador.fecha_ingreso) == 6) {
        if (trabajador.cedula != cedula) {
            fprintf(archivo_destino, "%d %s %d %d %.2f %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso);
        }else{
            fprintf(archivo_extrabajadores, "%d %s %d %d %.2f %s %d %s\n", trabajador.cedula, trabajador.nombre, trabajador.departamento, trabajador.cargo, trabajador.sueldo, trabajador.fecha_ingreso, motivo, nueva_fecha);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún trabajador con la cédula indicada.\n");
    }

    fclose(archivo_origen);
    fclose(archivo_destino);
    fclose(archivo_extrabajadores);
    remove("trabajadores.in");
    rename("trabajadores2.in", "trabajadores.in");
}

int main() {

    int num_registros, n, nuevo_departamento, nuevo_cargo, opcion_inicio, opcion_modi, motivo, opcion_modulo_2 = 0, nueva_cedula,opcion_modulo_3 = 0, des;
    float nuevo_sueldo;
    char exit;
    char *nuevo_nombre, *nueva_fecha_ingreso, *nueva_fecha;

    do
    {
        printf( "\n   1.- Ingresar Empleado");
        printf( "\n   2.- Consultar");
        printf( "\n   3.- Modificar");
        printf( "\n   4.- Eliminar");
        printf( "\n   5.- Salir");

        printf( "\n\n   Introduzca opcion (1-5): ");
        scanf( "%d", &opcion_inicio);

        switch (opcion_inicio) {
            case 1: 
            printf("Ingrese el numero de nuevos trabajadores a registrar:");
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
            printf("Ingrese la cedula del trabajador a modificar:");
            scanf("%d",&nueva_cedula);
            printf("Ingrese la opcion por la que desea modificar:");
            printf("\n  1.- Modificar el nombre. / 2.- Modificar el Departamento. / 3.- Modificar el cargo. / 4.- Modificar el sueldo. / 5.- Modificar la fecha de ingreso. \n");
            scanf("%d", &opcion_modi);

            switch(opcion_modi) {
                case 1:
                printf("Ingrese el nombre del trabajador a modificar:");
                scanf("%s", nuevo_nombre);
                modulo_3_nombre(nueva_cedula, nuevo_nombre);
                break;

                case 2:
                printf("Ingrese el departamento del trabajador a modificar:");
                scanf("%d",&nuevo_departamento);
                modulo_3_departamento(nueva_cedula, nuevo_departamento);
                break;

                case 3:
                printf("Ingrese el cargo del trabajador a modificar:");
                scanf("%d",&nuevo_cargo);
                modulo_3_cargo(nueva_cedula, nuevo_cargo);
                break;

                case 4:
                printf("Ingrese el sueldo del trabajador a modificar:");
                scanf("%f",&nuevo_sueldo);
                modulo_3_sueldo(nueva_cedula, nuevo_sueldo);
                break;

                case 5:
                printf("Ingrese el nombre del trabajador a modificar:");
                scanf("%s", nueva_fecha_ingreso);
                modulo_3_fecha(nueva_cedula, nueva_fecha_ingreso);
                break;

            }
            break;

            case 4:
            printf("Escriba la cedula de la persona a elminar:");
            scanf("%d", &nueva_cedula);
            printf("Escriba el motivo marque 1.- Traslado / 2.Renuncia / 3.- Despido / 4.- Otro :");
            scanf("%d", &motivo);
            printf("Escriba la fecha:");
            scanf("%s", nueva_fecha);
            modulo_4(nueva_cedula, motivo, nueva_fecha);
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