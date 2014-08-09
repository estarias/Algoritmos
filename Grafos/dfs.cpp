O(|V|+|A|)

bool existeCamino(nat o, nat d) {
	Array<bool> visitado (n, false);
	return dfs(o, d, visitado);
}

bool dfs( nat o,  nat d, Array<bool> &visitado) {
	if (o == d) return true;

	for (nat i, i<n,i++){
		if (g[o][i]){ //si es adyacente
			if (!visitado[i]){
				visitado[i]=true;
				if (dfs(i, d, visitado)) return true;
			}
		}
	}

    return false;
}

//No estoy seguro...:
bool esCiclico(Array<bool> visitado, int actual, Matriz<bool> g){
    visitado[actual] = true;
    for (nat i, i<n,i++){
		if (g[actual][i]){ //si es adyacente
			if (visitado[a])
				return true;
			else
				return esCiclico(i);
		}
	}
}