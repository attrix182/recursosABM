#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "peliculasFunciones.h"
#include "actoresFunciones.h"
#include "funcionesGet.h"
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

int altaPeliculas(ePelicula listado[], int len, int id, int codigoPelicula, char titulo[],int fechaDeEstreno, char genero[], int idActor)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].estado == 1)
        {
            listado[i].id = id;
            listado[i].codigoPelicula= codigoPelicula;
            strcpy(listado[i].titulo, titulo);
            listado[i].fechaDeEstreno= fechaDeEstreno;
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
            printf("%10d  %10d  %12s %16d %15s \n", listado[i].id, listado[i].codigoPelicula, listado[i].titulo, listado[i].fechaDeEstreno, listado[i].genero);

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

    int id[5]= {1000, 1002, 1003, 1004, 1005};
    int codigoPelicula[5]= {111, 222, 333, 444, 555};
    char titulo[5][51]= {"Avengers", "Up", "Iron Man", "Batman", "Silencio"};
    int fechaDeEstreno[5]= { 2001, 2002, 2003, 2004, 2005};
    char genero[5][21]= { "Accion", "Comedia", "Accion", "Accion", "Terror"};
    int idActor[5] = {1, 2, 3, 3, 4};
    //  int estado[4]= {0, 0, 0, 0};

    for(i=0; i<5; i++)
    {

        listado[i].id = id[i];
        listado[i].codigoPelicula= codigoPelicula[i];
        strcpy(listado[i].titulo, titulo[i]);
        listado[i].fechaDeEstreno= fechaDeEstreno[i];
        strcpy(listado[i].genero, genero[i]);
        listado[i].idActor = idActor[i];
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
            id = i+1001;
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


            printf("%10d %10d %13s %15d %15s %20s  \n", listadoPeliculas[i].id, listadoPeliculas[i].codigoPelicula, listadoPeliculas[i].titulo, listadoPeliculas[i].fechaDeEstreno, listadoPeliculas[i].genero, listadoActores[posActor].nombreActor);

        }

    }


    return 0;
}

int modificacionPelicula(ePelicula listadoPeliculas[], eActor listadoActores[], int len, int id, char titulo[],int idActor, int fechaDeEstreno, int option)
{
    int posAeditar = buscarPeliPorID(listadoPeliculas, len, id);
    int idExiste;
    if(posAeditar == -1)
    {
        return -1;
    }
    switch(option)
    {
    case 1:
        getString(" Ingrese nuevo titulo \n", titulo);
        strcpy(listadoPeliculas[posAeditar].titulo, titulo);
        break;
    case 2:
        fechaDeEstreno = getInt("Ingrese Nueva Fecha de estreno \n");
        listadoPeliculas[posAeditar].fechaDeEstreno = fechaDeEstreno;
        break;
    case 3:
        idActor = getInt("id de actor principal");
        idExiste = buscarActorPorID(listadoActores, len, idActor);
        while(idExiste == -1)
        {
            idActor = getInt("Reingrese una ID de Actor valida");
            idExiste = buscarActorPorID(listadoActores, len, idActor);;
        }
        listadoPeliculas[posAeditar].idActor = idActor;
        break;
    }
    return 0;
}

