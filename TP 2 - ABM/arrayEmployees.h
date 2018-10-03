#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#define FREE 1
#define TAKEN 0
#define ASCENDENTE 1
#define DESCENDENTE 0
#define QTY 1000

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

/** \brief Menu that indicates "alta, modificacion, baja y salir"
 *
 * \param void
 * \return int option "alta, modificacion, baja y salir"
 *
 */
int menu();

/** \brief Obtains free slot from the index.
 *
 * \param sEmployee list, employee list
 * \param int len, array lenght
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (i) if Ok
 */
int obtainFreeSlot (sEmployee* list, int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployee(sEmployee* list, int len);

/** \brief Add in a existing list of employees the values received as parameters
 * in the first empty position
 *
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(sEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */
int findEmployeeById(sEmployee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(sEmployee* list, int len, int id); //Remove employees function.

/** \brief Modifies an employee introducing the id (index position)
 *
 * \param list sEmployee*
 * \param len int
 * \param id int
 * \return
 *
 */
int modifyEmployee(sEmployee* list, int len, int id); //Modify employees function.

/** \brief Calculates
 *
 * \param list sEmployee*
 * \param int len
 * \return
 *
 */
void averageSalary(sEmployee* list, int len);

/** \brief Returns the order that the user selected to order the list
 *
 * \return int [0] - DOWN // [1] UP
 *
 */
int getOrder();

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(sEmployee* list, int len, int order);

/** \brief Prints the content of ONE employee
 *
 * \param list sEmployee*
 * \param index int
 * \return prints list of employees or Error (-1) if there isn't any employee
 */
int printEmployee(sEmployee* list, int length);

/** \brief Prints the content of employees array
 *
 * \param list sEmployee*
 * \param len intC:\Users\makic\OneDrive\Documentos\Mako\Makito\Programación UTN\CodeBlocks Proyectos\TP 2 - ABM\arrayEmployees.h
 * \return prints employees list or returns (-1) if Error [Invalid length or NULL pointer]
 *
 */
int printEmployees (sEmployee* list, int len);
