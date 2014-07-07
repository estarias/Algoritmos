//Costo minimo de multiplizar matrices
N matrices (0..N-1)
Array<nat> dimensiones(N+1)
Filas(i) = dimensiones[i]
Columnas(i) = dimensiones[i+1];
FCosto (A.B) = filas(A) * columnas(A) * columnas(B);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
O(n^3)
nat CostoMinimoDin(Array<nat> dim){
	nat N = dim.Largo -1;
	Matriz<nat> m (N);
	for(nat j=0; j<N;j++){
		for(nat iaux=j+1,i=j; iaux>o; iaux--,i--){
			if (i==j) 
				m[i][j] =0;
			else{
				nat min = INF;
				for (nat k=i; k<j; k++){
					nat aux = m[i][k] + m[k+1][j] + fil(i)*col(k)*col(j);
					if (aux<min) min=aux;
				}
				m[i][j] = min;
			}
		}
	}
	return m[0][N-1];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dividir para conquistar
nat costoMinMultiplicar(Array<nat> dim, nat i, nat k){
	if (i==k) return 0;
	nat min = INF;
	for (nat j = i; j < k; j++){
		nat aux = costoMinMultiplicar(dim, i, j) + 
					costoMinMultiplicar(dim, i, j) + 
						fil(dim, i) * col(dim, j) * col(dim, k);
		if (aux < min) min = aux;
	}	
	return min;	
}
nat fil(nat i){ //devuelve cantidad de filas
	return dim[i];
}
nat col(nat i){ //devuelve cantidad de columnas
	return dim[i+1];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////