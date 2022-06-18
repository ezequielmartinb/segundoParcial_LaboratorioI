#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	char tipoPasajero[50];
	char estadoVuelo[50];


}Passenger;

/// @brief Crea un pasajero en memoria dinamica
///
/// @pre
/// @post
/// @return Retorna el pasajero creado en memoria dinamica
Passenger* Passenger_new();
/// @brief Crea un pasajero en memoria dinamica con parametros en cadena de caracteres
///
/// @pre
/// @post
/// @return Retorna el pasajero creado con esos parametros y en memoria dinamica
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
/// @brief Crea un pasajero en memoria dinamica con parametros de la estructura en cadena de caracteres
///
/// @pre
/// @post
/// @return Retorna el pasajero creado con esos parametros de la estructura y en memoria dinamica
Passenger* Passenger_newParametrosCorrectos(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);

/// @brief Libera el espacio de memoria que ocupa un pasajero
///
/// @pre
/// @post
void Passenger_delete(Passenger* this);
/// @brief Setea un ID en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setId(Passenger* this,int id);
/// @brief Obtiene un ID de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getId(Passenger* this,int* id);
/// @brief Setea un nombre en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setNombre(Passenger* this,char* nombre);
/// @brief Obtiene un nombre de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getNombre(Passenger* this,char* nombre);
/// @brief Setea un apellido en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param apellido
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setApellido(Passenger* this,char* apellido);
/// @brief Obtiene un apellido de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param apellido
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getApellido(Passenger* this,char* apellido);
/// @brief Setea un codigo de vuelo en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @brief Obtiene un codigo de vuelo de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @brief Setea un tipo de pasajero en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param tipoPasajero
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
/// @brief Obtiene un tipo de pasajero de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param tipoPasajero
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
/// @brief Setea un precio en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param precio
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setPrecio(Passenger* this,float precio);
/// @brief Obtiene un precio de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param precio
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getPrecio(Passenger* this,float* precio);
/// @brief Setea un estado de vuelo en la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param estadoVuelo
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
/// @brief Obtiene un estado de vuelo de la estructura Passenger recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param estadoVuelo
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);
/// @brief Muestra un pasajero
///
/// @pre
/// @post
/// @param this
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_showOnePassenger(Passenger* this);
/// @brief Muestra una lista de pasajeros
///
/// @pre
/// @post
/// @param Passenger
/// @param len
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_showListPassenger(Passenger* Passenger[], int len);
/// @brief Busca un espacio libre en la estructura pasajero recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param len
/// @return retorna -1 en caso de error y la posicion del espacio libre en caso de exito
int Passenger_findFreeSpace(Passenger* this[], int len);
/// @brief Busca el id pasado por parametro dentro de la estructura pasajero recibida por parametro
///
/// @pre
/// @post
/// @param this
/// @param len
/// @param id
/// @return retorna -1 en caso de error y la posicion donde está el ID en caso de exito
int Passenger_findById(Passenger* this[], int len, int id);
/// @brief Busca el id pasado por parametro dentro de la LinkedList recibida por parametro
///
/// @pre
/// @post
/// @param listaPasajeros
/// @param id
/// @return retorna -1 en caso de error y la posicion donde está el ID en caso de exito
int Passenger_findByIdInTheLinkedList(LinkedList* listaPasajeros,int id);
/// @brief Alta de pasajero
///
/// @pre
/// @post
/// @param this
/// @param len
/// @param id
/// @param nombre
/// @param apellido
/// @param precio
/// @param tipoPasajero
/// @param codigoVuelo
/// @param estadoVuelo
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_addPassenger(Passenger* this[], int len, char* id, char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo);
/// @brief Baja de pasajero
///
/// @pre
/// @post
/// @param this
/// @param len
/// @param id
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_removePassenger(Passenger* this[], int len, int id);
/// @brief Modificar de pasajero
///
/// @pre
/// @post
/// @param this
/// @param index
/// @param id
/// @param opcion
/// @return retorna -1 en caso de error y 0 en caso de exito
int Passenger_modifyPassenger(Passenger* this, int index, int id, int opcion);
/// @brief Compara los pasajeros recibidos por parametros por el ID
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByID(void* unPasajero, void* otroPasajero);
/// @brief Compara los pasajeros recibidos por parametros por el apellido
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByApellido(void* unPasajero, void* otroPasajero);
/// @brief Compara los pasajeros recibidos por parametros por el nombre
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByNombre(void* unPasajero, void* otroPasajero);
/// @brief Compara los pasajeros recibidos por parametros por el precio
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByPrecio(void* unPasajero, void* otroPasajero);
/// @brief Compara los pasajeros recibidos por parametros por el codigo de vuelo
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByCodigoDeVuelo(void* unPasajero, void* otroPasajero);
/// @brief Compara los pasajeros recibidos por parametros por el tipo de pasajero
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByTipoPasajero(void* unPasajero, void* otroPasajero);
/// @brief Compara los pasajeros recibidos por parametros por el estado de vuelo
///
/// @pre
/// @post
/// @param unPasajero
/// @param otroPasajero
/// @return retorna 0, en caso de que la comparacion de que son igual
/// 		retorna 1, en caso de que el primero sea mayor que el segundo
/// 		retorna -1 en caso de que el segundo sea mayor que el primero
int Passenger_compareByEstadoVuelo(void* unPasajero, void* otroPasajero);


#endif /* PASSENGER_H_ */
