#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesGet.h"

int initEmployees(sEmployee list[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        list[i].isEmpty = 1;

    }

    return 0;

}

int addEmployee(sEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;

            return 0;
        }
    }
    return -1;
}

int printEmployees(sEmployee list[], int len)
{
    int i;
    printf("%10s - %10s - %10s - %10s - %10s \n", "ID", "NOMBRE", "APELLIDO","SALARIO"," SECTOR");
    sortEmployees(list, len, 1);

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%10d  %10s  %10s  %10.2f  %10d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

        }


    }
    return 0;
}

int findEmployeeById(sEmployee list[], int len,int id)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            return i;
        }
    }

    return -1;

}

int removeEmployee(sEmployee list[], int len, int id)
{

    int idAborrar = findEmployeeById(list, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    list[idAborrar].isEmpty = 1;
    return 0;
}

int modifyEmployee(sEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector, int option)
{
    int posToEdit = findEmployeeById(list, len, id);
    if(posToEdit == -1)
    {
        return -1;
    }
    switch(option)
    {
    case 1:
        getString("Ingrese nuevo nombre del empleado\n", name);
        strcpy(list[posToEdit].name, name);
        break;
    case 2:
        getString("Ingrese nuevo apellido del empleado\n", lastName);
        strcpy(list[posToEdit].lastName, lastName);
        break;
    case 3:
        salary = getFloat("Ingrese nuevo salario\n");;
        list[posToEdit].salary = salary;
        break;
    case 4:
        sector = getInt("Ingrese nuevo sector\n");
        list[posToEdit].sector = sector;
        break;
    }


    return 0;

}

int hardcode(sEmployee list[], int len)
{
    int i;
    int id[4]= {1, 2, 3, 4};
    char name[4][50]= {"Fernado", "Juan", "Pablo", "Roberto"};
    char lastName[4][13]= {"Andes", "caceres", "Caceres", "Echeverria"};
    float salary[4]= {100, 200, 300, 400};
    int sector[4]= { 8, 2,3,2};
    int isEmpty[4]= { 0, 0, 0, 0};
    for(i=0; i<4; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = isEmpty[i];

    }
    return -1;
}

int sortEmployees(sEmployee list[], int len, int order)
{
    int i;
    int j;
    sEmployee aux;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(list[i].isEmpty==0 && list[j].isEmpty==0 ){
            if(stricmp(list[i].lastName, list[j].lastName)>0)
            {
                aux =list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            else if(stricmp(list[i].lastName, list[j].lastName) == 0 && list[j].sector < list[i].sector)
            {
                aux=list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            }

        }
    }

    return 0;
}

int generateID(sEmployee list[], int len)
{
    int i;
    int id;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty ==1)
        {
            id = i+1;
            break;
        }
    }
    return id;
}

float showSalary(sEmployee list[], int len)
{
    int i;
    float sumSalary = 0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty ==0)
        {

            sumSalary = sumSalary + list[i].salary;

        }
    }
    return sumSalary;
}

int searchFull(sEmployee list[], int len)
{
    int i;
    int numberOfEmployees = 0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty ==0)
        {
            numberOfEmployees = numberOfEmployees + 1;

        }
    }
    return numberOfEmployees;
}
int searchSalarySup(sEmployee list[], int len)
{
    int i;
    int salarySup = 0;
    int salaries;
    int average;
    int numberOfEmployees;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty ==0)
        {
            salaries = showSalary(list, len);
            numberOfEmployees = searchFull(list, len);
            average = salaries/numberOfEmployees;
            if(list[i].salary > average )
            {
                salarySup = salarySup + 1;
            }
        }
    }
    return salarySup;
}
