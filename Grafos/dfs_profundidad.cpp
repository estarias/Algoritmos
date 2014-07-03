void DFS(int v){
	marcado[v] = true;
	for (int i=0; i<CANT_VERTICES; i++)	
		if (grafo[v][i] && !marcado[i]) //si es adyacente y no es conocido
			DFS(i);
}

void main(){
	for (int i=0; i<CANT_VERTICES; i++)
		marcado[i] = false;
	for (int i=0; i<CANT_VERTICES; i++)
		if (!marcado[i]) DFS(i);
}


bool esCiclico(Array conocidos, int actual, grafo):
    conocidos[actual] = true
    for a in adyacentes(actual):
        if (conocido[a]) 
            return true;
        else
            return esCiclico(a)