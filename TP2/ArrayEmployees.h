#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list sEmployee* Pointer to array of sEmployees
 * \param len int Array length
 * \return int Return (0) if Ok
 *
 */
int initEmployees(sEmployee list[], int len);

/** \brief add in a existing list of sEmployees the values received as parameters
 * in the first empty position
 * \param list sEmployee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [without free space] - (0) if Ok
 */
int addEmployee(sEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief print the content of sEmployees array
 *
 * \param list sEmployee*
 * \param length int
 * \return int Return (0) if Ok
 *
 */
int printEmployees(sEmployee list[], int length);

/** \brief find an sEmployee by Id en returns the index position in array.
 *
 * \param list sEmployee*
 * \param len int
 * \param id int
 * \return Return sEmployee index position or (-1) if [sEmployee not found]
 */
int findEmployeeById(sEmployee list[], int len,int id);


/** \brief Remove a sEmployee by Id (put isEmpty Flag in 1)
 *
 * \param list sEmployee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [if can't find a sEmployee] - (0) if Ok
 *
 */
int removeEmployee(sEmployee list[], int len, int id);

/** \brief modify a existing list of sEmployees the values received as parameters in the first empty position
 * \param list sEmployee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [if can't find a sEmployee] - (0) if Ok
 **/
int modifyEmployee(sEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector, int option);

/** \brief Test array with hardcoded values
 *
 * \param list[] sEmployee
 * \param len int
 * \return int
 *
 */
int hardcode(sEmployee list[], int len);

/** \brief Sort the elements in the array of sEmployees, the argument order
indicate UP or DOWN order
 *
 * \param list sEmployee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(sEmployee list[], int len, int order);



/** \brief Search first empty index in the array of sEmployees
 *
 * \param list[] sEmployee
 * \param len int
 * \return int Return first ID available
 *
 */
int generateID(sEmployee list[], int len);

/** \brief Shows salaries
 *
 * \param list[] sEmployee
 * \param len int
 * \return int Return the sum of salaries
 *
 */
float showSalary(sEmployee list[], int len);

/** \brief Search number Of Employees
 *
 * \param list[] sEmployee
 * \param len int
 * \return int return number Of Employees
 *
 */
int searchFull(sEmployee list[], int len);

/** \brief Find the number of employees that exceed the average salary.
 *
 * \param list[] sEmployee
 * \param len int
 * \return int retrun employees that exceed the average
 *
 */
int searchSalarySup(sEmployee list[], int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
