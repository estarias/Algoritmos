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
int mochilaB(int capacidad,int N,Array<int> valor,Array<int> peso){
    if(capacidad==0) return 0;
    if(capacidad<0) return -INFINITO;
    if(capacidad>=0 && N<0) return 0;

    return maxDe3(mochilaB(capacidad- peso[N],N-1,valor,peso) + valor[N],
                mochilaB(capacidad,N-1,valor,peso),
                0);
				
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila dinamica
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mochilaDinamica(Array<int> peso, Array<int> valor, Array<int> elemento, int n, int c){
	nat n = elemento.Largo;
	
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
			//otra forma igual:
			//m[i][j] = j < peso[i] ? m[i-1][j] : max(m[i-1][j], valor[i] + m[i-1][j-peso[i]]);
		}
	}

	i = n-1;
	j = c;
	
	while(i>0 && j>0){
		if (j >= peso[i] && m[i][j] == valor[i] + m[i-1][j-peso[i]]){
			cout << "Utilizo elemento: " << i << endl;
			j = j - peso[i];
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
struct Item{
	nat peso;
	nat valor;
	nat cantMax;
}

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

Array<nat> MochilaDinamicaElementosRepetidos(Array<Item> items, nat capacidad){
	Matriz<Prod> pr (items.Largo, capacidad+1);
	
	//la matriz ya esta inicializada porque hice los constructores de prod.
	
	for (nat i=1; i<items.Largo;i++){
		for (nat j=1; i<=capacidad;j++){
			if (j < items[i].peso){
				pr[i,j] = Prod(pr[i-1][j].valor, 0);
			}else{
				nat val1 = items[i].cantMax > 0 ? items[i].valor + pr[i-1][j-items[i].peso].valor : 0; //aplana un if. //hasta acá es igual q la mochila vieja.
				nat cantidad = pr[i][j-items[i].peso].cantidad;
				nat valI = pr[i][j-items[i].peso].valor;
				
				if (valI < items[i].cantMax){
					cantidad++;
					valI+= items[i].valor;
				}
				
				pr[i][j] = Prod(pr[i-1][j].valor, 0);
				if (val1 > pr[i][j].valor)
					pr[i][j]= Prod(val1, 1);
				if (valI > pr[i][j].valor)
					pr[i][j]= Prod(valI, cantidad);				
			}
		}
	}
	
	//armar la solucion
	Array<nat> res (items.Largo, 0); //voy a retornar, cuantos elementos voya tener de cada tipo en la mochila.
	nat i = items.Largo;
	nat j = capacidad;
	
	while (i>0 && j >0){
		i--;
		res[i] = pr[i][j].cantidad;
		j -= res[i]*items[i].peso;
	}
	
	return res;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila Backtracking con cantidad de elementos disponibles 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Arra<nat> MochilaBacktrackingElementosRepetidos(Array<Item> items, nat capacidad){

	Array<nat> cantActual(items.Largo, 0);
	Array<nat> cantSol(items.Largo, 0);
	nat mejorValor = 0;

	MochilaBacktrackingElementosRepetidosEx(items, capacidad, cantActual, 0, cantSol, mejorValor);

	return catnSol;
}

void MochilaBacktrackingElementosRepetidosEx(Array<Item> items, nat capacidad, nat it, 
											Array<nat> cantActual, nat valor, 
											Array<nat> cantSol, nat & mejorValor){
	if (it == items.Largo){
		if (valor > mejorValor)
			mejorValor = valor;
			Array<nat>::Copiar(cantActual, cantSol);
		}
		return;
	}

	for(nat k=0; k<=items[it].cantMax && k*items[it].peso <= capacidad; k++){
		cantActual[it] = k; //Agregar 
		MochilaBacktrackingElementosRepetidosEx(items, capacidad - k*items[it].peso, it + 1, 
												cantActual, valor + k*items[it].valor, 
												cantSol, mejorValor);
		cantActual[it]=0; //Borrar
	}
	
	
}

