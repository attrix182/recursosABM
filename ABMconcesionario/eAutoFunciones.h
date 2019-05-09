#ifndef EAUTOFUNCIONES_H_INCLUDED
#define EAUTOFUNCIONES_H_INCLUDED
#include "bibliotecaEstructura.h"

typedef struct
{
    int id;
    char marca[51];
    char modelo[51];
    char patente[10];
    int tiempoEstacionado;
    int estado;
    int idPropietario;
} eAuto;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int inicializarAutos(eAuto[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int altaAuto(eAuto[], int len, int id, int idPropietario, char marca[],char modelo[], char patente[], int tiempoEstacionado);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int mostrarListadoAutos(eAuto[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int buscarAutoPorID(eAuto[], int len,int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int bajaAuto(eAuto[], int len, int id);

/** \brief modify a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/

int harcodeAutos(eAuto[], int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int buscarLibreAuto(eAuto[], int len);

/** \brief
 *
 * \param eAuto[]
 * \param ePropietario[]
 * \param len int
 * \return int
 *
 */
int mostrarAutosConPropietario(eAuto[], ePropietario[], int len);




#endif // EAUTOFUNCIONES_H_INCLUDED

