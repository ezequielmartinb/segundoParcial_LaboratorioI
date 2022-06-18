#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "inputs.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pArchivo=NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		retorno=parser_PassengerFromText(pArchivo, pArrayListPassenger, path);
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivo;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo=fopen(path, "rb");
		retorno=parser_PassengerFromBinary(pArchivo, pArrayListPassenger, path);
	}
	return retorno;
}
/// @brief Busca el ultimo id que se cargo
/// @param pArrayListPassenger
/// @return retorna el ultimo id que se cargo
int controller_lastID(LinkedList* pArrayListPassenger)
{
	Passenger* auxiliarPasajeros;
	int id=0;
	int len;
	len=ll_len(pArrayListPassenger);

	for(int i=0;i<len;i++)
	{
		if(i==len-1)
		{
			auxiliarPasajeros=(Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(auxiliarPasajeros, &id);
		}
	}

	return id;
}


/** \brief Alta de pasajero
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 *
 * \return int
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* nuevoPasajero;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[50];
	int tipoPasajero;
	int estadoVuelo;
	char auxiliarTipoPasajero[50];
	char auxiliarEstadoVuelo[50];

	if(pArrayListPassenger!=NULL)
	{
		nuevoPasajero=Passenger_new();
		id=controller_lastID(pArrayListPassenger);
		id++;
		if(utn_getNombre(nombre, 50, "Ingrese el nombre del pasajero: ", "ERROR. NOMBRE INVALIDO. ", 3)==0 &&
		   utn_getNombre(apellido, 50, "Ingrese el apellido del pasajero: ", "ERROR. APELLIDO INVALIDO. ", 3)==0 &&
		   utn_getNumeroFlotante(&precio, "Ingrese el precio: ", "ERROR. PRECIO INVALIDO. ", 1, 3000000, 3)==0 &&
		   utn_getString(codigoDeVuelo, 50, "Ingrese el codigo de vuelo: ", "ERROR. CODIGO DE VUELO INVALIDO. ", 3)==0 &&
		   utn_getNumeroEntero(&tipoPasajero, "Ingrese el tipo de pasajero: \n\t1-FirstClass\n\t2-Executive\n\t3-EconomyClass\n", "ERROR. TIPO DE PASAJERO INVALIDO. ", 1, 3, 3)==0 &&
		   utn_getNumeroEntero(&estadoVuelo, "Ingrese el estado del vuelo: \n\t1-Aterrizado\n\t2-En Horario\n\t3-Demorado\n", "ERROR. ESTADO DE VUELO INVALIDO. ", 1, 3, 3)==0)
		{
			if(nuevoPasajero!=NULL)
			{
				switch(tipoPasajero)
				{
					case 1:
						strcpy(auxiliarTipoPasajero, "FirstClass");
						break;
					case 2:
						strcpy(auxiliarTipoPasajero, "Executive");
						break;
					case 3:
						strcpy(auxiliarTipoPasajero, "EconomyClass");
						break;
				}
				switch(estadoVuelo)
				{
					case 1:
						strcpy(auxiliarEstadoVuelo, "Aterrizado");
						break;
					case 2:
						strcpy(auxiliarEstadoVuelo, "En Horario");
						break;
					case 3:
						strcpy(auxiliarEstadoVuelo, "Demorado");
						break;
				}
				nuevoPasajero=Passenger_newParametrosCorrectos(id, nombre, apellido, precio, codigoDeVuelo, auxiliarTipoPasajero, auxiliarEstadoVuelo);
				//Passenger_showOnePassenger(nuevoPasajero);
				ll_add(pArrayListPassenger, nuevoPasajero);
				retorno=0;
			}
		}

	}

    return retorno;
}

/** \brief Listar pasajeros
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pasajerosAuxiliar=NULL;
	int retorno=-1;
	int tam;
	tam=ll_len(pArrayListPassenger);

	if(pArrayListPassenger!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			pasajerosAuxiliar=ll_get(pArrayListPassenger, i);
			Passenger_showOnePassenger(pasajerosAuxiliar);
			retorno=0;
		}
	}
	return retorno;
}
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int index=-1;
	int retorno=-1;
	int idIngresado;
	int len;
	int opcion;
	int idMaximo;
	Passenger* auxiliarPasajeros;
	auxiliarPasajeros=Passenger_new();

	if(pArrayListPassenger!=NULL && auxiliarPasajeros!=NULL && controller_ListPassenger(pArrayListPassenger)==0)
	{
		len=ll_len(pArrayListPassenger);
		idMaximo=controller_lastID(pArrayListPassenger);
		if(utn_getNumeroEntero(&idIngresado, "Ingrese el ID que desea modificar: ", "ERROR. ID INVALIDO. ", 1, idMaximo, 3)==0)
		{
			index=Passenger_findByIdInTheLinkedList(pArrayListPassenger, idIngresado);
			for(int i=0;i<len;i++)
			{
				auxiliarPasajeros=ll_get(pArrayListPassenger, index);
			}
			Passenger_showOnePassenger(auxiliarPasajeros);
			if(utn_getNumeroEntero(&opcion, "Que desea modificar?\n \t1-NOMBRE\n\t2-APELLIDO\n\t3-PRECIO\n\t4-TIPO DE PASAJERO\n\t5-CODIGO DE VUELO\n\t6-ESTADO DE VUELO\n Ingrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 6, 3)==0)
			{
				Passenger_modifyPassenger(auxiliarPasajeros, index, idIngresado, opcion);
				retorno=0;
			}

		}
	}
    return retorno;
}


/** \brief Baja de pasajero
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int index=-1;
	int idIngresado;
	int len;
	char opcion;
	int idMaximo;
	Passenger* auxiliarPasajeros;
	auxiliarPasajeros=Passenger_new();

	if(pArrayListPassenger!=NULL && auxiliarPasajeros!=NULL && controller_ListPassenger(pArrayListPassenger)==0)
	{
		len=ll_len(pArrayListPassenger);
		idMaximo=controller_lastID(pArrayListPassenger);
		if(utn_getNumeroEntero(&idIngresado, "Ingrese el ID que desea eliminar: ", "ERROR. ID INVALIDO", 1, idMaximo, 3)==0)
		{
			index=Passenger_findByIdInTheLinkedList(pArrayListPassenger, idIngresado);
			for(int i=0;i<len;i++)
			{
				auxiliarPasajeros=ll_get(pArrayListPassenger, index);
			}
			Passenger_showOnePassenger(auxiliarPasajeros);
			if(utn_getUnCaracter(&opcion, "Esta seguro que desea eliminar este pasajero? Y/N", "ERROR. OPCION INVALIDA", 'A', 'Z', 3)==0 && opcion=='Y')
			{
				if(ll_remove(pArrayListPassenger, index)==0)
				{
					printf("Se eliminó con exito\n");
				}
				else
				{
					printf("Error en la baja\n");
					index=-1;
				}
			}
		}

	}
    return index;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int opcion;
	int orden;

	if(utn_getNumeroEntero(&opcion, "\n\n\t1-Ordenar por ID\n"
									"\t2-Ordenar por Apellido\n"
									"\t3-Ordenar por Nombre\n"
									 "\t4-Ordenar por Precio\n"
									 "\t5-Ordenar por Codigo de Vuelo\n"
									 "\t6-Ordenar por Tipo de Pasajero\n"
									 "\t7-Ordenar por Estado de Vuelo\n"
									 "\t8-Volver al menu anterior\n\n\n"
									 "Ingrese la opcion por la cual desea ordenar: ", "ERROR. OPCION INVALIDA.", 1, 8, 3)==0)
	{
		switch(opcion)
		{
			case 1:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByID, orden);
				}
				break;
			case 2:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByApellido, orden);
				}
				break;
			case 3:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByNombre, orden);
				}
				break;
			case 4:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByPrecio, orden);
				}
				break;
			case 5:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByCodigoDeVuelo, orden);
				}
				break;
			case 6:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByTipoPasajero, orden);
				}
				break;
			case 7:
				if(utn_getNumeroEntero(&orden, "Desea ordenar de forma ASCENDENTE (1) o DESCENDENTE (0): ", "ERROR. OPCION INVALIDA.", 0, 1, 3)==0)
				{
					retorno=ll_sort(pArrayListPassenger, Passenger_compareByEstadoVuelo, orden);
				}
				break;
			case 8:
				printf("\n\n\n**********************VOLVIENDO AL MENU ANTERIOR**********************\n\n\n");
				break;
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;// ERROR AL ABRIR EL ARCHIVO
	FILE* pArchivo;
	Passenger* auxiliarPasajero=NULL;

	int auxiliarId;
	char auxiliarNombre[50];
	char auxiliarApellido[50];
	float auxiliarPrecio;
	char auxiliarCodigoVuelo[50];
	char auxiliarTipoPasajero[50];
	char auxiliarEstadoVuelo[50];

	char opcion;
	int len;
	int cantidad;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		if(utn_getUnCaracter(&opcion, "\nEsta accion sobreescribira los archivos. Desea sobreescribir los archivos? Y/N\n", "ERROR. OPCION INVALIDA", 'A', 'Z', 3)==0 && opcion=='Y')
		{
			pArchivo=fopen(path,"w");
			len=ll_len(pArrayListPassenger);
			fprintf(pArchivo, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i=0;i<len;i++)
			{
				auxiliarPasajero=(Passenger*) ll_get(pArrayListPassenger, i);
				if(auxiliarPasajero!=NULL)
				{
					if(Passenger_getId(auxiliarPasajero, &auxiliarId)==0 &&	Passenger_getNombre(auxiliarPasajero, auxiliarNombre)==0 &&
					Passenger_getApellido(auxiliarPasajero, auxiliarApellido)==0 && Passenger_getPrecio(auxiliarPasajero, &auxiliarPrecio)==0 &&
					Passenger_getCodigoVuelo(auxiliarPasajero, auxiliarCodigoVuelo)==0 && Passenger_getTipoPasajero(auxiliarPasajero, auxiliarTipoPasajero)==0 &&
					Passenger_getEstadoVuelo(auxiliarPasajero, auxiliarEstadoVuelo)==0)
					{
						cantidad=fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%s,%s\n", auxiliarId, auxiliarNombre, auxiliarApellido,auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo);
						retorno=0;// LOS DATOS FUERON GUARDADOS CON EXITO
					}
				}
				if(cantidad<7)
				{
					retorno=1;// ERROR AL GUARDAR LOS ARCHIVOS
					break;
				}
			}
			fclose(pArchivo);
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;// ERROR AL ABRIR EL ARCHIVO
	FILE* pArchivo;
	Passenger* auxiliarPasajeros=NULL;
	char opcion;
	int len;
	int cantidad;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{

		if(utn_getUnCaracter(&opcion, "\nEsta accion sobreescribira los archivos. Desea sobreescribir los archivos? Y/N\n", "ERROR. OPCION INVALIDA", 'A', 'Z', 3)==0 && opcion=='Y')
		{
			pArchivo=fopen(path,"wb");
			len=ll_len(pArrayListPassenger);
			for(int i=0;i<len;i++)
			{
				auxiliarPasajeros=(Passenger*) ll_get(pArrayListPassenger, i);
				if(auxiliarPasajeros!=NULL)
				{
					cantidad=fwrite(auxiliarPasajeros,sizeof(Passenger),1,pArchivo);
					retorno=0;// LOS DATOS SE GUARDARON CON EXITO
				}
				if(cantidad<1)
				{
					retorno=1;// ERROR AL GUARDAR LOS ARCHIVOS
					break;
				}
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}

