void minimax(int * v, int izq, int der, int & m, int & M){
	int mI, mD, MI, MD, medio;
	if (der - izq == 1){ //si tiene dos elementos
		if (v[izq] < v[der])
			m = v[izq]; M = v[der];
		}else{
			M = v[izq]; m = v[der];
	}else{
		if (izq == der){
			m = v[izq]; M=v[izq];
		}else{
			//mas de dos elementos : problema dificil
			medio = (izq+der)/2; //division el problema
			minimax(v, izq, medio, mI, MI); //resolución sub promlema
			minimax(v, medio+1, der, mD, MD); //resolución sub promlema
			m = min(mI, mD); //combinaicon de las soluciones
			M = max(MI, MD); //combinaicon de las soluciones
		}
	}
}