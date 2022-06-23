#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this;

	this=(LinkedList*) malloc(sizeof(LinkedList));

	if(this!=NULL)
	{
		this->pFirstNode=NULL;
		this->size=0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;
	if(this!=NULL)
	{
		returnAux=this->size;
	}
	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode=NULL;
	int len;

	len=ll_len(this);

	if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
	{
		pNode=this->pFirstNode;
		for(int i=0; i<nodeIndex;i++)
		{
			pNode=pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 * 						o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno=-1;
    int len;
    Node* pNuevoNodo=NULL;
    Node* pAuxiliarNodo=NULL; // NODO ANTERIOR

    len=ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
    	pNuevoNodo=(Node*)malloc(sizeof(Node));
		if(pNuevoNodo!=NULL)
		{
			if(nodeIndex==0)
			{
				pNuevoNodo->pNextNode=this->pFirstNode;
				this->pFirstNode=pNuevoNodo;
				pNuevoNodo->pElement=pElement;
				this->size++;
				retorno=0;
			}
			else
			{
				pAuxiliarNodo=getNode(this, nodeIndex-1);
				if(pAuxiliarNodo!=NULL)
				{
					pNuevoNodo->pNextNode=pAuxiliarNodo->pNextNode;
					pAuxiliarNodo->pNextNode=pNuevoNodo;
					pNuevoNodo->pElement=pElement;
					this->size++;
					retorno=0;
				}
			}
		}
    }


    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno=-1;
    int len;

    len=ll_len(this);

    if(this!=NULL && len>=0)
    {
    	retorno=addNode(this, len, pElement);
    }

    return retorno;
}

/** \brief Permite obtener un elemento del nodo
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL
 * 							o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno=NULL;
    Node* pNodo=NULL;
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
    	pNodo=getNode(this, index);
    	if(pNodo!=NULL)
    	{
    		retorno=pNodo->pElement;
    	}
    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno=-1;
    int len;
    Node* pNodo=NULL;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
    	pNodo=getNode(this, index);
		if(pNodo!=NULL)
		{
			pNodo->pElement=pElement;
			retorno=0;
		}
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno=-1;
    int len;
	Node* pAuxiliarNodo=NULL;
	Node* pAuxiliarNodoAnterior=NULL; // NODO ANTERIOR

	len=ll_len(this);

	if(this!=NULL && index>=0 && index<len)
	{
		pAuxiliarNodo=getNode(this, index);
		if(pAuxiliarNodo!=NULL)
		{
			if(index==0)
			{
				this->pFirstNode=pAuxiliarNodo->pNextNode;
			}
			else
			{
				pAuxiliarNodoAnterior=getNode(this, index-1);
				if(pAuxiliarNodoAnterior!=NULL)
				{
					pAuxiliarNodoAnterior->pNextNode=pAuxiliarNodo->pNextNode;
				}
			}
			this->size--;
			free(pAuxiliarNodo);
			retorno=0;
		}

	}
    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno=-1;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        if(len>0)
        {
        	for(int i=0;i<len;i++)
        	{
        		ll_remove(this, i);
        	}
        	retorno=0;
        }
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno=-1;

    if(this!=NULL && ll_clear(this)==0)
    {
    	free(this);
    	retorno=0;
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno=-1;
    int len;
    void* auxiliarElemento=NULL;

    if(this!=NULL)
    {
        len=ll_len(this);
    	for(int i=0;i<len;i++)
    	{
    		auxiliarElemento=ll_get(this, i);
    		if(auxiliarElemento==pElement)
    		{
    			retorno=i;
    			break;
    		}
    	}
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno=-1;
    int len;

    if(this!=NULL)
    {
    	len=ll_len(this);
    	if(len>0)
    	{
    		retorno=0;
    	}
    	else
    	{
    		retorno=1;
    	}
    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 * 							o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno=-1;
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)
    {
    	retorno=addNode(this, index, pElement);
    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL
 * 								o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno=NULL;
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
    	retorno=ll_get(this, index);
    	ll_remove(this, index);
    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno=-1;
    int index;

    if(this!=NULL)
    {
    	retorno=0;
    	index=ll_indexOf(this, pElement);
    	if(index!=-1)
    	{
    		retorno=1;
    	}
    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno=-1;
    int lenThis2;
    void* pElementThis2;

    if(this!=NULL && this2!=NULL)
    {
    	lenThis2=ll_len(this2);
    	retorno=1;

    	for(int i=0;i<lenThis2;i++)
    	{
    		pElementThis2=ll_get(this2, i);
    		if(ll_contains(this, pElementThis2)==0)
    		{
    			retorno=0;
    			break;
    		}
    	}
    }

    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneSubList=NULL;
    void* auxiliarElemento=NULL;

    int len;
    len=ll_len(this);

    if(this!=NULL && from>=0 && from<len && to<=len && from<to)
    {
    	cloneSubList=ll_newLinkedList();
    	if(cloneSubList!=NULL)
    	{
    		for(int i=from;i<to;i++)
    		{
    			auxiliarElemento=ll_get(this, i);
    			ll_add(cloneSubList, auxiliarElemento);
    		}
    	}
    }

    return cloneSubList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneList=NULL;
    int len;

    if(this!=NULL)
    {
    	len=ll_len(this);
    	cloneList=ll_subList(this, 0, len);
    }

    return cloneList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno=-1;
    int len;
    int estaOrdenado;
    void* auxiliarUnElemento=NULL;
    void* auxiliarOtroElemento=NULL;

    if(this!=NULL && (order==0 || order==1) && pFunc!=NULL)
    {
    	len=ll_len(this);
    	do
    	{
    		estaOrdenado=1;
    		len--;
    		for(int i=0;i<len;i++)
    		{
    			auxiliarUnElemento=ll_get(this, i);
    			auxiliarOtroElemento=ll_get(this, i+1);
    			if((pFunc(auxiliarUnElemento, auxiliarOtroElemento)>0 && order==1) || (pFunc(auxiliarUnElemento, auxiliarOtroElemento)<0 && order==0))
    			{
    				ll_set(this, i, auxiliarOtroElemento);
    				ll_set(this, i+1, auxiliarUnElemento);
    				estaOrdenado=0;
    			}
    		}
    	}while(estaOrdenado==0);
    	retorno=0;
    }

    return retorno;

}

// INFORMES
/** \
 * 		1. 	Pasajeros por clase: Se deber� informar la cantidad de pasajeros por clase.
 *
 * 			Para ello se deber� agregar la funci�n �ll_count()�, la cual permitir� contar elementos de la lista bajo alg�n
			criterio
 *
 * 		La funci�n �ll_count� recibir� una lista y una funci�n �fn�.
 *
 * 		Se deber� iterar todos los elementos de la lista y pas�rselos a la funcion �fn�.
 *
 * 		La funci�n �fn� devolver� la cantidad que debe contarse.
 *
 * 		La funci�n �ll_count� almacenar� un acumulador al cual sumar� el valor de retorno de �fn� en cada iteraci�n.

		Al finalizar las iteraciones, la funci�n �ll_count� devolver� el valor
		acumulado
 */
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int acumuladorCantidadTipoPasajeros;
	int len;
    void* auxiliarElemento=NULL;
    int retornoFn;
    acumuladorCantidadTipoPasajeros=0;

	if(this!=NULL && fn!=NULL)
	{
		len=ll_len(this);
		for(int i=0;i<len;i++)
		{
			auxiliarElemento=ll_get(this, i);
			retornoFn=fn(auxiliarElemento);
			acumuladorCantidadTipoPasajeros=acumuladorCantidadTipoPasajeros+retornoFn;
		}
	}

	return acumuladorCantidadTipoPasajeros;
}
/*
 * 	2.  Generar archivo de vuelos: se solicitar� al usuario que ingrese un TIPO DE PASAJERO y se
		generar� otro archivo con el mismo formato que el original, pero s�lo con los pasajeros de
		ese vuelo. Para realizar este punto se deber� desarrollar la funci�n �ll_filter()�, la cual
		permitir� filtrar elementos de una lista bajo alg�n criterio.
 *
 *
 * 	La funci�n �ll_filter� recibir� una lista y una funci�n �fn�.
 *
 * 	Se deber� iterar todos los elementos de la lista y pas�rselos a la funci�n �fn�.
 *
 * 	La funci�n �fn� analizar� el elemento recibido e informar� si cumple o no con el criterio establecido.
 *
 * 	Al finalizar la iteraci�n, la nueva lista estar� conformada s�lo por los elementos que corresponden.
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* auxiliarLista;
    void* auxiliarElemento=NULL;
    int retornoFn;
	int len;

	if(this!=NULL && fn!=NULL)
	{
		len=ll_len(this);
		auxiliarLista=ll_newLinkedList();
		if(auxiliarLista!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				auxiliarElemento=ll_get(this, i);
				retornoFn=fn(auxiliarElemento);
				if(retornoFn==0)
				{
					ll_add(auxiliarLista, auxiliarElemento);
				}
			}
		}
	}
	return auxiliarLista;
}
/*
		3. Calcular millas acumuladas: se deber� informar el listado de pasajeros con una columna
		   extra que indicar� las millas que se acumularon con ese vuelo seg�n el siguiente criterio:

				1-Cada $100 se suma 1 milla.
				2-Si el pasajero es de primera clase, duplica las millas acumuladas
				3-Si el pasajero es de clase ejecutiva, triplica las millas acumuladas

			Para el desarrollo de este punto se deber� crear la funci�n �ll_map()�, que permitir� calcular
			el campo millas.


			La funci�n �ll_map� recibir� una lista y una funci�n �fn�.

			Se deber� iterar todos los elementos de la lista y pas�rselos a la funci�n �fn�.

			La funci�n �fn� podr� realizar un c�lculo con el elemento recibido y modificar alguno de sus campos si es necesario.

			Al finalizar la iteraci�n, los elementos de la lista quedar�n modificados.


 */
LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
	LinkedList* auxiliarLista=NULL;
    void* auxiliarElemento=NULL;
	int len;

	if(this!=NULL && fn!=NULL)
	{
		len=ll_len(this);
		for(int i=0;i<len;i++)
		{
			auxiliarElemento=ll_get(this, i);
			fn(auxiliarElemento);
			ll_add(auxiliarLista, auxiliarElemento);
		}
	}

	return auxiliarLista;
}
