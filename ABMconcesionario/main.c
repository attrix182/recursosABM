#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaEstructura.h"
#include "eAutoFunciones.h"
#include "menu.h"
#include "funcionesGet.h"
#define TAM 20


int main()
{
    int opcion;
    char seguir = 's';
    int idPropietario;
   // char nombre[50];
   // char apellido[13];
   // int tarjeta;
    int id;
    int idExiste;
    char marca[51];
    char modelo[51];
    char patente[10];
    int tiempoEstacionado;


    ePropietario listadoProp[TAM];
    eAuto listadoAutos[TAM];
    inicializarAutos(listadoAutos, TAM);
    inicializarPropietarios(listadoProp, TAM);
    harcodePropietario(listadoProp, TAM);
    harcodeAutos(listadoAutos, TAM);

    do
    {
        opcion = pedirOpcionMenu();

        switch(opcion)
        {
        case 1:
            id = getInt("id del auto\n");

            idPropietario = getInt(" id del propietario \n");

            idExiste = buscarPropietarioPorID(listadoProp, TAM, idPropietario);

            while(idExiste == -1)
            {
                idPropietario = getInt("Reingrese una ID valida");
                idExiste = buscarPropietarioPorID(listadoProp, TAM, idPropietario);
            }

            printf(" marca \n");
            scanf("%s", marca);
            fflush(stdin);
            printf(" modelo \n");
            scanf("%s", modelo);
            fflush(stdin);
            printf(" patente \n");
            scanf("%s", patente);
            fflush(stdin);
            printf(" tiempoEstacionado \n");
            scanf("%d", &tiempoEstacionado);
            fflush(stdin);

            altaAuto(listadoAutos, TAM, id, idPropietario,  marca, modelo,  patente, tiempoEstacionado);

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            mostrarAutosConPropietario(listadoAutos, listadoProp, TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        }

        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}
