#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaEstructura.h"

// 1 = libre ; 0 = ocupado

int inicializarPropietarios(ePropietario listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}

int altaPropietarios(ePropietario listado[], int len, int id, char nombre[],char apellido[], int tarjeta)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].estado == 1)
        {
            listado[i].id = id;
            strcpy(listado[i].nombre, nombre);
            strcpy(listado[i].apellido, apellido);
            listado[i].tarjeta= tarjeta;
            listado[i].estado = 0;
            return 0;
        }
    }
    return -1;
}

int mostrarListadoPropietarios(ePropietario listado[], int len)
{
    int i;
    printf("%10s - %10s - %10s - %10s \n", "ID", "Nombre", "Apellido", "tarjeta");
    ordenarPropietarios(listado, len, 1);

    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%10d  %10s  %10s %10d \n", listado[i].id, listado[i].nombre, listado[i].apellido, listado[i].tarjeta);

        }

    }
    return 0;
}

int buscarPropietarioPorID(ePropietario listado[], int len,int id)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].id == id)
        {
            return i;
        }
    }

    return -1;

}

int bajaPropietario(ePropietario listado[], int len, int id)
{

    int idAborrar = buscarPropietarioPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}

int modificacionPropietario(ePropietario listado[], int len, int id, char nombre[],char apellido[], int tarjeta, int option)
{
    int posAeditar = buscarPropietarioPorID(listado, len, id);
    if(posAeditar == -1)
    {
        return -1;
    }
    switch(option)
    {
    case 1:
        printf(" nuevo nombre \n");
        scanf("%s", nombre);
        fflush(stdin);
        strcpy(listado[posAeditar].nombre, nombre);
        listado[posAeditar].estado = 0;
        break;
    case 2:
        printf(" nuevo apellido \n");
        scanf("%s", apellido);
        fflush(stdin);
        strcpy(listado[posAeditar].apellido, apellido);
        listado[posAeditar].estado = 0;
        break;
    case 3:
        printf(" nuevo tarjeta \n");
        scanf("%d", &tarjeta);
        fflush(stdin);
        listado[posAeditar].tarjeta = tarjeta;
        listado[posAeditar].estado = 0;
        break;
    }


    return 0;

}

int harcodePropietario(ePropietario listado[], int len)
{
    int i;

    int id[4]= {1, 2, 3, 4};
    char nombre[4][50]= {"Fernado", "Juan", "Pablo", "Roberto"};
    char apellido[4][13]= {"Andes", "Caceres", "Rojas", "Echeverria"};
    int tarjeta[4]= { 1111, 2222, 3333, 4444};
    int estado[4]= { 0, 0, 0, 0};

    for(i=0; i<4; i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].apellido,apellido[i]);
        listado[i].tarjeta = tarjeta[i];
        listado[i].estado = estado[i];

    }
    return -1;
}

int ordenarPropietarios(ePropietario listado[], int len, int order)
{
    int i;
    int j;
    ePropietario aux;


    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(listado[i].tarjeta > listado[j].tarjeta)
            {
                aux =listado[i];
                listado[i] = listado[j];
                listado[j] = aux;


            }
        }
    }

    return 0;
}
int buscarLibrePropietarios(ePropietario listado[], int len)
{
    int i;
    int id;

    for(i=0; i<len; i++)
    {
        if(listado[i].estado ==1)
        {
            id = i+1;
            break;
        }
    }
    return id;
}
