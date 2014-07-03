void imprimirPorNivelRecorridaAmplitud(Puntero<Grafo<V,A>> &g, const V &origen){
    Puntero<Cola<Nivel<v>>> niveles = new... ();
    niveles->Encolar(new Nivel<V> (origen, 0));

    while(!niveles->EsVAcia()){
		Nivel n = niveles->Desencolar();
		cout << n.Nivel << " - " << n.V ;
		foreach(w, g->Adyacentes(v)){
			niveles->Encolar(new Nivel<V>(n.Nivel+1, w));
		}
    }
}