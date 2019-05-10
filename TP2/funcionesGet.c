#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funcionesGet.h"
#include "ArrayEmployees.h"

int getInt(char mensaje[])
{
    char auxiliarChar[10];
    int enteroADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    enteroADevolver = atoi(auxiliarChar);

    while(enteroADevolver == 0)
    {
        printf("%s", "Valor invalido. Ingrese un numero \n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        enteroADevolver = atoi(auxiliarChar);
    }

    return enteroADevolver;

}

float getFloat(char mensaje[])
{
    char auxiliarChar[10];
    float floatADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    floatADevolver = atof(auxiliarChar);

    while(floatADevolver == 0)
    {
        printf("%s", "Valor invalido. Ingrese un numero \n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        floatADevolver = atof(auxiliarChar);
    }


    return floatADevolver;

}


void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}





