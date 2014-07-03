//Camino mas corto ponderado (Costo Positivo)
//Órden: O(v^2) 

#define INF 99999

struct nodoDijkstra{
	nat costo;
	V anterior;
	bool visitado;
};

Puntero<Tabla<V,nodoDijkstra>> CaminoMasCorto(Grafo<V,A> * g, V origen, FuncionCosto<V,A> fcosto){

	Puntero<Tabla<V,nodoDijkstra>> tabla = new TablaHashAbierta<V,nodoDijkstra>(fhash, g->CantVertices());

	//inicializo tabla
	foreach(v, g->ObtenerIterador()){
		nodoDijkstra nv;
		nv.costo = INF;
		nv.visitado = false;
		tabla->Agregar(v, nv);
	}
	
	//marco inicio
	nodoDijkstra no = tabla->Obtener(origen);
	no.costo = 0;
	tabla->Agregar(origen, no);
	
	nat cantVisitados=0;
	while(cantVisitado < tabla->Largo()){//tengo vertices sin visitar
	    cantVisitados++;
		
		V v = ObtenerMenorCostoNoVisitado(tabla);
		
		nodoDijkstra nv = tabla->Obtener(v);
		nv.visitado = true;
		tabla->Agregar(v,nv);
		
		foreach(a, g->Adyacentes(v)){
			nodoDijkstra na = tabla->Obtener(w);
			nat costoAcumulado = nv.costo + fcosto->ObtenerCosto(v,a); 
			if (costoAcumulado < na.costo){
				na.costo = costoAcumulado;
				na.anterior = v;
				tabla->Agregar(a,na);
			}
		}
	}
	return tabla;
}

V ObtenerMenorCostoNoVisitado(Puntero<Tabla<V,nodoDijkstra>>){
	V resutlado;
	nat min = INF;
	foreach(v, g->ObtenerVertices()){
		nodoDijkstra nv = tabla->Obtener(v);
		if (nv.costo < min && !nv.visitado){
			min = nv.costo;
			resultado = v;
		}
	}
	return resultado;
}

void ImprimirCamino(Puntero<Tabla<v, nodoDijkstra>> tabla, V d){
	if (!tabla->Pertenece(d)){
		cout << "No hay camino";
	}else{
		nodoDijkstra nd = tabla->Obtener(d);
		if (nd.costo > 0)
			ImprimirCamino(tabla, nd.anterior);
		cout << d << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INF = MAX_INT
struct nodoDijkstra{
    bool conocido;
    int costo;
    int anterior;
};

//inicializo la tabla
//marco el inicio
//Recorro vertices de menor costo, no conocidos
//recorro sus adyacentes
//actualizo el costo 

void Dijkstra(Matriz<int> grafo, int origen){
	//inicializo tabla
	Array<nodoDijkstra> tabla(CANT_VERTICES); 
	for (int i=0; i<= CANT_VERTICES; i++){
		tabla[i].costo = INF;
		tabla[i].conocido = false;
		tabla[i].anterior = -1;
	}

	//Marco el inicio
	tabla[origen].costo = 0;
	int actual = origen;

	//Recorro vertices de menor costo, no conocidos
	while(actual != -1){
		tabla[actual].conocido = true; //marco vertice como conocido
		for (int i=0; i<CANT_VERTICES; i++){ //recorro sus adyacentes
			if (grafo[actual][i]){  //si existe camino
			int costoAcumulado = tabla[actual].costo + peso(actual, i) 
			if (tabla[i].costo > costoAcumulado){  //Actualiza el costo
				tabla[i].costo = costoAcumulado;
				tabla[i].anterior = actual;
			}
		}
		actual = getVerticeMenorCostoNoConocido(tabla);
	}
}

int getVerticeMenorCostoNoConocido(Puntero<TablaDijkstra> tabla){
        int min = INF;
        int retorno = 0;
        for (int i =0; i<CANT_VERTICES; i++){
                if (tabla[i].costo < min && !tabla[i].conocido){
                        retorno = i;
                        min = tabla[i].costo;
                }
        }
        return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////