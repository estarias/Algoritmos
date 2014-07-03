/*****************************************************
Devuelve una matriz con las distancias minimas de cada nodo al resto de los vertices.
*****************************************************/

Matriz<int> floyd(Matriz<int> g){
	Matriz<bool> m(CANT);
    
    for(nat i = 0; i < CANT; i++)
		for(nat j = 0; j < CANT; j++)
			if (i == j) 
				m[i][i] = 0;
			else
				m[i][j] = g[i][j];
 
    for(nat k = 0; k < CANT; k++)
        for(nat i = 0; i < CANT; i++)
            for(nat j = 0; j < CANT; j++){
                int dt = m[i][k] + m[k][j];
                if (dt < m[i][j])
                    m[i][j] = dt;
            }
 
    return m;
}

bool existeCamino(Matriz<int> g, nat o, nat d){
    Matriz<int> camino = floyd(g);
    return camino[o][d] != INF;
}

int MenorCoosto(Matriz<int> g, nat o, nat d){
	Matriz <int> m = Floyd(g);
	return m[o][d];
}