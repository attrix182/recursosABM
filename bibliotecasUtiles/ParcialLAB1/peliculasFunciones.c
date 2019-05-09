#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculasFunciones.h"
#include "actoresFunciones.h"
//1 libre; 0 ocupado
int inicializarPeliculas(ePelicula listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}

int altaPeliculas(ePelicula listado[], int len, int id, int codigoPelicula, char titulo[],char fechaDeEstreno[], char genero[], int idActor)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].estado == 1)
        {
            listado[i].id = id;
            listado[i].codigoPelicula= codigoPelicula;
            strcpy(listado[i].titulo, titulo);
            strcpy(listado[i].fechaDeEstreno, fechaDeEstreno);
            strcpy(listado[i].genero, genero);
            listado[i].idActor= idActor;
            listado[i].estado = 0;
            return 0;
        }
    }
    return -1;
}

int mostrarListadoPeliculas(ePelicula listado[], int len)
{
    int i;
    printf("%10s - %10s - %8s - %10s - %10s \n", "ID", "codigoPelicula", "titulo", "fechaDeEstreno", "genero");


    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%10d  %10d  %12s %16s %15s \n", listado[i].id, listado[i].codigoPelicula, listado[i].titulo, listado[i].fechaDeEstreno, listado[i].genero);

        }


    }
    return 0;
}

int buscarPeliPorID(ePelicula listado[], int len,int id)
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

int bajaPelicula(ePelicula listado[], int len, int id)
{

    int idAborrar = buscarPeliPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}



int harcodePeliculas(ePelicula listado[], int len)
{
    int i;

    int id[5]= {1, 2, 3, 4, 5};
    int codigoPelicula[5]= {111, 222, 333, 444, 555};
    char titulo[5][51]= {"Avengers", "Up", "Iron Man", "Batman", "Silencio"};
    char fechaDeEstreno[5][20]= { "20/08/2001", "10/08/2001", "15/08/2001", "21/08/2001", "15/08/2001"};
    char genero[5][21]= { "Accion", "Comedia", "Accion", "Accion", "Terror"};
    int idActor[5] = {1, 2, 3, 3, 4};
    //  int estado[4]= {0, 0, 0, 0};

    for(i=0; i<5; i++)
    {

            listado[i].id = id[i];
            listado[i].codigoPelicula= codigoPelicula[i];
            strcpy(listado[i].titulo, titulo[i]);
            strcpy(listado[i].fechaDeEstreno, fechaDeEstreno[i]);
            strcpy(listado[i].genero, genero[i]);
            listado[i].idActor= idActor[i];
            listado[i].estado = 0;


    }
    return -1;
}


int buscarLibrePelicula(ePelicula listado[], int len)
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

int mostrarPeliculasConActores(ePelicula listadoPeliculas[], eActor listadoActores[], int len)
{
    int i;
    int posActor;
    printf("%10s - %10s - %8s - %10s - %10s - %10s \n", "ID", "codigoPelicula", "titulo", "fechaDeEstreno", "genero", " Actor ");


    for(i = 0; i < len; i++)
    {
        if(listadoPeliculas[i].estado == 0)
        {

            posActor = buscarActorPorID(listadoActores, len, listadoPeliculas[i].idActor);


            printf("%10d %10d %13s %15s %15s %20s  \n", listadoPeliculas[i].id, listadoPeliculas[i].codigoPelicula, listadoPeliculas[i].titulo, listadoPeliculas[i].fechaDeEstreno, listadoPeliculas[i].genero, listadoActores[posActor].nombreActor);

        }

    }


    return 0;
}

