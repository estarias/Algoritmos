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
nat Sistema::mochilaDinamica(Array<int> peso, Array<int> valor, Array<int> elemento, int n, int c, Puntero<Lista<pLinea>> &sol){

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
			int nroLinea = elemento[i];
			sol->AgregarFin(arrayLineas[nroLinea]);
			j = j - peso[i];
		}		
		i--;
	}

	return m[n-1][c];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila Backtracking
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sistema::mochilaBacktracking(Puntero<Lista<Puntero<Item>>> items, int peso, Puntero<Lista<Puntero<Item>>> &solActual, Puntero<Lista<Puntero<Item>>> &mejorSol, int valor, int &mejorValor){

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
	nat costo;
	nat ganancia;
	nat cantMax;
}

struct Prod{
	nat ganancia;
	nat cantI;
	
	Prod(){
		ganancia = 0;
		cantI = 0;
	}
	
	Prod(nat g, nat c){
		ganancia = g;
		cantI = c;
	}
}

Array<nat> MochilaDinamicaElementosRepetidos(Array<Item> items, nat capital){
	Matriz<Prod> pr (items.Largo, capital+1);
	
	//la matriz ya esta inicializada porque hice los constructores de prod.
	
	for (nat i=1; i<items.Largo;i++){
		for (nat c=1; i<=capital;c++){
			if (c < items[i].costo){
				pr[i,c] = Prod(pr[i-1][c].ganancia, 0);
			}else{
				nat gan1 = items[i].cantMax > 0 ? items[i].ganancia + pr[i-1][c-items[i].costo].ganancia : 0; //aplana un if. //hasta acá es igual q la mochila vieja.
				nat cantI = pr[i][c-items[i].costo].cantI;
				nat ganI = pr[i][c-items[i].costo].ganancia;
				
				if (ganI < items[i].cantMax){
					cantI++;
					ganI+= items[i].ganancia;
				}
				
				pr[i][c] = Prod(pr[i-1][c].ganancia, 0);
				if (gan1 > pr[i][c].ganancia)
					pr[i][c]= Prod(gan1, 1);
				if (ganI > pr[i][c].ganancia)
					pr[i][c]= Prod(ganI, cantI);				
			}
		}
	}
	
	//armar la solucion
	Array<nat> res (items.Largo, 0); //voy a retornar, cuantos elementos voya tener de cada tipo en la mochila.
	nat i = items.Largo;
	nat c = capital;
	
	while (i>0 && c >0){
		i--;
		res[i] = pr[i][c].CantI;
		c -= res[i]*items[i].costo;
	}
	
	return res;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mochila Backtracking con cantidad de elementos disponibles 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Arra<nat> MochilaBacktrackingElementosRepetidos(Array<Producto> productos, nat capital){

	Array<nat> cantActual(productos.Largo, 0);
	Array<nat> cantSol(productos.Largo, 0);
	nat ganSol = 0;

	MochilaBacktrackingElementosRepetidosEx(productos, capital, cantActual, 0, cantSol, ganSol);

	return catnSol;
}

void MochilaBacktrackingElementosRepetidosEx(Array<Producto> productos, nat capital, nat p, Array<nat> cantActual, nat ganActual, Array<nat> cantSol, nat & ganSol){
	if (p==productos.Largo){
		if (ganActual > ganSol)
			ganSol = ganActual;
			Array<nat>::Copiar(cantActual, cantSol);
		}
	}else{
		for(nat i=0; i<=productos[p].cantMax; i++){
			nat costoI = i*productos[p].costo;
			if (costoI <= capital){
				cantActual[p] = i;
				MochilaBacktrackingElementosRepetidosEx(productos, capital - costoI, p+1, 
							cantActual, ganActual+i*productos[p].valor, cantSol, ganSol);
				
				cantActual[p]=0;
			}else{
				break;
			}
		}
	}
	
}

