/*TAD Arbol binario
ESTRUCTURAS DE DATOS 1CM13
Noviembre 2017
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TADArbolBin.h"


/*recibe<-�rbol(A); 
Initialize (A)
Efecto: Recibe un �rbol binario A y lo inicializa para su trabajo normal.
*/
void Initialize(arbol_bin *A){
	*A = NULL;
	return;
}

/*recibe<-�rbol(A); 
Destroy (A)
Efecto: Recibe un �rbol binario A y lo libera completamente.
*/
void Destroy(arbol_bin *A){
	if(*A == NULL)
		return;
	else
	{
		if((*A)->izq != NULL)
			Destroy(&((*A)->izq));
		if((*A)->der != NULL)
			Destroy(&((*A)->der));
		free(*A);
		return;
	}
}

/*recibe<-�rbol(A); retorna -> posici�n
Root (A)
Efecto: Recibe un �rbol binario A y retorna la posici�n de la ra�z de A, si el �rbol es vac�o devuelve una posici�n nula.
*/
posicion Root(arbol_bin *A){
	return *A;
}


/*recibe<-�rbol(A), posici�n(P); retorna -> posici�n
Parent(A,P)
Efecto: Recibe un �rbol binario  A y una posici�n P, devuelve la posici�n de padre de p. 
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si P es la ra�z se devuelve una posici�n nula.
*/
posicion Parent(arbol_bin *A, posicion p){
	posicion r = NULL;
	if(*A == NULL || *A == p)
		return NULL;
	else if ((*A)->izq == p || (*A)->der == p)
		return *A;
	else 
	{
		r = Parent(&((*A)->izq), p);
		if(r == NULL)
			r = Parent(&((*A)->der), p);
		return r;
	}
}

/*recibe<-�rbol(A), posici�n(P); retorna -> posici�n
RightSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve la posici�n del hijo derecho de p. 
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si P no tiene hijo derecho devuelve una posici�n nula.
*/
posicion RightSon(arbol_bin *A, posicion P)
{
	posicion r = NULL;
	if(!NullNode(A, P))
		r = P -> der;
	
	return r;
}
/*recibe<-�rbol(A), posici�n(P); retorna -> posici�n
LeftSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve la posici�n del hijo izquierdo de p. 
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida. Si P no tiene hijo izquierdo devuelve una posici�n nula.
*/
posicion LeftSon(arbol_bin *A, posicion P)
{
	posicion r = NULL;
	if(!NullNode(A, P))
		r = P -> izq;
	
	return r;
}


/*recibe<-�rbol(A), elemento (E); retorna -> posici�n
Search(A,E)
Efecto: Recibe un �rbol binario A y un elemento, devuelve la posici�n del elemento E en el �rbol  A.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si E no es encontrado devuelve una posici�n nula.
*/
posicion Search(arbol_bin *A, elemento e)
{
	
	posicion r = NULL;
	if(*A == NULL)
		return NULL;
	else if (memcmp(&((*A)->e),&e,sizeof(elemento))==0 && ((*A)->izq == NULL) && ((*A)->der == NULL)) 
		return *A;
	else 
	{
		r = Search(&((*A)->izq), e);
		if(r == NULL)
			r = Search(&((*A)->der), e);
		return r;
	}

}

/*recibe<-�rbol(A); retorna -> booleano
Empty(A)
Efecto: Recibe un �rbol binario A y devuelve verdadero en caso de que el �rbol A este vac�o, devuelve falso en caso contrario.
*/
boolean Empty(arbol_bin *A)
{
	boolean r;
	if(*A == NULL)
		r = TRUE;
	else 
		r = FALSE;
	
	return r;
}

/*recibe<-�rbol(A), posici�n (P); retorna -> booleano
NullNode(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve verdadero si la posici�n P del �rbol A es nula o incorrecta y devuelve falso en caso contrario.
*/
boolean NullNode(arbol_bin *A, posicion p)
{
	boolean r;
	if(*A == NULL)
		return TRUE;
	else if (*A == p)
		return FALSE;	
	
	else 
	{
		r = NullNode(&((*A)->izq), p);
		if(r == TRUE)
			r = NullNode(&((*A)->der), p);
		return r;
	}
}

