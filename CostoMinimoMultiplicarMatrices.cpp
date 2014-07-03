//Costo minimo de multiplizar matrices
N matrices (0..N-1)
Array<nat> dimensiones(N+1)
Filas(i) = dimensiones[i]
Columnas(i) = dimensiones[i+1];
FCosto (A.B) = filas(A) * columnas(A) * columnas(B);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
O(n^3)
nat CostoMinimoDin(Array<nat> dimensiones){
	nat N = dimensiones.Largo -1;
	Matriz<nat> cm (N);
	for(nat j=0; j<N;j++){
		for(nat iaux=j+1,i=j; iaux>o; iaux--,i--){
			if (i==j) 
				cm[i][j] =0;
			else{
				nat min = INF;
				for (nat k=i; k<j; k++){
					nat aux = cm[i][k] + cm[k+1][j] + Filas(i)*Columnas(k)*Columnas(j);
					if (aux<min) min=aux;
				}
				cm[i][j] = min;
			}
		}
	}
	return cm[0][N-1];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dividir para conquistar
nat costoMinMultiplicar(Array<nat> dimensiones, nat i, nat k){
	if (i==k) 
		return 0;
	else{
		nat min = INF;
		for (nat j = i; j < k; j++){
			nat aux = costoMinMultiplicar(dimensiones, i, j) + 
						costoMinMultiplicar(dimensiones, i, j) + 
							filas(dimensiones, i) * columnas(dimensiones, j) * columnas(dimensiones, k);
			if (aux < min)
				min = aux;
		}	
		return min;	
	}
}
nat filas(nat i){ //devuelve cantidad de filas
	return dimensiones[i];
}
nat columnas(nat i){ //devuelve cantidad de columnas
	return dimensiones[i+1];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////