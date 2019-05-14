#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionesGet.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("            A B M                  \n\n");
    printf(" 1. ALTAS  \n 2. LISTAR \n 3. MODIFICAR PELICULA\n 4. Salir\n");
    scanf("%d", &opcion);

    return opcion;

}
int pedirOpcionModificacionPelicula()
{
    int opcionAmodificar;
    printf("%s","             MODIFICACION            \n");
    printf("%10s - %10s - %10s \n", "1.Titulo", "2.Anio de estreno", "3.Actor");
    opcionAmodificar = getInt("Que desea modificar?");

    return opcionAmodificar;
}

int getOptionShow()
{
    int optionShow;
    printf("%s","                   INFORMES                 \n");
    printf("%s %s \n", " 1. Empleados ordenados alfabeticamente por Apellido y Sector\n", "2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio");
    scanf("%d", &optionShow);

    return optionShow;
}
