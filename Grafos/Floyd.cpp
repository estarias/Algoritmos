/*****************************************************
Devuelve una matriz con las distancias minimas de cada nodo al resto de los vertices.

Es un algoritmo de programaicón dinámica.

*****************************************************/

Matriz<int> floyd(Matriz<int> g){
	Matriz<int> m(n);
    
    for(nat i = 0; i < n; i++)
		for(nat j = 0; j < n; j++)
			m[i][j] = g[i][j];
 
    for(nat k = 0; k < n; k++)
        for(nat i = 0; i < n; i++)
            for(nat j = 0; j < n; j++){
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


void floydCamino(Matriz<int> g, int o, int d){
	Matriz<int> m(n);
	Matriz<int> c(n);
    
    for(nat i = 0; i < n; i++)
		for(nat j = 0; j < n; j++){
			if (i == j) 
				m[i][i] = 0;
			else
				m[i][j] = g[i][j];
			c[i][j] = -1;
		}
 
    for(nat k = 0; k < n; k++)
        for(nat i = 0; i < n; i++)
            for(nat j = 0; j < n; j++){
                int dt = m[i][k] + m[k][j];
                if (dt < m[i][j]){
                    m[i][j] = dt;
					c[i][j] = k;
				}
            }
 
    cout << "menor costo es:"  << m[o][d];

	cout << "El camino es:"  << endl;
	mostrarCamino(o,d,c);
}

void mostrarCamino(int o, int d, Matriz<int> c){
	int k=c[o][d];
	if(k!=-1){
		mostrarCamino(o,k,c);
		cout << k;
		mostrarCamino(k,d,c);
	};
}