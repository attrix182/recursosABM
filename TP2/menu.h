#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


/** \brief Muestra opciones del menu y obtiene una opcion
 *
 * \return int retorna la opcion typeada
 *
 */
int pedirOpcionMenu();

/** \brief Muestra un menu con opciones de modificacion y obtiene una opcion
 *
 * \return int retorna la opcion recibida
 *
 */
int getOptionModify();

/** \brief Muestra un menu con opciones de informes y obtiene una opcion
 *
 * \return int retorna la opcion recibida
 *
 */
int getOptionShow();
#endif // MENU_H_INCLUDED
