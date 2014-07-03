void DFS (Puntero<Grafo<V,A>> &g, Array<bool> visitados, Puntero<Tabla<V,nat>> tablaVertices, const v& actual){ //la tabla me sirve para el mapeo de id a partir del vertice

    nat pos = this->tablaVertices->Obtener(actual);
    if (!visitado[pos]) cout<< w;
    foreach(w, g->ObtenerAdyacentes()) DFS(g, visitados, tablaVertices, w);
    
}


