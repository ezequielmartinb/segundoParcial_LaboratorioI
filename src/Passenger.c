#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"
#include "inputs.h"

Passenger* Passenger_new()
{
	Passenger* auxiliar=NULL;

	auxiliar=(Passenger*) malloc(sizeof(Passenger));

	if (auxiliar!=NULL)
	{
		Passenger_setId(auxiliar, 0);
		Passenger_setNombre(auxiliar, " ");
		Passenger_setApellido(auxiliar, " ");
		Passenger_setPrecio(auxiliar, 0);
		Passenger_setTipoPasajero(auxiliar, 0);
		Passenger_setCodigoVuelo(auxiliar, " ");
		Passenger_setEstadoVuelo(auxiliar, 0);
	}

	return auxiliar;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* auxiliar=NULL;

	auxiliar=Passenger_new();

	if(auxiliar!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL)
	{
		if(Passenger_setId(auxiliar, atoi(idStr))!=0 || Passenger_setNombre(auxiliar, nombreStr)!=0 || Passenger_setApellido(auxiliar, apellidoStr)!=0
		   || Passenger_setPrecio(auxiliar, atof(precioStr))!=0 || Passenger_setTipoPasajero(auxiliar, tipoPasajeroStr)!=0
		   || Passenger_setCodigoVuelo(auxiliar, codigoVueloStr)!=0 || Passenger_setEstadoVuelo(auxiliar, estadoVueloStr)!=0)
		{
			auxiliar=NULL;
		}
	}

	return auxiliar;
}
Passenger* Passenger_newParametrosCorrectos(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
{
	Passenger* auxiliar=NULL;

	auxiliar=Passenger_new();

	if(auxiliar!=NULL && id>0 && nombre!=NULL && apellido!=NULL && precio>0 && tipoPasajero>0 && codigoVuelo!=NULL && estadoVuelo>0)
	{
		// ANTES DEL SET, HAY QUE VALIDAR SI LO QUE RECIBO ES UN DATO VALIDO
		if(Passenger_setId(auxiliar, id)!=0 || Passenger_setNombre(auxiliar, nombre)!=0 || Passenger_setApellido(auxiliar, apellido)!=0
		   || Passenger_setPrecio(auxiliar, precio)!=0 || Passenger_setTipoPasajero(auxiliar, tipoPasajero)!=0
		   || Passenger_setCodigoVuelo(auxiliar, codigoVuelo)!=0 || Passenger_setEstadoVuelo(auxiliar, estadoVuelo)!=0)
		{
			auxiliar=NULL;
		}
	}

	return auxiliar;
}
void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno=-1;

	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}

	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=-1;

	if (this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=0;
	}

	return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if (this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido, apellido);
		retorno=0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		retorno=0;
	}

	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=-1;

	if (this!=NULL && precio>0)
	{
		this->precio= precio;
		retorno=0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=-1;

	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno=0;
	}

	return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;

	if (this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno=0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno=0;
	}

	return retorno;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if (this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno=0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno=0;
	}

	return retorno;
}
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno=-1;

	if (this!=NULL && estadoVuelo>0)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno=0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno=-1;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno=0;
	}

	return retorno;
}

int Passenger_showOnePassenger(Passenger* this)
{
	int retorno=-1;
	int idAuxiliar;
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	float precioAuxiliar;
	char tipoPasajeroAuxiliar[50];
	char codigoVueloAuxiliar[50];
	char estadoVuelo[50];

	if(this!=NULL)
	{
		if(Passenger_getId(this, &idAuxiliar)==0 &&	Passenger_getNombre(this, nombreAuxiliar)==0 &&
		   Passenger_getApellido(this, apellidoAuxiliar)==0 && Passenger_getPrecio(this, &precioAuxiliar)==0 &&
		   Passenger_getTipoPasajero(this, tipoPasajeroAuxiliar)==0 &&	Passenger_getCodigoVuelo(this, codigoVueloAuxiliar)==0 &&
		   Passenger_getEstadoVuelo(this, estadoVuelo)==0)
		{
			printf("|%4d | |%15s | |%15s | |%15.2f | |%15s | |%15s | |%15s |\n",idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, codigoVueloAuxiliar, estadoVuelo);
			retorno=0;
		}

	}

	return retorno;
}
int Passenger_showListPassenger(Passenger* this[], int len)
{
	int retorno=-1;

	if(this!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(this[i]!=NULL)// SI LA POSICION EN EL ARRAY NO ESTA VACIA, MUESTRO EL ARRAY
			{
				Passenger_showOnePassenger(this[i]);
			}
		}
		retorno=0;
	}

	return retorno;
}

