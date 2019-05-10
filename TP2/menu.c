#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionesGet.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("                     A B M      EMPLEADOS              \n\n");
    printf(" 1. ALTAS  \n 2. MODIFICAR  \n 3. BAJA\n 4. INFORMAR\n 5. Salir\n");
    opcion = getInt("\nIngrese una opcion\n");
    return opcion;
}
int getOptionModify()
{
    int optionModify;
    printf("             MODIFICACION                \n");
    printf(" 1.NOMBRE\n 2.APELLIDO\n 3.SALARIO\n 4.SECTOR\n");
    optionModify = getInt("\nIngrese una opcion\n");
    return optionModify;
}

int getOptionShow()
{
    int optionShow;
    printf("                   INFORMES                 \n");
    printf("%s %s \n", " 1. Empleados ordenados alfabeticamente por Apellido y Sector\n", "2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio");
    optionShow = getInt("\nIngrese una opcion\n");
    return optionShow;
}
