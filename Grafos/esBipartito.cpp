/*Grafo Bi partito
si estan en la misma clase, no tienen arcos entre si.

recorre en amplitud, y los niveles pares son una clase y los impares otra.
no es bipartito, cuando la lista ya esta en un grupo y ese grupo es el mismo que yo.

*/

bool EsBipartito_Ej24(Matriz<bool> g ){
	Puntero<Cola<nat>> niveles=...();
	niveles -> Encolar(0);
	
	Array<nat> clases(N); //dado un vertice me dice en q clase esta: 0 no tiene clase(no visitado), 1 es calse 1, 2 es clase 2
	clases[0] = 1;
	
	while(!niveles->EsVacia()){
		nat actual = niveles->Desencolar();
		for (int i=0;i<g.Largo, i++){
			if (g[actual][i]){//si es adyacente
				if (clases[actual]==clases[i])//esta en la misma clase return False;
			}
			if (clases[i]==0){
				clases[i]=(clase[actual]==1) ? 2:1; //si calse acutal es 1, pone 2, sino pone 1.
				niveles->Encolar(i);
			}
		}
	}
	return True;
}