nat GrafoImp::cantComponentesConexas(Matriz<Puntero<Arista>> aux){
	Array<SetImp<Puntero<CiudadImp>>> conjuntos = Array<SetImp<Puntero<CiudadImp>>>(cantCiudades);
	nat cantMaxAristas = (cantCiudades * (cantCiudades - 1)) / 2;
	ColaPImp cp = ColaPImp(cantMaxAristas);
	nat costoMin = 0;
	for (nat x = 1; x < cantCiudades; x++){
		conjuntos[x] = SetImp<Puntero<CiudadImp>>(cantCiudades);
		conjuntos[x].Insertar(arrayV[x]);
	} 
	Matriz<Puntero<Arista>> resultado = Matriz<Puntero<Arista>>(cantCiudades);
	//Cargo los vertices en el Set
	for (nat f = 1; f < cantCiudades; f++){
		for(nat c = 1; c < cantCiudades; c++){
			if (aux[f][c] != NULL){
				cp.Insertar(aux[f][c], aux[f][c]->costo);
			}
		}
	}
	nat compConexas = 0;
	bool fin = cp.EsVacia();
	while(!fin){
		Puntero<Arista> a = cp.Min();
		cp.BorrarMin();
		nat origen = BuscarVertice(conjuntos, a->cOrigen);
		nat destino = BuscarVertice(conjuntos, a->cDestino);
		nat coordenadaX = tablaV->ObtenerElemento(a->cOrigen);
		nat coordenadaY = tablaV->ObtenerElemento(a->cDestino);
		if (origen != 0 && destino != 0){
			if (origen != destino){
				resultado[coordenadaX][coordenadaY] = a;
				conjuntos[origen].Union(conjuntos[destino]);
				conjuntos[destino].Vaciar();
			}
			fin = cp.EsVacia() || conjuntos[origen].getCantidadElementos() == cantCiudades;
		}
	}
	for(nat i=1; i<conjuntos.Largo(); i++){
		if(!conjuntos[i].EsVacio()){
			compConexas++;
		}
	}
	return compConexas;