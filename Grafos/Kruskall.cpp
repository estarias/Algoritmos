/*****************************************************
Àrbol de cubrimiento mínimo: Conjunto mín de aristas, para no perder conectividad y la suma de los costos de esas aristas sea el minimo.
Agrega vértices que no pertenecen a la sol y otro sque si.

//supondremos grafos no dirigidos en nuestro curso.

Aplicaciones:

Dada una red de saneamiento y quiero minimizar los metros de metros de tubería que necesito para
Fibra óptica, electríca, metros de carretera, etc.

CaminoMasBarato
*****************************************************/
O(A) prom solo cargar la cola de prioridad.
O(log A)

Esta en la misma componente conexa, si esta unido agrupado (mio)

Algoritmo de Kruskalll

Iterador<Tupla<nat, nat>>  Kruskall (Grafo <nat, nat> g){
						 //Vorig, V dest
	ColaPrioridad <Tupla<nat, nat>, nat> * arcos = new ColaHeap<Tupla<nat, nat>, nat> (g->CantArcos()); //O,D -> peso
	Array<nat> comp(g->CantVertices());
	Lista<Tupla<nat, nat>> * retorno = new ListaImp<Tupla<nat, nat>> ();
	
	//inicializo
	foreach(v, g->ObtenerIterador()){
		comp[v]=v;
		foreach (w, g->Adyacentes()){
			Tupla<nat,nat> aux (v,w);
			arcos->Encolar(aux, g->ObtenerArco(v,w)); //aux:dato, lo otro es la prioridad.
		}
	}
	
	while (!arcos->EsVacio() && retorno->Largo() < g->CantVertices() - 1){
		auto aux = arcos->ObtenerMin();
		arcos->BorrarMin();
		if (comp[aux.Dato1] == comp[aux.Dato2])
			continue; //vuelve al while 
		nat c2 = comp[aux.Dato2];
		for (nat i = 0; i<comp.Largo;i++){  
			if (comp[i] == c2) //si estan en la componente, le pongo lo que tenia el dato1.
				comp[i] = comp[aux.Dato1];
		}
		retorno->Agregar(aux);
	}
	
	return retorno->ObtenerIterador();
	
}

/////////////////////////////////////////////////////////////////////////////////////
struct Conexion{
	Cadena C1;
	Cadena C2;
	nat dist;
}

Array<Conexion> CamaraCable(Grafo<Cadena, nat> g){
	ColaPrioridad<Conexion>* aristas = CargarAristas(g);
	Tabla<Cadena, nat>* componentes = CargarComponentes(g);
	Array<Conexion> cMin (g->getCantidadVertices() -1);
	nat tope=0;

	while(!aristas->esVacia()){
		Conexio min = aristas->obtenerMin();
		aristas->borrarMin();
		nat compO = componentes->obtener(min.c1);
		nat compD = componentes->obtener(min.c2);
		if(compO != compD){
			cantMetros += min.dist;
			cMin[tope++] = min;
			actualizarComponentes(compO, compD, componentes, grafo);
		}
	}
	return Tupla<nat, array<Conexion>>(cantMetros, cMin);
}

ColaPrioridad<Conexion>* CargarAristas(Grafo<Cadena, nat> g){
	ColaPrioridad<Conexion>* cola = new ColaPrioridad<Conexion>();
	foreach(v, g->ObtenerVertices()){
		foreach(w, g->ObtenerVertices()){
			if (g->existeArco(v,w)){
				Conexion c;
				c.C1 = v;
				c.C2 = w;
				c.dist = g->ObtenerCosto(v,w); //FuncionCosto
				cola->Encolar(c, dist); //dist es la prioriodad
			}
		}	
	}
	return cola;
}

Tabla<Cadena, nat>* CargarComponentes(Grafo<Cadena, nat> g){
	Tabla<Cadena, nat>* tabla = new Tabla<Cadena, nat>();
	nat nroComponente =0;
	foreach(v, g->ObtenerVertices()){
		tabla->Agregar(v, nroComponente++);
	}
	return tabla;
}

void actualizarComponentes(nat compO, nat CompD, Tabla<Cadena, nat>* tabla, Grafo<Cadena, nat> g){
	foreach(v, g->ObtenerVertices()){
		nat nroComp = tabla->Obtener(v);
		if (nroComp == CompD) tabla->Agregar(v, CompO); //si existe lo reemplaza
	}
}
