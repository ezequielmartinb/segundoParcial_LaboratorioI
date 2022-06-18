#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    LinkedList* listaPasajeros=ll_newLinkedList();
    int opcionIngresada;
    int banderaGuardarDeDatosTxt;
    int banderaGuardarDeDatosBin;
    int banderaCargarDeDatosTxt;
    int banderaCargarDeDatosBin;
    int banderaAlta;

    banderaGuardarDeDatosTxt=0;
    banderaGuardarDeDatosBin=1;
    banderaCargarDeDatosTxt=1;
    banderaCargarDeDatosBin=1;
    banderaAlta=1;

    setbuf(stdout, NULL);

    while(opcionIngresada!=10)
	{
		printf("\t**********************BIENVENIDO A LA APP UTN LINKEDLIST**********************\n\n");
		printf("1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			   "2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			   "3- Alta de pasajero\n"
			   "4- Modificar datos de pasajero\n"
			   "5- Baja de pasajero\n"
			   "6- Listar pasajero\n"
			   "7- Ordenar pasajero\n"
			   "8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
			   "9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
			   "10- SALIR \n\n");
		if(utn_getNumeroEntero(&opcionIngresada, "Ingrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 10, 3)==0)
		{
			switch(opcionIngresada)
			{
				case 1:
					if(banderaGuardarDeDatosTxt==1)
					{
						printf("\n\n\n**********************ANTES DE CARGAR LOS ARCHIVOS EN TEXTO, PRIMERO HAY QUE GUARDAR**********************\n\n\n");
					}
					else
					{
						if(controller_loadFromText("data.csv",listaPasajeros)!=-1)
						{
							banderaCargarDeDatosTxt=0;
							printf("\n\n\n**********************LA CARGA DE DATOS EN TEXTO SE REALIZO CON EXITO**********************\n\n\n");
						}
					}
					break;
				case 2:
					if(banderaGuardarDeDatosBin==1)
					{
						printf("\n\n\n**********************ANTES DE CARGAR LOS ARCHIVOS BINARIO, PRIMERO HAY QUE GUARDAR**********************\n\n\n");
					}
					else
					{
						if(controller_loadFromBinary("data.bin",listaPasajeros)!=-1)
						{
							banderaCargarDeDatosBin=0;
							printf("\n\n\n**********************LA CARGA DE DATOS EN BINARIO SE REALIZO CON EXITO**********************\n\n\n");
						}
					}
					break;
				case 3:
					if(controller_addPassenger(listaPasajeros)==0)
					{
						banderaAlta=0;
						printf("\n\n\n**********************ALTA EXITOSA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************ALTA DENEGADA**********************\n\n\n");
					}
					break;
				case 4:
					if((banderaCargarDeDatosTxt==1 && banderaCargarDeDatosBin==1) && banderaAlta==1)
					{
						printf("\n\n\n**********************ANTES DE MODIFICAR, PRIMERO HAY QUE DAR DE ALTA O CARGAR LOS ARCHIVOS**********************\n\n\n");
					}
					else if(controller_editPassenger(listaPasajeros)==0)
					{
						printf("\n\n\n**********************MODIFICACION EXITOSA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************MODIFICACION DENEGADA**********************\n\n\n");
					}

					break;
				case 5:
					if((banderaCargarDeDatosTxt==1 && banderaCargarDeDatosBin==1) && banderaAlta==1)
					{
						printf("\n\n\n**********************ANTES DE DAR DE BAJA, PRIMERO HAY QUE DAR DE ALTA O CARGAR LOS ARCHIVOS**********************\n\n\n");
					}
					else if(controller_removePassenger(listaPasajeros)!=-1)
					{
						printf("\n\n\n**********************BAJA EXITOSA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************BAJA DENEGADA**********************\n\n\n");
					}
					break;
				case 6:
					if(banderaCargarDeDatosTxt==1 && banderaCargarDeDatosBin==1 && banderaAlta==1)
					{
						printf("\n\n\n**********************ANTES DE LISTAR, PRIMERO HAY QUE DAR DE ALTA O CARGAR LOS ARCHIVOS**********************\n\n\n");
					}
					else if(controller_ListPassenger(listaPasajeros)!=0)
					{
						printf("\n\n\n**********************LA LISTA NO SE MOSTRO CON EXITO**********************\n\n\n");
					}
					break;
				case 7:
					if((banderaCargarDeDatosTxt==1 && banderaCargarDeDatosBin==1) && banderaAlta==1)
					{
						printf("\n\n\n**********************ANTES DE ORDENAR, PRIMERO HAY QUE DAR DE ALTA O CARGAR LOS ARCHIVOS**********************\n\n\n");
					}
					else if(controller_sortPassenger(listaPasajeros)==0)
					{
						printf("\n\n\n**********************LA LISTA SE ORDENO DE FORMA EXITOSA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************LA LISTA NO SE ORDENO DE FORMA EXITOSA**********************\n\n\n");
					}
					break;
				case 8:
					if(controller_saveAsText("data.csv", listaPasajeros)==0)
					{
						banderaGuardarDeDatosTxt=0;
						printf("\n\n\n**********************LOS DATOS DE LA LISTA FUERON GUARDADOS CON EXITO**********************\n\n\n");
					}
					else if(controller_saveAsText("data.csv", listaPasajeros)==1)
					{
						printf("\n\n\n**********************ERROR AL GUARDAR LOS DATOS DE LA LISTA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************ERROR AL ABRIR LOS DATOS DE LA LISTA**********************\n\n\n");
					}
					break;
				case 9:
					if(controller_saveAsBinary("data.bin", listaPasajeros)==0)
					{
						banderaGuardarDeDatosBin=0;
						printf("\n\n\n**********************LOS DATOS DE LA LISTA FUERON GUARDADOS CON EXITO**********************\n\n\n");
					}
					else if(controller_saveAsBinary("data.bin", listaPasajeros)==1)
					{
						printf("\n\n\n**********************ERROR AL GUARDAR LOS DATOS DE LA LISTA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************ERROR AL ABRIR LOS DATOS DE LA LISTA**********************\n\n\n");
					}
					break;
				case 10:
					printf("\n\n\n**********************GRACIAS POR UTILIZAR LA APP UTN LINKEDLIST**********************\n\n\n\n");
					break;
			}
		}

	}

    return 0;
}

