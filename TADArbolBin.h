#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef struct elemento
{
	int valor;
	int bit;
	char caracter;
}elemento;

typedef struct nodo
{
	struct nodo *izq, *der;
	elemento e;
}nodo;

typedef nodo* posicion;
typedef posicion arbol_bin;

void Initialize(arbol_bin *A);
/*recibe<-�rbol(A); 
Initialize (A)
Efecto: Recibe un �rbol binario A y lo inicializa para su trabajo normal.
*/

void Destroy(arbol_bin *A);
/*recibe<-�rbol(A); 
Destroy (A)
Efecto: Recibe un �rbol binario A y lo libera completamente.
*/

posicion Root(arbol_bin *A);
/*recibe<-�rbol(A); retorna -> posici�n
Root (A)
Efecto: Recibe un �rbol binario A y retorna la posici�n de la ra�z de A, si el �rbol es vac�o devuelve una posici�n nula.
*/

posicion Parent(arbol_bin *A, posicion P);
/*recibe<-�rbol(A), posici�n(P); retorna -> posici�n
Parent(A,P)
Efecto: Recibe un �rbol binario  A y una posici�n P, devuelve la posici�n de padre de p. 
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si P es la ra�z se devuelve una posici�n nula.
*/

posicion RightSon(arbol_bin *A, posicion P);
/*recibe<-�rbol(A), posici�n(P); retorna -> posici�n
RightSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve la posici�n del hijo derecho de p. 
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si P no tiene hijo derecho devuelve una posici�n nula.
*/

posicion LeftSon(arbol_bin *A, posicion P);
/*recibe<-�rbol(A), posici�n(P); retorna -> posici�n
LeftSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve la posici�n del hijo izquierdo de p. 
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida. Si P no tiene hijo izquierdo devuelve una posici�n nula.
*/

posicion Search(arbol_bin *A, elemento e);
/*recibe<-�rbol(A), elemento (E); retorna -> posici�n
Search(A,E)
Efecto: Recibe un �rbol binario A y un elemento E, devuelve la posici�n del elemento E en el �rbol  A.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si E tiene hijos o no es encontrado devuelve una posici�n nula.
*/


boolean Empty(arbol_bin *A);
/*recibe<-�rbol(A); retorna -> booleano
Empty(A)
Efecto: Recibe un �rbol binario A y devuelve verdadero en caso de que el �rbol A este vac�o, devuelve falso en caso contrario.
*/

boolean NullNode(arbol_bin *A, posicion p);
/*recibe<-�rbol(A), posici�n (P); retorna -> booleano
NullNode(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve verdadero si la posici�n P del �rbol A es nula o incorrecta y devuelve falso en caso contrario.
*/

elemento ReadNode(arbol_bin *A, posicion p);
/*recibe<-�rbol(A), posici�n (P); retorna -> elemento
ReadNode(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, devuelve el elemento en la posici�n P del �rbol A.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida..
*/

void NewRightSon(arbol_bin *A, posicion p, elemento e);
/*recibe<-�rbol(A), posici�n (P), elemento E; 
NewRightSon(A,P,E)
Efecto: Recibe un �rbol binario A, una posici�n P y un elemento E, se a�ade un nodo que contenga E como hijo derecho del nodo con posici�n P.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si el �rbol A es vac�o se agrega a un nodo ra�z con E. si P ya tiene un hijo derecho, se cancela la operaci�n.
*/

void NewLeftSon(arbol_bin *A, posicion p, elemento e);
/*recibe<-�rbol(A), posici�n (P), elemento E; 
NewLeftSon(A,P,E)
Efecto: Recibe un �rbol binario A, una posici�n P y un elemento E, se a�ade un nodo que contenga E como hijo izquierdo del nodo con posici�n P.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. Si el �rbol A es vac�o se agrega a un nodo ra�z con E; si P ya tiene un hijo Izquierdo, se cancela la operaci�n.
*/

void DeleteRightSon(arbol_bin *A, posicion p);
/*recibe<-�rbol(A), posici�n (P);
DeleteRightSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n se elimina al hijo derecho y todos sus descendientes del nodo con posici�n P.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida y tiene un hijo derecho.
*/

void DeleteLeftSon(arbol_bin *A, posicion p);
/*recibe<-�rbol(A), posici�n (P);
DeleteLeftSon(A,P)
Efecto: Recibe un �rbol binario A y una posici�n se elimina al hijo izquierdo y todos sus descendientes del nodo con posici�n P.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida y tiene un hijo izquierdo.
*/

void DeleteNode(arbol_bin *A, posicion p);
/*recibe<-�rbol(A), posici�n (P);
DeleteNode(A,P)
Efecto: Recibe un �rbol binario A y una posici�n P, se elimina al nodo con posici�n  P  y todos sus descendientes.
Requerimientos: El �rbol A es no vac�o y la posici�n P es una posici�n valida. 
*/

void ReplaceNode(arbol_bin *A, posicion p, elemento e);
/*recibe<-�rbol(A), posici�n (P), elemento (E);
ReplaceNode(A,P)
Efecto: Recibe un �rbol binario A, una posici�n P y un elemento E, se remplaza a E del nodo con posici�n P en A.
Requerimientos: El �rbol binario A es no vac�o y la posici�n P es una posici�n valida. 
*/
