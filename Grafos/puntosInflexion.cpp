Puntero<ListaImp<pCiudad>> GrafoImp::EstacionesCriticas(){
	Puntero<ListaImp<pCiudad>> retorno = new ListaImp<pCiudad>();
	Matriz<Puntero<Arista>> auxiliar = Matriz<Puntero<Arista>>(cantCiudades);

	ReinicioMat(auxiliar);
	nat cantConexasAnt = 0;
	cantConexasAnt = CantComponentesConexas(auxiliar); //a = número de componentes en G

	for(nat k=1; k<cantCiudades; k++){//para cada i en V con aristas incidentes
		for(nat m=1; m<cantCiudades ; m++){
			auxiliar[m][k] = NULL; //eliminar i de V
			auxiliar[k][m] = NULL;
		}
		nat cantConexasAct = 0;
		cantConexasAct = CantComponentesConexas(auxiliar); //b = número de componentes en G con i eliminado
		nat diferencia = cantConexasAct-cantConexasAnt; //si b > a
		if(diferencia > 1){
			Puntero<CiudadImp> ciudad = arrayV[k]; //i es un vértice de corte
			pCiudad c = ciudad;
			retorno->AgregarFin(c);
		}
		ReinicioMat(auxiliar); //restaurar i
	}
	return retorno;
}