/*****************************************************
Àrbol de cubrimiento mínimo: Conjunto mín de aristas, para no perder conectividad y la suma de los costos de esas aristas sea el minimo.
Agrega vértices que no pertenecen a la sol y otro sque si.

//supondremos grafos no dirigidos en nuestro curso.

Aplicaciones:

Dada una red de saneamiento y quiero minimizar los metros de metros de tubería que necesito para
Fibra óptica, electríca, metros de carretera, etc.

CaminoMasBarato
*****************************************************/

void Prim (Matriz<int> g){
	//PRE: Grafo conexo y no dirigido.
	ColaPrioridad<nat, int> cola = new ColaHeap<nat,int>(g.Largo);
	Array<int> costo(g.Largo, INF);
	Array<nat> anterior(g.Largo, -1);
	
	for (nat i = 0; i<g.Largo; i++)
	    cola->Encolar(i,costo[i])
	
	while (!cola->EstaVacia()){
		nat v = cola->ObtenerMin();
		cola->EliminarMin();
		
		for (nat a = 0; a<g.Largo; a++){
			if (g[v][a] != INF) //si es adyacente
				if ((cola->Pertenece(a) && (g[v][a] < costo[a]){
					anterior[a] = v;
					costo[a] = g[v][a];
					cola->CambiarPrioridad(a,costo[a]);
				}
			}
		}
	}
	
	cout << "Arcos que forma el arbol de cubrimiento minino: "
	for (nat i=0; i<g.Largo; i++){
		if (anterior[i] != -1){
			cout << anterior[i] << " -> " << i;
		}
	}
}
-------------------------
struct nodoP{
	V v;
	nat ant;
	A arco;
	bool conectado; //visitado
};

Array<nodoP> Prim (Puntero<Grafo<V,A>> g){
	Array<nodoP> tabla (g->CantVertices()+1);//suma 1 para no usar la pos 0
	nat pos = 1;
	
	foreach(v, g->ObtenerVertices()){
		tabla[pos].v = v;
		tabla[pos].ant = 0;
		tabla[pos].conectado = false;
	}
	
	pos = 1; //supongo un origen
	
	while (pos > 0){
		tabla[pos].conectado = true;
		for (nat i=1; i< tabla.Largo; i++){ //recorro adyacentes y verifico si q exista arco entre vertices
			if (tabla[i].conectado) continue;
			if (g->ExisteArco(tabla[pos].v, tabla[i].v)){
				A arco = g->ObtenerArco(tabla[pos].v, tabla[i].v); //Cambiando esta linea el algoritmo es dijkstra!!! VER!!!
				if (tabla[i].ant == 0 || arco < tabla[i].arco){
					tabla[i].arco = arco;
					tabla[i].ant = pos;
				}
			}
		}
		pos = BuscarMenorNoConectado(tabla);
	}
	
	return tabla;
}

nat BuscarMenorNoConectado(Array<nodoP> tabla){
	nat pos;
	for (nat i = 1; i<tabla.Largo; i++){
		if (!tabla[i].conectado && (pos == 0 || tabla[i].ant > 0 && tabla[i].arco < tabla[i].arco))
			pos = i;
	}
	return pos;
}

