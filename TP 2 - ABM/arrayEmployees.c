#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#include "utn.h"

/** \brief Generates an unique ID for each employee
 *
 * \return unique ID
 *
 */
static int generateNextId ()
{
    static int id=0;

    id ++;

    return id;
}

int menu ()
{
    int option;
    fflush(stdin);
    printf(" *****Menu*****\n"
           " 1. Alta empleado\n"
           " 2. Modificar empleado\n"
           " 3. Baja Empleado\n"
           " 4. Informar\n"
           " 5. Salir\n"
           " Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    while(option < 0 || option > 5)
    {
        printf(" Por favor, ingrese una opcion del 1 al 5\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf(" MENU:\n"
               " 1. Alta empleado\n"
               " 2. Modificar empleado\n"
               " 3. Baja Empleado\n"
               " 4. Informar\n"
               " 5. Salir\n"
               " Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &option);
    }
    return option;
}

int initEmployee(sEmployee* list, int len)
{
    int myReturn=-1;
    int i;
    if(list !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=FREE;
        }
        myReturn=0;
    }
    return myReturn;
}

int obtainFreeSlot (sEmployee* list, int len)
{
    int myReturn=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == FREE)
        {
            myReturn = i;
            break;
        }
    }
    return myReturn;
}

int addEmployee(sEmployee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
    int myReturn=-1;
    int indexIsEmpty=obtainFreeSlot(list, len);
    int employeeIndexId=findEmployeeById(list, len, id);

    if(list != NULL)
    {
        if (name !=NULL && lastName !=NULL)
        {
            if (indexIsEmpty!=-1)
            {
                if (list[employeeIndexId].isEmpty==TAKEN)
                {
                    id=generateNextId();
                }
                list[indexIsEmpty].id=id;
                strcpy(list[indexIsEmpty].name, name);
                strcpy(list[indexIsEmpty].lastName, lastName);
                list[indexIsEmpty].salary=salary;
                list[indexIsEmpty].sector=sector;
                list[indexIsEmpty].isEmpty=TAKEN;
                myReturn=0;
            }
        }
    }
    return myReturn;
}

int findEmployeeById(sEmployee* list, int len, int id)
{
    int myReturn=-1;
    int i;

    if(list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if (list[i].id == id && list[i].isEmpty==TAKEN)
            {
                myReturn=i;
                break;
            }
        }
    }
    return myReturn;
}

int removeEmployee(sEmployee* list, int len, int id)
{
    int myReturn=-1;
    int i;

    printf ("\n Ingrese el ID del empleado que desea dar de baja: ");
    scanf("%d", &id);

    int employeeIndexPosition=findEmployeeById(list, len, id);

    for (i=0; i<len; i++)
    {
        if (employeeIndexPosition>=0)
        {
            printf ("\n El empleado fue dado de baja.\n");
            list[employeeIndexPosition].isEmpty = FREE;
            system ("pause");
            break;
        }
        else
        {
            printf ("\n El ID no existe en el indice.\n");
            system ("pause");
            break;
        }
    }
    return myReturn;
}

int modifyEmployee(sEmployee* list, int len, int id)
{
    int myReturn=-1;
    int modifyOptions;
    int index;
    char auxNewName[31];
    char auxNewLastName[31];
    float auxNewSalary;
    int auxNewSector;
    char proceed='n';

    printf("Ingrese el ID que desea modificar:\n");
    scanf("%d", &id);
    index=findEmployeeById(list, len, id);
    if(list!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("\n%5s %20s %20s %10s %3s \n", "ID","Nombre","Apellido","Sueldo","Sector");
                printEmployee(list, index);
                printf("\n\n Seleccione el campo que desea modificar:");
                printf("\n 1. Nombre\n");
                printf(" 2. Apellido\n");
                printf(" 3. Salario\n");
                printf(" 4. Sector\n");
                scanf("%d", &modifyOptions);
                switch(modifyOptions)
                {
                case 1:
                    getValidString(" Ingrese nombre: "," Error, ingrese nuevamente:", auxNewName);
                    strcpy(list[index].name, auxNewName);
                    break;
                case 2:
                    getValidString(" Ingrese apellido: "," Error, ingrese nuevamente:", auxNewLastName);
                    strcpy(list[index].lastName, auxNewLastName);
                    break;
                case 3:
                    auxNewSalary=getValidFloat(" Ingrese salario: \n"," Error, el salario no es valido.\n", 0, 1000000);
                    list[index].salary=auxNewSalary;
                    break;
                case 4:
                    auxNewSector=getValidInt(" Ingrese sector: \n"," Error, el sector no es valido.\n", 0, 200);
                    list[index].sector=auxNewSector;
                    break;
                default :
                    printf(" Opcion incorrecta, ingrese un numero del 1 al 5.");
                }
                printf(" ¿Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&proceed);
                system("pause");
                system("cls");
            }
            while(proceed=='s' || proceed=='S');
        }
        else if(index<0)
        {
            printf(" No existe ese Id. \n");
        }
        myReturn=0;
    }
    return myReturn;
}

void averageSalary(sEmployee* list, int len)
{
    float average=0;
    float total=0;
    int counterEmployees=0;
    int counterSalary=0;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            counterEmployees++;
            total=total+list[i].salary;
        }
    }
    average= total/counterEmployees;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            if(list[i].salary>average)
            {
                counterSalary++;
            }
        }
    }
    printf("Total Salarios: %.2f\n", total);
    printf("Promedio Salarios: %.2f\n", average);
    printf("Cantidad de Empleados que superan el promedio: %d\n", counterSalary);
}

int getOrder()
{
    int order;
    printf("Ingrese el orden en que quiere ordenar la lista de empleados\n0. Descendente\n1. Ascendente\n");
    scanf("%d", &order);
    return order;
}

int sortEmployees(sEmployee* list, int len, int order)
{
    int myReturn=-1;
    sEmployee aux;
    if(len > 0 && list != NULL)
    {
        switch(order)
        {
        case DESCENDENTE:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) > 0)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
            myReturn=0;
            break;
        case ASCENDENTE:
            if(len > 0 && list != NULL)
            {
                for(int i=0; i<len - 1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[j].lastName, list[i].lastName) < 0)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                        else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
                myReturn=0;
                break;
            default:
                printf("Error, ingrese 1 (ASCENDENTE) o 0 (DESCENDENTE)\n");
                break;
            }
        }
    }
    return myReturn;
}

int printEmployee(sEmployee* list, int index)///imprime UN solo empleado
{
    int myReturn=-1;/// variable para retornar error
    if (list!=NULL)///verifica que los datos no tengan basura y que len sea positivo
    {
        if(list[index].isEmpty==TAKEN)
        {
            printf ("%5d %20s %20s %10.2f %3d\n", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
            myReturn=0;///mi variable myReturn me retorna 0
        }
    }
    return myReturn;///me retorna Error (-1) si hay error y retorna 0 si esta todo OK.(el return tiene que estar solo una vez en la funcion)
}

int printEmployees(sEmployee* list, int len)///imprime todos los empleados ingresados
{
    int myReturn=-1;///posible error
    int i;///iteraciones actuales
    if (list!=NULL)
    {
        printf("\n%5s %20s %20s %10s %3s \n", "ID","Nombre","Apellido","Sueldo","Sector");
        for (i=0; i<len; i++)///creo un for para recorrer la lista de empleados e imprime los datos de cada empleado
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list, i);
                myReturn=0;///mi variable myReturn cambia su valor a 0
            }
        }
    }
    return myReturn;///en caso de Error me retorna (-1)
}

