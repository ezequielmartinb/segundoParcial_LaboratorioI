#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, char* path)
{
	Passenger* auxiliarPasajeros=NULL;
	int retornoFscanf;
	int retorno=-1;
	char idAuxiliar[50];
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	char precioAuxiliar[50];
	char tipoPasajeroAuxiliar[50];
	char codigoDeVueloAuxiliar[50];
	char estadoDeVueloAuxiliar[50];

	if(path!=NULL)
	{
		pFile=fopen(path, "r");
	}

	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAuxiliar,nombreAuxiliar,apellidoAuxiliar,precioAuxiliar, tipoPasajeroAuxiliar, codigoDeVueloAuxiliar, estadoDeVueloAuxiliar);// falsa lectura
		do
		{
			retornoFscanf=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAuxiliar,nombreAuxiliar,apellidoAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, codigoDeVueloAuxiliar, estadoDeVueloAuxiliar);
			if(retornoFscanf==7)
			{
				auxiliarPasajeros=Passenger_newParametros(idAuxiliar, apellidoAuxiliar, nombreAuxiliar,precioAuxiliar, tipoPasajeroAuxiliar, codigoDeVueloAuxiliar, estadoDeVueloAuxiliar);
				if(auxiliarPasajeros!=NULL)
				{
					ll_add(pArrayListPassenger,auxiliarPasajeros);
					retorno=0;
				}
			}
			else
			{
				break;
			}

		}while(!feof(pFile));

		fclose(pFile);
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger, char* path)
{
	int retorno=-1;
	Passenger* auxiliarPasajeros=NULL;
	int cantidad;
	int auxiliarId;
	char auxiliarNombre[50];
	char auxiliarApellido[50];
	float auxiliarPrecio;
	char auxiliarCodigoVuelo[20];
	char auxiliarTipoPasajero[50];
	char auxiliarEstadoVuelo[50];

	if(path!=NULL)
	{
		pFile=fopen(path, "rb");
	}
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			cantidad=fread(&auxiliarPasajeros,sizeof(Passenger),1,pFile);
			auxiliarPasajeros=Passenger_new();

			if(cantidad==1 && auxiliarPasajeros!=NULL)
			{
				if(Passenger_getId(auxiliarPasajeros,&auxiliarId)==0 &&
				   Passenger_getNombre(auxiliarPasajeros,auxiliarNombre)==0 &&
				   Passenger_getApellido(auxiliarPasajeros, auxiliarApellido)==0 &&
				   Passenger_getPrecio(auxiliarPasajeros, &auxiliarPrecio)==0 &&
				   Passenger_getCodigoVuelo(auxiliarPasajeros, auxiliarCodigoVuelo)==0 &&
				   Passenger_getTipoPasajero(auxiliarPasajeros, auxiliarTipoPasajero)==0 &&
				   Passenger_getEstadoVuelo(auxiliarPasajeros, auxiliarEstadoVuelo)==0)
				{
					 ll_add(pArrayListPassenger,auxiliarPasajeros);
					 retorno=0;
				}
				else
				{
					Passenger_delete(auxiliarPasajeros);
				}
			}
		}while(!feof(pFile));

		fclose(pFile);
	}

	return retorno;
}
