//Grafos dirigidos y acíclicos. 
//Aplicaiones:
//* Previaturas de asignaturas de una carrera
//* Flujo de trabajo de un proyecto o proceso. (relevar req, analizar, diseñar, desarrollar, test, etc.)

void imprimirTopologico(Grafo<V,A> g){
	Puntero<Tabla<V,nat>> grados = new TablaHashAbierta<V,nat>(fhash, g->CantVertices());
	Puntero<Cola<V>> cola = new ColaImp<V>();
 
	//inicializamos la tabla con los grados de entrada y en la cola los que no tienen incidentes
	foreach(v, g->ObtenerVertices()){
		nat ge = g->CantIncidentes(v);
		if (ge == 0)
			cola->Encolar(v);
		else
			grados->Agregar(v,ge);
	}
 
	nat procesados = 0;
	while(!cola->EsVacia()){
		procesados++;
		V v = cola->Desencolar();
		cout << v;

		foreach (a, g->Adyacentes(v)){
			nat ge = grados->Obtener(a) - 1;
			if (ge == 0)
				cola->Encolar(a)
			else
				grados->Agregar(a,ge);
		}
	}
 
	if (procesados > g->CantVertices()):
        cout << "Tiene ciclos";
    else
        cout << "OK";
}
