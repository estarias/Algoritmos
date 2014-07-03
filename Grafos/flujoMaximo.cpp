/*
Grafos dirigidos.

Dada una red, (ej de computadoras, de tránsito, cañerías, etc.)

Ej capacidad de desagotar el agua de las lluvias de la calles que van por cañería. Cuánto tiene que llover para que se inunden las calles?

El resultado, la suma de la suma de los arcos que salen, dbee dar igual a la suma de los arcos que entran. del origen al destino.
*/

Ford-Fulkerson

//Grafo resultado
//Grafo residual


//En el obl debo acumular las densidades de los tramos, de una estacion a otra.

nat FlujoMaximo(Grafo * g, s, t){ //OJO!!! g, lo modifica, por lo tanto debo pasar una copia
	nat flujo = 0;
	Iterador it = BuscarCamino(g, s, t); //iterador de los tramos  recorrida en profundiad o amplitud.
	while (it.HayElementos()){
		nat f = capacidadMaxima(it);
		flujo+=f;
		//it.Reiniciar();
		//it.Avanzar();
		para cada tramo (v,w) en it
		g(v,w) -= f;
		g(w,v) += f;
		it = BuscarCamino(g,s,t)
	}
	
	return flujo;
}

// Retorna el maximo del grafo desde el destino origen hasta destino
template <class V, class A, typename FHashV>
int GrafoMatrizAdy<V,A,FHashV>::fordFulkerson(int origen, int destino) const {
	for (nat i=0; i<this->matriz.Largo; i++) {
		for (nat j=0; j<this->matriz.Largo; j++) {
			matrizFlujo[i][j]=matriz[i][j];
		}
	}
	
	int u, v;

       for (nat k=0; k<this->matriz.Largo; k++) {
               for (nat y=0; y<this->matriz.Largo; y++) {
				   if(this->matriz[k][y]!=NULL){
                       Iterador<Puntero<Tramo>> arcos = this->matriz[k][y]->lista->ObtenerIterador();
                       nat densidadTotal = 0;
                       foreach(a, arcos){
                               densidadTotal += a->ObtenerDensidad();
                       }
                       matrizDensidades[k][y] = densidadTotal;
				   }
               }
       }


	Array<int> parent(this->matriz.Largo); 
    int max_flow = 0; 

	
	while (this->bfs(origen, destino, parent))
    {
		  int path_flow = INT_MAX;
          for (v=destino; v!=origen; v=parent[v])
          {
              u = parent[v];
              path_flow = min(path_flow , matrizDensidades[u][v]);
          }

          for (v=destino; v != origen; v=parent[v])
		  {
                u = parent[v];
				matrizDensidades[u][v]-= path_flow;
				matrizDensidades[v][u]+= path_flow;
		   }
		max_flow += path_flow;

	}
	 return max_flow;
}
