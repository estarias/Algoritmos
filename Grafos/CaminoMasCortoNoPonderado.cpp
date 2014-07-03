//CaminoMasCortoNoPonderado desde un origen a todos los vertices de G.
//Resuelto en la clase pasada, en el cuaderno.  (aplicacion de busqueda en amplitud)

struct nodoCamino{
	nat costo;
	V anterior;
	bool visitado;
}

Tabla<V,nodoCamino> * CaminoMasCortoNoPonderado(Grafo<V,A> * g, V origen){
	Tabla<V,nodoCamino> * tabla-> new TablaHashAbierta<V,nat>(fhash, g->CantVertices());
	Cola<V> * c= new ColaImp<V>();

	c->Encolar(origen);
	nodoCamino nodoOrigen;
	nodoOrigen.costo=0;
	nodoOrigen.visitado=true;
	tabla->Agregar(origen, nodoOrigen);
	
	while(!c->EsVacia()){
		V v = c->Desencolar();
		nodoCamino nv = tabla->Obtener(v); //nodo al vertice que acaba de desencolar
		foreach(w, g->Adyacentes(v)){
			if (!tabla->Pertenece(w)){
				nodoCamino nw;
				nw.costo = nv.costo + 1;
				nw.visitado = true;
				nw.anterior = v;
				c->Encolar(w);
				tabla->Agregar(w,nw);
			}
		}
	}

	return tabla;
}

void ImprimirCamino(Tabla<v, nodoCamino> * tabla, V d){
	if (!tabla->Pertenece(d)){
		cout << "No hay camino"
	}else{
		nodoCamino nd = tabla->Obtener(d);
		if (nd.costo > 0)
			ImprimirCamino(tabla, nd.anterior);
		cout << d << endl;
	}
}

