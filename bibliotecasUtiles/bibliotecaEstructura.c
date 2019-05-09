#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaEstructura.h"

int inicializar(eGenerica listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}

int alta(eGenerica listado[], int len, int id, char nombre[],char apellido[], float sueldo)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].estado == 1)
        {
            listado[i].id = id;
            strcpy(listado[i].nombre, nombre);
            strcpy(listado[i].apellido, apellido);
            listado[i].sueldo= sueldo;
            listado[i].estado = 0;
            return 0;
        }
    }
    return -1;
}

int mostrarlistado(eGenerica listado[], int len)
{
    int i;
    printf("%10s - %10s - %10s - %10s \n", "ID", "Nombre", "Apellido", "Sueldo");
    ordenar(listado, len, 1);

    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%10d  %10s  %10s %10f \n", listado[i].id, listado[i].nombre, listado[i].apellido, listado[i].sueldo);

        }


    }
    return 0;
}

int buscarPorID(eGenerica listado[], int len,int id)
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

int baja(eGenerica listado[], int len, int id)
{

    int idAborrar = buscarPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}

int modificacion(eGenerica listado[], int len, int id, char nombre[],char apellido[], float sueldo, int option)
{
    int posAeditar = buscarPorID(listado, len, id);
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
        printf(" nuevo sueldo \n");
        scanf("%f", &sueldo);
        fflush(stdin);
        listado[posAeditar].sueldo = sueldo;
        listado[posAeditar].estado = 0;
        break;
    }


    return 0;

}

int harcode(eGenerica listado[], int len)
{
    int i;

    int id[4]= {1, 2, 3, 4};
    char nombre[4][50]= {"Fernado", "Juan", "Pablo", "Roberto"};
    char apellido[4][13]= {"Andes", "Caceres", "Rojas", "Echeverria"};
    int sueldo[4]= { 50, 80, 30, 20};
    int estado[4]= { 0, 0, 0, 0};

    for(i=0; i<4; i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].apellido,apellido[i]);
        listado[i].sueldo = sueldo[i];
;

    }
    return -1;
}

int ordenar(eGenerica listado[], int len, int order)
{
    int i;
    int j;
    eGenerica aux;


    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(listado[i].sueldo > listado[j].sueldo)
            {
                aux =listado[i];
                listado[i] = listado[j];
                listado[j] = aux;


            }
        }
    }

    return 0;
}
int buscarLibre(eGenerica listado[], int len)
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
