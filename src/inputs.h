/*
 * inputs.h
 *
 *  Created on: 30 abr. 2022
 *      Author: Ezequiel
 */

#ifndef INPUTS_H_
#define INPUTS_H_
// PEDIR STRING
int utn_getString(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);
int utn_myGets(char cadena[], int len);
// OBTENER NUMERO ENTEROS (NEGATIVOS Y POSITIVOS)
int utn_getNumeroEntero(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_validarSiEsNumerico(char cadena[]);
int utn_validarSiSonLetras(char cadena[]);
// OBTENER NUMERO FLOTANTES (NEGATIVOS Y POSITIVOS)
int utn_getNumeroFlotante(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_validarSiSonLetrasFlotantes(char cadena[]);
int utn_validarSiEsNumericoFlotante(char cadena[]);
// OBTENER NOMBRES
int utn_getNombre(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);
int utn_validarSiEsUnNombreCompuesto(char cadena[]);
int utn_validarSiEsNumericoEnCadena(char cadena[]);
int utn_formatearNombre(char cadena[], int len);
// PEDIR UN CHAR
int utn_getUnCaracter(char* unCaracter, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

#endif /* INPUTS_H_ */
