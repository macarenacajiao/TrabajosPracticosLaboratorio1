#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"

int main()
{
    sEmployee employeesList[QTY];
    int option;
    int order;
    int freeSlot;
    int auxId=0;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int flag=0;

    initEmployee(employeesList, QTY);

    do
    {
        option=menu();

        switch(option)
        {
        case 1:
            flag++;
            freeSlot=obtainFreeSlot(employeesList, QTY);
            if (freeSlot!=-1)
            {
                getValidString(" Ingrese nombre:\n", " Error, ingrese nombre nuevamente (solo letras):", auxName);
                fflush(stdin);
                system("pause");
                getValidString(" Ingrese apellido:\n", " Error, ingrese apellido nuevamente (solo letras):", auxLastName);
                fflush(stdin);
                system("pause");
                auxSalary=getValidFloat(" Ingrese salario:\n"," Error, ingrese salario nuevamente (solo numero flotante):\n", 0, 1000000);
                system("pause");
                auxSector=getValidInt(" Ingrese sector:\n"," Error, ingrese sector nuevamente (solo numero):\n", 0, 10);
                system("pause");
            }
            else
            {
                printf (" No hay espacio libre!\n");
                system ("pause");
                system ("cls");
            }
            addEmployee(employeesList, QTY, auxId, auxName, auxLastName, auxSalary, auxSector);
            break;
        case 2:
            if(flag!=0)
            {
                modifyEmployee(employeesList, QTY, auxId);
            }
            else
            {
                printf(" No hay datos que mostrar.\n");
                system ("pause");
            }
            break;
        case 3:
            if(flag!=0)
            {
                removeEmployee(employeesList, QTY, auxId);
            }
            else
            {

                printf(" No hay datos que mostrar\n");
                system ("pause");
            }
            break;
        case 4:
            if(flag!=0)
            {
                order=getOrder();
                sortEmployees(employeesList, QTY, order);
                printEmployees(employeesList, QTY);
                averageSalary(employeesList, QTY);
                system ("pause");
                system ("cls");
            }
            else
            {
                printf(" No hay datos que mostrar\n");
                system ("pause");
            }
            break;
        case 5:
            printf (" Gracias por usar el ABM.");
            break;
        default:
            printf (" Error. Ingrese nuevamente el comando del 1 al 5.");
            break;
        }
        system("cls");
    }
    while (option!=5);
}