int Passenger_findFreeSpace(Passenger* this[], int len)
{
	int retorno=-1;
	if (this!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			//*(this + i) = NULL; NOTACION DE PUNTEROS
			if(this[i] == NULL)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int Passenger_findByIdInTheLinkedList(LinkedList* listaPasajeros,int id)
{
	int retorno = -1;
	int len;
	int i;
	Passenger* auxiliarPasajeros;
	int idLeido;

	if(listaPasajeros!=NULL && id>0)
	{
		len=ll_len(listaPasajeros);

		for(i=0;i<len;i++)
		{
			auxiliarPasajeros=ll_get(listaPasajeros,i);
			if(Passenger_getId(auxiliarPasajeros,&idLeido)==0)
			{
				if(idLeido==id)
				{
					retorno=i;
					break;
				}
			}
		}
	}
	return retorno;
}
int Passenger_findById(Passenger* this[], int len, int id)
{
	int retorno=-1;
	if (this!=NULL && len>0 && id>0)
	{
		for (int i=0; i<len; i++)
		{
			//*(this + i) = NULL; NOTACION DE PUNTEROS
			if(this[i]!=NULL && Passenger_getId(this[i], &id)==id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_addPassenger(Passenger* this[], int len, char* id, char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
	int retorno=-1;
	int index;
	if (this!=NULL && len>0)
	{
		index=Passenger_findFreeSpace(this, len);
		if (this[index]==NULL)
		{
			this[index]=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			retorno=0;
		}
	}
	return retorno;
}
int Passenger_removePassenger(Passenger* this[], int len, int id)
{
	int retorno=-1;
	int index;

	if (this!=NULL && len>0 && id>0)
	{
		index=Passenger_findById(this, len, id);
		if (index!=-1 && Passenger_getId(this[index], &id)==id)
		{
			Passenger_showOnePassenger(this[index]);
			Passenger_delete(this[index]);
			this[index]=NULL;
			retorno=0;
		}
	}

	return retorno;
}
int Passenger_modifyPassenger(Passenger* this, int index, int id, int opcion)
{
	int retorno=-1;
	char nuevoNombre[50];
	char nuevoApellido[50];
	float nuevoPrecio;
	char nuevoCodigoDeVuelo[50];
	char auxiliarNuevoTipoPasajero[50];
	int nuevoTipoPasajero;
	char auxiliarNuevoEstadoVuelo[50];
	int nuevoEstadoVuelo;

	if (this!=NULL && index>0)
	{
		switch(opcion)
		{
			case 1:
				if (utn_getNombre(nuevoNombre, 50, "Ingrese el nuevo nombre: ", "ERROR. NOMBRE INVALIDO", 3)==0)
				{
					Passenger_setNombre(this, nuevoNombre);
					retorno = 0;
				}
				break;
			case 2:
				if (utn_getNombre(nuevoApellido, 50, "Ingrese el nuevo apellido: ", "ERROR. APELLIDO INVALIDO", 3)==0)
				{
					Passenger_setApellido(this, nuevoApellido);
					retorno=0;
				}
				break;
			case 3:
				if (utn_getNumeroFlotante(&nuevoPrecio, "Ingrese nuevo precio: ", "ERROR. PRECIO INVALIDO", 1, 3600000, 3)==0)
				{
					Passenger_setPrecio(this, nuevoPrecio);
					retorno = 0;
				}
				break;
			case 4:
				if (utn_getString(nuevoCodigoDeVuelo, 50, "Ingrese el nuevo codigo de vuelo: ", "ERROR. CODIGO DE VUELO INVALIDO. ", 3)==0)
				{
					Passenger_setCodigoVuelo(this, nuevoCodigoDeVuelo);
					retorno = 0;
				}
				break;
			case 5:
				if (utn_getNumeroEntero(&nuevoTipoPasajero, "Ingrese el nuevo tipo de pasajero: \n\t1-FirstClass\n\t2-Executive\n\t3-EconomyClass\n", "ERROR. TIPO DE PASAJERO INVALIDO. ", 1, 3, 3))
				{
					switch(nuevoTipoPasajero)
					{
						case 1:
							strcpy(auxiliarNuevoTipoPasajero, "FirstClass");
							break;
						case 2:
							strcpy(auxiliarNuevoTipoPasajero, "Executive");
							break;
						case 3:
							strcpy(auxiliarNuevoTipoPasajero, "EconomyClass");
							break;
					}
					Passenger_setTipoPasajero(this, auxiliarNuevoTipoPasajero);
					retorno = 0;
				}
				break;
			case 6:
				if (utn_getNumeroEntero(&nuevoEstadoVuelo, "Ingrese el nuevo estado del vuelo: \n\t1-Aterrizado\n\t2-En Horario\n\t3-Demorado\n", "ERROR. ESTADO DE VUELO INVALIDO. ", 1, 3, 3)==0)
				{
					switch(nuevoEstadoVuelo)
					{
					case 1:
						strcpy(auxiliarNuevoEstadoVuelo, "Aterrizado");
						break;
					case 2:
						strcpy(auxiliarNuevoEstadoVuelo, "En Horario");
						break;
					case 3:
						strcpy(auxiliarNuevoEstadoVuelo, "Demorado");
						break;
					}
					Passenger_setEstadoVuelo(this, auxiliarNuevoEstadoVuelo);
					retorno = 0;
				}
				break;
		}
	}
	return retorno;
}
int Passenger_compareByID(void* unPasajero, void* otroPasajero)
{
	int retorno;
	int auxiliarIDUno;
	int auxiliarIDDos;
	retorno=0;

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getId((Passenger*)unPasajero, &auxiliarIDUno);
		Passenger_getId((Passenger*)otroPasajero, &auxiliarIDDos);

		if(auxiliarIDUno>auxiliarIDDos)
		{
			retorno=1;
		}
		else if(auxiliarIDUno<auxiliarIDDos)
		{
			retorno=-1;
		}
	}

	return retorno;
}
int Passenger_compareByApellido(void* unPasajero, void* otroPasajero)
{
	int retorno;
	char auxiliarUnApellido[50];
	char auxiliarOtroApellido[50];

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getApellido((Passenger*)unPasajero, auxiliarUnApellido);
		Passenger_getApellido((Passenger*)otroPasajero, auxiliarOtroApellido);

		retorno=strcmp(auxiliarUnApellido, auxiliarOtroApellido);
	}

	return retorno;
}
int Passenger_compareByNombre(void* unPasajero, void* otroPasajero)
{
	int retorno;
	char auxiliarUnNombre[50];
	char auxiliarOtroNombre[50];

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getNombre((Passenger*)unPasajero, auxiliarUnNombre);
		Passenger_getNombre((Passenger*)otroPasajero, auxiliarOtroNombre);

		retorno=strcmp(auxiliarUnNombre, auxiliarOtroNombre);
	}

	return retorno;
}

int Passenger_compareByPrecio(void* unPasajero, void* otroPasajero)
{
	int retorno;
	float auxiliarPrecioUno;
	float auxiliarPrecioDos;
	retorno=0;

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getPrecio((Passenger*)unPasajero, &auxiliarPrecioUno);
		Passenger_getPrecio((Passenger*)otroPasajero, &auxiliarPrecioDos);

		if(auxiliarPrecioUno>auxiliarPrecioDos)
		{
			retorno=1;
		}
		else if(auxiliarPrecioUno<auxiliarPrecioDos)
		{
			retorno=-1;
		}
	}

	return retorno;
}
int Passenger_compareByCodigoDeVuelo(void* unPasajero, void* otroPasajero)
{
	int retorno;
	char auxiliarUnCodigoDeVuelo[50];
	char auxiliarOtroCodigoDeVuelo[50];

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getCodigoVuelo((Passenger*)unPasajero, auxiliarUnCodigoDeVuelo);
		Passenger_getCodigoVuelo((Passenger*)otroPasajero, auxiliarOtroCodigoDeVuelo);

		retorno=strcmp(auxiliarUnCodigoDeVuelo, auxiliarOtroCodigoDeVuelo);
	}

	return retorno;
}
int Passenger_compareByTipoPasajero(void* unPasajero, void* otroPasajero)
{
	int retorno;
	char auxiliarUnTipoPasajero[50];
	char auxiliarOtroTipoPasajero[50];

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getTipoPasajero((Passenger*)unPasajero, auxiliarUnTipoPasajero);
		Passenger_getTipoPasajero((Passenger*)otroPasajero, auxiliarOtroTipoPasajero);

		retorno=strcmp(auxiliarUnTipoPasajero, auxiliarOtroTipoPasajero);
	}

	return retorno;
}
int Passenger_compareByEstadoVuelo(void* unPasajero, void* otroPasajero)
{
	int retorno;
	char auxiliarUnEstadoVuelo[50];
	char auxiliarOtroEstadoVuelo[50];

	if(unPasajero!=NULL && otroPasajero!=NULL)
	{
		Passenger_getEstadoVuelo((Passenger*)unPasajero, auxiliarUnEstadoVuelo);
		Passenger_getEstadoVuelo((Passenger*)otroPasajero, auxiliarOtroEstadoVuelo);

		retorno=strcmp(auxiliarUnEstadoVuelo, auxiliarOtroEstadoVuelo);
	}

	return retorno;
}

