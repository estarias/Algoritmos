Con backtracking:

dado un arbol, devolver todos los caminos desde la raiz a una hoja.


struct nodoAB{
	nat dato;
	nodoABB * izq;
	nodoABB * der;
};

typedef Iterador<nat> Camino;

template <class T>
struct nodoL{
	T dato;
	nodoL * sig;
}

Iterador<Camino> TodosLosCaminos(nodoABB * raiz){
	nadoL<Camino> * caminos = NULL;
	nat cantCaminos = 0;
	EncontrarCaminos(raiz, NULL, 0, caminos, cantCaminos);
	Array<Camino> resultado(cantCaminos);
	nat pos = 0;
	while (camions != NULL){
		resultado[pos] = caminos->dato;
	}
	return resultado.ObtenerIterador();
}


void EncontrarCaminos(nodoABB * nodo, nodoL<nat> * caminoActual, nat largo, nodoL<Camino> * & caminos, nat & cantCaminos){
	if (nodo == NULL) return;
	if (nodo->izq == nodo && nodo->izq == NULL) { //Si es hoja
		AgregarCamino(nodo, caminoActual, largo, caminos, cantCaminos);
	}else{
		nodo<nat> * caminoSig = new nodoL<nat>;
		caminoSig = nodo->dato;
		caminoSig->sig = caminoActual;
		EncontrarCaminos(nodo->izq; caminoSig, largo+1, caminos, cantCaminos);
		EncontrarCaminos(nodo->der; caminoSig, largo+1, caminos, cantCaminos);
	}
}

void AgregarCamino(nodoAB * hoja, nodo<nat>* caminoActual, nat largo, nodoL<Camino> * &caminos, nat & cantCaminos){
		Array<nat> c (largo+1);
		c[largo] = hoja->dato;
		while(caminoActual !=NULL){
			largo--;
			c[largo]=caminoActual->dato;
			caminoActual = caminoActual->sig;
		}
		nodoL <Camino> * nuevo = new nodoL<Camino>;
		nuevo->dato = c.ObtenerIterador();
		nuevo->sig = caminos;
		caminos = nuevo;
		cantCaminos++;
}

/****
Escriba el procedimiento caminos, utilizando la técnica backtracking, que imprima todos los caminos
positivos de la raíz a una hoja (en ese orden) de un árbol binario no vacío de enteros. Un camino es positivo
si no posee ningún número menor o igual a cero. Si usa algún TAD auxiliar para resolver este problema,
deberá especificar las operaciones que utilice (solamente), pero no se requiere implementarlas.
****/
struct nodoAB { 
	int dato; 
	nodoAB * izq; 
	nodoAB * der; 
};
void caminos (nodoAB * arb){
    Pila<nodoAB *> * p=new PilaImp<nodoAB *>();
    caminosAux(arb,p);
};
void mostrarAux(Pila<nodoAB *> * p){
    if(!p->esVacia()){
        nodoAB * a=p->Top();
        p->Pop();
        mostrarAux(p);
        mostrar(arb->dato);
    };
};
void mostrar(Pila<nodoAB *> * p){
    Pila<nodoAB *> * aux=p->Clon();
    mostrarAux(aux);
};
void caminosAux (nodoAB * arb,Pila<nodoAB *> * p){
    if(arb!=NULL){
        if(arb>=0){
            p->Push(arb);
            if(esUnaHoja(arb))
                mostrar(p);
            caminosAux(arb->izq,p);
            caminosAux(arb->der,p);
            p->Pop();
        };
    };
};