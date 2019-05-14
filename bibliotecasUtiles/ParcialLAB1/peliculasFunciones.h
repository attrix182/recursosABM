#ifndef PELICULASFUNCIONES_H_INCLUDED
#define PELICULASFUNCIONES_H_INCLUDED
#include "actoresFunciones.h"
typedef struct
{
    // código de película ,su título, fecha de estreno, genero
    int id;
    int codigoPelicula;
    char titulo[51];
    int fechaDeEstreno;
    char genero[21];
    int estado;
    int idActor;
} ePelicula;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int inicializarPeliculas(ePelicula[], int len);

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
int altaPeliculas(ePelicula[], int len, int id, int codigoPelicula, char titulo[],int fechaDeEstreno, char genero[], int idActor);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int mostrarListadoPeliculas(ePelicula[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int buscarPeliPorID(ePelicula[], int len,int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int bajaPelicula(ePelicula[], int len, int id);

/** \brief modify a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/

int harcodePeliculas(ePelicula[], int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int buscarLibrePelicula(ePelicula[], int len);

/** \brief
 *
 * \param ePelicula[]
 * \param ePropietario[]
 * \param len int
 * \return int
 *
 */
int mostrarPeliculasConActores(ePelicula[], eActor[], int len);

/** \brief modify a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int modificacionPelicula(ePelicula[], eActor listado[], int len, int id, char titulo[],int idActor, int fechaDeEstreno, int option);



#endif // PELICULASFUNCIONES_H_INCLUDED
