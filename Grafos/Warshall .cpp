//Dice si hay una forma de ir de un vertice  a otro. 
//Es un algoritmo de programaicón dinámica.

/****************************************************
Clausura transitiva
Para todo x,y,z que pertenecen a V, 
Si hayCamino(x,y) y hayCamino(x,y) entonces: hayCamino (x,z)

/****************************************************/

Matriz<bool> Warshall(Matriz <bool> g){
    Matriz<bool> m(n);
 
    for(nat i = 0; i < n; i++)
		for(nat j = 0; j < n; j++)
			m[i][j] = g[i][j];
 
    for(nat k = 0; k < n; k++)
        for(nat i = 0; i < n; i++)
            for(nat j = 0; j < n; j++)
				if (!m[i][j])
					m[i][j] = m[i][k] && m[k][j]
	return m;
}

/*****************************************************/
Determina si existe camino de un vertice a otro
/*****************************************************/
bool existeCamino(Matriz<bool> g, int o, int d){
    Matriz<bool> m = Warshall(g);
    return m[o][d];
}

/*****************************************************/
Determina si un grafo es debilmente conexo
/*****************************************************/
bool esDebilmenteConexo(Matriz<bool> g){
    Matriz<bool> m(n);
 
    //copio el grafo, y lo hago no dirigido
    for(nat i = 0; i < n; i++)
		for(nat j = 0; j < n; j++){
			m[i][j] = grafo[i][j];
            if (m[i][j])
				m[j][i] = true;
		}

    //plico warshall y verifico si M es completa
    return esCompleta(m);
}

/*****************************************************/
Determina si un grafo es conexo
/*****************************************************/
bool esConexo(Matriz<bool> g){ //O sea, puedo llegar de cualquier vértice a cualquier vérticie (ver)
    if esCompleta(Warshall(g)) return true; //Si esta toda llena
}

void esConexo(){
	if esCompleta(Warshall(m)) cout << "Es fuertemente conexo";
	if esDebilmenteConexo(Matriz<bool> g) cout << "Es debilmente conexo";
	cout << "No es conexo";
}

