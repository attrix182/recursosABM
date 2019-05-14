#include <stdio.h>
#include <stdlib.h>
#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "menu.h"
#include "funcionesGet.h"
#define ATAM 5
#define TAM 1500

int main()
{
    eActor listadoActores[ATAM];
    ePelicula listadoPeliculas[TAM];

    inicializarActores(listadoActores, ATAM);
    harcodeActores(listadoActores, ATAM);

    inicializarPeliculas(listadoPeliculas, TAM);
    harcodePeliculas(listadoPeliculas, TAM);

    int opcion;
    int opcionMod;
    char seguir = 's';
    int id;
    int codigoPelicula;
    char titulo[51];
    int fechaDeEstreno;
    char genero[21];
    int idActor;
    int idExiste;

    do
    {
        opcion = pedirOpcionMenu();

        switch(opcion)
        {
        case 1:
            id = buscarLibrePelicula(listadoPeliculas, TAM);
            codigoPelicula = getInt("Ingrese codigo pelicula");

            getString(" Ingrese titulo \n", titulo);
            fechaDeEstreno = getInt("Ingrese Fecha de estreno \n");
            getString(" Ingrese genero \n", genero);
            idActor = getInt("id de actor principal");
            idExiste = buscarActorPorID(listadoActores, ATAM, idActor);
            while(idExiste == -1)
            {
                idActor = getInt("Reingrese una ID de Actor valida");
                idExiste = buscarActorPorID(listadoActores, ATAM, idActor);;
            }

            altaPeliculas(listadoPeliculas, TAM, id, codigoPelicula, titulo, fechaDeEstreno,genero, idActor);

            break;
        case 2:
            printf("   Listado de Peliculas SIN Actores  \n");
            mostrarListadoPeliculas(listadoPeliculas, TAM);
            printf("\n");
            printf("   Listado de Peliculas CON Actores  \n");
            mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
            break;
        case 3:

            id = getInt("Ingrese ID de Pelicula a modificar \n");
            idExiste = buscarPeliPorID(listadoPeliculas, TAM, id);
            while(idExiste == -1)
            {
                id = getInt("Reingrese una ID valida\n");
                idExiste = buscarPeliPorID(listadoPeliculas, TAM, id);

            }
            opcionMod = pedirOpcionModificacionPelicula();
            modificacionPelicula(listadoPeliculas, listadoActores, TAM, id, titulo, idActor, fechaDeEstreno, opcionMod);
            break;
        case 4:
            seguir = 'n';
            break;

        default:
            printf("opcion invlaida \n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}
