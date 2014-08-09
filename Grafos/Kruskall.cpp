/*****************************************************
Àrbol de cubrimiento mínimo: Conjunto mín de arcos, para no perder conectividad y la suma de los costos de esas arcos sea el minimo.
Agrega vértices que no pertenecen a la sol y otro sque si.

El objetivo es unir TODOS los vértices

//supondremos grafos no dirigidos en nuestro curso.

Aplicaciones:

Dada una red de saneamiento y quiero minimizar los metros de metros de tubería que necesito para
Fibra óptica, electríca, metros de carretera, etc.

CaminoMasBarato
*****************************************************/
O(A) prom solo cargar la cola de prioridad.
O(log A)

struct Conexion{
	V x;
	V y;
	nat dist;
	
	Conexion(V v,V w,nat d){
		x = v;
		y = w; 
		dist = d;
	}
}

Array<Conexion> kruskall(Grafo<V, nat> g){

	//Cargar Aristas
	ColaPrioridad<Conexion>* arcos = new ColaImp<Conexion>();
	foreach(v, g->ObtenerVertices()){
		foreach(w, g->ObtenerVertices()){
			if (g->existeArco(v,w)){
				Conexion c(v,w, g->ObtenerCosto(v,w));
				arcos->Agregar(c, dist); //dist es la prioriodad
			}
		}	
	}
	
	//Cargar componentes
	Tabla<V, nat>* componentes = new TablaImp<V, nat>();
	nat i =0;
	foreach(v, g->ObtenerVertices()) componentes->Agregar(v, i++); 
	
	Array<Conexion> sol (g->getCantVertices() -1);
	nat distTotal = 0;
	nat i=0;
	while(!arcos->esVacia()){
		Conexion min = arcos->obtenerMin();
		arcos->borrarMin();
		nat compX = componentes->obtener(min.x);
		nat compY = componentes->obtener(min.y);
		if(compX != compY){
			distTotal += min.dist;
			sol[i++] = min;
			//actualizarComponentes
			foreach(v, g->ObtenerVertices()){
				nat nroComp = componentes->Obtener(v);
				if (nroComp == compY) componentes->Agregar(v, compX); //si existe lo reemplaza
			}
		}
	}
	
	cout << "distancia total: " << distTotal;
	
	return sol;
	
}
