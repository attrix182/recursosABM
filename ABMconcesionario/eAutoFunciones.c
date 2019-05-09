#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eAutoFunciones.h"

int inicializarAutos(eAuto listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}

int altaAuto(eAuto listado[], int len, int id, int idPropietario, char marca[],char modelo[], char patente[], int tiempoEstacionado)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].estado == 1)
        {
            listado[i].id = id;
            listado[i].idPropietario= idPropietario;
            strcpy(listado[i].marca, marca);
            strcpy(listado[i].modelo, modelo);
            strcpy(listado[i].patente, patente);
            listado[i].tiempoEstacionado= tiempoEstacionado;

            listado[i].estado = 0;
            return 0;
        }
    }
    return -1;
}

int mostrarListadoAutos(eAuto listado[], int len)
{
    int i;
    printf("%10s - %10s - %10s - %10s - %10s \n", "ID", "marca", "modelo", "patente", "tiempoEstacionado");


    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%10d  %10s  %10s %10s %10d \n", listado[i].id, listado[i].marca, listado[i].modelo, listado[i].patente, listado[i].tiempoEstacionado);

        }


    }
    return 0;
}

int buscarAutoPorID(eAuto listado[], int len,int id)
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

int bajaAuto(eAuto listado[], int len, int id)
{

    int idAborrar = buscarAutoPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}



int harcodeAutos(eAuto listado[], int len)
{
    int i;

    int id[5]= {1, 2, 3, 4, 5};
    char marca[5][51]= {"ford", "fiat", "chevrolet", "volkswagen", "nissan"};
    char modelo[5][51]= {"focus", "siena", "corsa", "gol", "versa"};
    char patente[5][10]= { "aa999aa", "bb999bb", "cc999cc", "dd999dd", "ee999ee"};
    int tiempoEstacionado[5]= { 50, 80, 30, 20, 90};
    int idPropietario[5] = {1, 2, 3, 3, 4};
    //  int estado[4]= {0, 0, 0, 0};

    for(i=0; i<5; i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].marca,marca[i]);
        strcpy(listado[i].modelo,modelo[i]);
        strcpy(listado[i].patente,patente[i]);
        listado[i].tiempoEstacionado = tiempoEstacionado[i];
        listado[i].idPropietario = idPropietario[i];
        listado[i].estado = 0;

    }
    return -1;
}


int buscarLibreAuto(eAuto listado[], int len)
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

int mostrarAutosConPropietario(eAuto listadoAutos[], ePropietario listadoProp[], int len)
{
    int i;
    int posPropietario;
    printf("%10s - %10s - %10s - %10s - %10s \n", "marca", "modelo", "patente", "apellido", "tarjeta");


    for(i = 0; i < len; i++)
    {
        if(listadoAutos[i].estado == 0)
        {

            posPropietario = buscarPropietarioPorID(listadoProp, len, listadoAutos[i].idPropietario);


            printf("%10s %10s %10s %10s %10d  \n", listadoAutos[i].marca, listadoAutos[i].modelo, listadoAutos[i].patente, listadoProp[posPropietario].apellido, listadoProp[posPropietario].tarjeta);

        }

    }


    return 0;
}