/*recibe<-�rbol(A), posici�n (P); retorna -> elemento
ReadNode(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve el elemento en la posici�n P del �rbol A.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida..
*/
elemento ReadNode(arbol_bin *A, posicion p)
{
	elemento r;
	
	if(!NullNode(A, p)){
		r = p->e;
	}
	else
	{
		printf("Error: ReadNode");
		exit(1);
	}
	
	return r;
}

/*recibe<-�rbol(A), posici�n (P), elemento E; 
NewRightSon(A,P,E)
Efecto: Recibe un �rbol binario A, una posici�n P y un elemento E, se a�ade un nodo que contenga E como hijo derecho del nodo con posici�n P.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si el �rbol A es vac�o se agrega a un nodo ra�z con E. si P ya tiene un hijo derecho, se cancela la operaci�n.
*/
void NewRightSon(arbol_bin *A, posicion p, elemento e)
{
	if(Empty(A))
	{
		*A = (nodo*)malloc(sizeof(nodo));
		(*A)->e = e;
		(*A)->izq = NULL;
		(*A)->der = NULL;
	}
	else if(!NullNode(A, p))
	{
		if(p->der != NULL){
			printf("Error: NewRightSon: ya existe");
			exit(1);
		}
		else
		{
			p->der = (nodo*)malloc(sizeof(nodo));
			p->der->e = e;
			p->der->izq = NULL;
			p->der->der = NULL;
		}
	}else{
		printf("Error: NewRightSon");
		exit(1);
	}
	return;
}

/*recibe<-�rbol(A), posici�n (P), elemento E; 
NewLeftSon(A,P,E)
Efecto: Recibe un �rbol binario A, una posici�n P y un elemento E, se a�ade un nodo que contenga E como hijo izquierdo del nodo con posici�n P.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si el �rbol A es vac�o se agrega a un nodo ra�z con E; si P ya tiene un hijo Izquierdo, se cancela la operaci�n.
*/
void NewLeftSon(arbol_bin *A, posicion p, elemento e)
{
	if(Empty(A))
	{
		*A = (nodo*)malloc(sizeof(nodo));
		(*A)->e = e;
		(*A)->izq = NULL;
		(*A)->der = NULL;
	}
	else if(!NullNode(A, p))
	{
		if(p->izq != NULL){
			printf("Error: NewLeftSon: ya existe");
			exit(1);
		}
		else
		{
			p->izq = (nodo*)malloc(sizeof(nodo));
			p->izq->e = e;
			p->izq->izq = NULL;
			p->izq->der = NULL;
		}
	}else{
		printf("Error: NewLeftSon");
		exit(1);
	}
	return;
}

/*recibe<-�rbol(A), posici�n (P);
DeleteRightSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n se elimina al hijo derecho y todos sus descendientes del nodo con posici�n P.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida y tiene un hijo derecho.
*/
void DeleteRightSon(arbol_bin *A, posicion p)
{
	if(!NullNode(A, p))
	{
		Destroy(&(p->der));
	}
	else
	{
		printf("Error: DeleteRightSon");
		exit(1);
	}
	return;
}

/*recibe<-�rbol(A), posici�n (P);
DeleteLeftSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n se elimina al hijo izquierdo y todos sus descendientes del nodo con posici�n P.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida y tiene un hijo izquierdo.
*/
void DeleteLeftSon(arbol_bin *A, posicion p)
{
	if(!NullNode(A, p))
	{
	Destroy(&(p->izq));
	}
	else
	{
		printf("Error: DeleteLeftSon");
		exit(1);
	}
	return;
}


/*recibe<-�rbol(A), posici�n (P);
DeleteNode(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, se elimina al nodo con posici�n  P  y todos sus descendientes.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida. 
*/
void DeleteNode(arbol_bin *A, posicion p)
{
	if(!NullNode(A, p))
	{
		Destroy(&p);
	}
	else
	{
		printf("Error: Delete");
		exit(1);
	}
	return;
}

/*recibe<-�rbol(A), posici�n (P), elemento (E);
ReplaceNode(A,P)
Efecto: Recibe un �rbol binario A, una posici�n P y un elemento E, se remplaza a E del nodo con posici�n P en A.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. 
*/
void ReplaceNode(arbol_bin *A, posicion p, elemento e)
{
	if(!NullNode(A, p))
	{
		p->e = e;
	}
	else
	{
		printf("Error: ReplaceNode");
		exit(1);
	}
	return; 
}

