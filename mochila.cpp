////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Hay dos versiones de mochilas: las q se pueden repetir eltos y las que no se pueden repetir elementos.
Elementos son las lineas, q tienen un precio y una distTotal. Tambien tengo dineroMax. Las lineas no se pueden repetir. 

* Sabores:
** MochilaDinamica 
** MochilaMem 
** MochilaGredy 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dividir para conquistar
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int mochilaB(int c,int n,Array<int> valor,Array<int> peso){
    if(c==0) return 0;
    if(C<0) return -INFINITO;
    if(c>=0 && n<0) return 0;

    return maxDe3(mochilaB(c - peso[n],n-1,valor,peso) + valor[n],
                mochilaB(c,n-1,valor,peso),
                0);
				
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila dinamica
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mochilaDinamica(Array<int> peso, Array<int> valor, int n, int c){
	
	Matriz<int> m(n,c+1);
	int i, j;
	
	for(i=0;i<n;i++) m[i][0]=0;
	for(i=0;i<c+1;i++) m[0][i]=0;	

	for(i=1; i<n; i++){
		for(j=1;j<c+1;j++){
			if(j < peso[i])
				m[i][j] = m[i-1][j];
			else
				m[i][j] = max(m[i-1][j], valor[i] + m[i-1][j-peso[i]]);
		}
	}

	i = n-1;
	j = c;
	
	while(i>0 && j>0){
		if (j >= peso[i] && m[i][j] == valor[i] + m[i-1][j-peso[i]]){
			cout << "Utilizo elemento: " << i << endl;
			j -= peso[i];
		}		
		i--;
	}

	cout << "Valor Óptimo " << m[n-1][c];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila Backtracking
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mochilaBacktracking(Puntero<Lista<Puntero<Item>>> items, int peso, 
						Puntero<Lista<Puntero<Item>>> &solActual, Puntero<Lista<Puntero<Item>>> &mejorSol, 
						int valor, int &mejorValor){

	//CASO BASE
	if (items->EstaVacia()){ 
		if(mejorValor < valor){
			mejorValor = valor;
			mejorSol = solActual->Clonar();
		}
		return;
	}

	Puntero<Item> it = items->Primero();
	
	items->BorrarPrimero();
	for (int k = 0; k<=1 && it->ObtenerPeso()*k <= peso; k++){ // 0 o 1, va a ser mi k en este caso. 
		if(k > 0)
			solActual->Agregar(it);
		mochilaBacktracking(items, peso - it->ObtenerPeso()*k, solActual, mejorSol, valor + it->ObtenerValor()*k, mejorValor);
		if(k > 0)
			solActual->Borrar(it);
	}
	items->Agregar(it);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila MEM
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Matriz<int> bdMochila(N,capacidad);

void inicializoMochila(){
	for(int c=0;c<N;o++)
		for(int c=0;c<capacidad;c++)
			bdMochila[o][c]=NULL;
};
bool fueCalculadoMochila(int n,int c){
	return bdMochila[n][c]!=NULL;
};

int MochilaMem(int capacidad, int N, Array<int>valor, Array<int>peso){
	if(capacidad==0)return 0;
	if(capacidad<0)return -INFINITO;
	if(capacidad>=0 && N<0) return 0;
 
	if(!fueCalculadoMochila(N,capacidad)){
		if(capacidad==0)
			bdMochila[N][capacidad] = 0;
		else
			bdMochila[N][capacidad] = maxDe3(valor[N]+ MochilaMem(capacidad- peso[N],N-1,valor,peso),
											MochilaMem(capacidad,N-1,valor,peso),
											0);
	};
	
	return bdMochila[capacidad][N];
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila Dinamica con cantidad de elementos disponibles 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Prod{
	nat valor;
	nat cantidad;
	
	Prod(){
		valor = 0;
		cantidad = 0;
	}
	
	Prod(nat v, nat c){
		valor = v;
		cantidad = c;
	}
}

Array<nat> MochilaDinamicaElementosRepetidos(Array<nat> peso, Array<nat> valor, Array<nat> cantidad, nat n, nat c){
	Matriz<Prod> m (n, c+1);
	//la matriz ya esta inicializada porque hice los constructores de prod.
	
	for (nat i=1; i<n;i++){
		for (nat j=1; i<c+1;j++){
			if (j < peso[i]){
				m[i,j] = Prod(m[i-1][j].valor, 0);
			}else{
				nat val1 = cantidad[i] > 0 ? valor[i] + m[i-1][j-peso[i]].valor : 0; //aplana un if. 
				nat cant = m[i][j-peso[i]].cantidad;
				nat val = m[i][j-peso[i]].valor;
				
				if (val < cantidad[i]){
					cant++;
					val+= valor[i];
				}
				
				m[i][j] = Prod(m[i-1][j].valor, 0);
				if (m[i][j].valor < val1) m[i][j]= Prod(val1, 1);
				if (m[i][j].valor < val) m[i][j]= Prod(val, cant);				
			}
		}
	}
	
	//armar la solucion
	Array<nat> res (n, 0); //voy a retornar, cuantos elementos voya tener de cada tipo en la mochila.
	nat i = n-1;
	nat j = c;
	
	while (i>0 && j >0){
		res[i] = m[i][j].cantidad;
		j -= res[i]*peso[i];
		i--;
	}
	
	return res;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila Backtracking con cantidad de elementos disponibles 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MochilaBacktrackingElementosRepetidosEx(Array<Item> items, nat c, nat it, 
											Array<nat> cantActual, Array<nat> cantMejor
											nat valorActual, nat & mejorValor){
	if (it == items.Largo){
		if (valorActual > mejorValor){
			mejorValor = valorActual;
			Array<nat>::Copiar(cantActual, cantMejor);
		}
	}else{
		for(nat k=0; k<=items[it].cantMax && k*items[it].peso <= c; k++){
			cantActual[it] = k; //Agregar 
			MochilaBacktrackingElementosRepetidosEx(items, c - k*items[it].peso, it + 1, 
													cantActual, cantMejor,
													valorActual + k*items[it].valor, mejorValor);
			cantActual[it]=0; //Borrar
		}
	
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
nat costoMin(nat i, nat j, nat k){
	if (i==j) return 0;
	if (k==0) return m[i][j];
	return min(costoMin(i,k,k-1)+costoMin(k,j,k-1), costoMin(i,j, k-1));
}


nat costoMin (nat origen, nat destino, nat n, Matriz<nat> g){
	Matriz<nat> m(n,n, 0);
	//for (int i=1, i<n; i++) C[i][i] = 0;
	
	for (nat i= 1; i<n; i++)
		for (nat j= 1; j<n; j++){
			nat temp = INF;
			for (int k= origen+1; k<n;k++)
				temp := min(temp, g[origen][k] + C[k][destino]);
            m[i][j] = temp;
		}
	return C[n][n];
}
