///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
monedas disponibles

dado un monto, retornar el cambio necesario para devolver la cantidad minima de monedas

*/

//Array de tipos de monedas (de 1, 2, 5, 10, 50 por ej) asumo q estan ordenadas de menor a mayor (ordenadqs por valor)
//Array de cuantas moendas de ese tipo tengo
//Solucion con divide and conquer
Array<nat> DarCambio(Array<nat> monedas, nat monto){
	Array<nat> usadas(monto.Largo, 0);
	DarCambioDivideAndConquer(monedas, monto, usadas, 0); //monedas.Largo-m-1
	return usadas;
}

void DarCambioDivideAndConquer(Array<nat> monedas, nat monto, Array<nat> usadas, nat m){
	//como estan ordenadas de menor a mayor, tomo la mas grande, y hago mientras me sirva para dar cambio, la doy. 'm' es el tipo de moneda. (pos del array)
	if (monto == 0 || m==monedas.Largo) return;
	nat pos = monedas.Largo - m -1;
	nat cant = monto / monedas[pos]; // es una division entera. me devuelve  la cantidad de monedas que necesito.
	usadas[pos] = cant;
	monto = monto % monedas[pos];
	DarCambioDivideAndConquer(monedas, monto, usadas, m+1);
}
//No resuelve la cantidad minima, porque voy a usar todos los tipos de monedas.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*SOLUCION CON PROGRAMACION DINAMICA
Debo ver en que orden cargar las estructuras, para no repetir calculos.
	filas: cantidad de monedas
	columnas: monto a devolver

	calculo para cada tipo de moneda, como puedo dar el cambio, comparando la soluciones
*/

Array<nat> DarCambioDin(Array<nat> monedas, nat monto){
	Matriz<nat> m(monedas.Largo, monto+1);
	
	for (nat i=0; i<monedas.Largo; i++){
		for (nat j=0; i<=monto; j++){
			if (i==0)
				m[0][j] = j/monedas[0];
			else if(j< monedas[i])
				m[i][j] = m[i-1][j];
			else
				m[i][j] = Min(m[i-1][j], 1+m[i][j-monedas[i]]);
		}
	}
	
	Array<nat> usadas(monedas.Largo, 0);
	nat i = 0;
	nat j = monto;
	while (j>0){
		nat pos = monedas.Largo - i - 1;
		if (pos > 0 && m[pos][j] == m[pos-1][j]){ //no utilicé esta moenda
			i++;
		}else if(j >= monedas[pos]){  //usé esta moenda, o el monto es inferior al valor de la moneda
			j -= monedas[pos];
			usadas[pos]++;
		}else{ //
			break;
		}			
	}
	
	return usadas;
}

nat Min(nat x, nat y){
	return x<y ? x:y;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
///
/// DAR CAMBIO MEMORIZACION
////////////////////////////////////////////////////////////////////////////////
#define CANT_MAX 1500
#define MON_HASTA 10
int * bdCambio[CANT_MAX][MON_HASTA];

void inicializoBDCambio(){
	for(int c=0;c<CANT_MAX;c++)
	for(int m=0;m<MON_HASTA;m++)
	bdCambio[c][m]=NULL;
};
bool fueCalculado(int cantAPagar,int monedaHasta, int * bd[CANT_MAX][MON_HASTA]){
	return bd[cantAPagar][monedaHasta]!=NULL;
};
int cambioMem(int cantAPagar,int monedaHasta,int * valorMoneda, int * bd[CANT_MAX][MON_HASTA]){
	if(cantAPagar<0 || monedaHasta <0) return INFINITO;
	if(!fueCalculado(cantAPagar,monedaHasta,bd)){ 
		bd[cantAPagar][monedaHasta]=new int;
		if(cantAPagar==0){
			*bd[cantAPagar][monedaHasta]= 0;
		}else{
			int usando=1+cambioMem(cantAPagar-valorMoneda[monedaHasta],monedaHasta,valorMoneda,bd);
			int noUsando=cambioMem(cantAPagar,monedaHasta-1,valorMoneda,bd);
			*bd[cantAPagar][monedaHasta]= min(usando,noUsando);
		}
	}

	return *bd[cantAPagar][monedaHasta];
};
int cantMon[8];
void quemonedas(int cantAPagar,int monedaHasta,int * valorMoneda,int * bd[CANT_MAX][MON_HASTA],int *cantMon){
	int mH=monedaHasta;

	for(int i=0;i<=monedaHasta;i++) cantMon[i]=0;
	inicializoBDCambio();
	int cant=cambioMem(cantAPagar,monedaHasta,valorMoneda,bd);
	cout <<endl<< "para pagar "<< cantAPagar << "usando moendas hasta la "<< monedaHasta<<" se requieren "<< cant <<" monedas"<< endl;
	while(cantAPagar>0 && monedaHasta>=0){
		if(monedaHasta==0){
			cantMon[monedaHasta]++;
			cantAPagar=cantAPagar-valorMoneda[monedaHasta];
		}else{
			if(*bd[cantAPagar][monedaHasta]==*bd[cantAPagar][monedaHasta-1])
				monedaHasta--;
			else{
			cantMon[monedaHasta]++;
			cantAPagar=cantAPagar-valorMoneda[monedaHasta];
			};
		};
	};

	cout <<endl;
	for(int i=0;i<=mH;i++){
		cout<< endl;
		cout.width(4);
		cout<< valorMoneda[i];
		cout.width(4);
		cout<< cantMon[i];
		cout<< endl;
	};
}