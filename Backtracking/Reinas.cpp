////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <assert.h>
using namespace std;

#define DIM 10
bool dSuma[2*DIM+1];
bool dDife[2*DIM+1];
bool fila[DIM+1];
int solucion[DIM+1];

void inicializo(){
	for(int i=0;i<2*DIM+1;i++){
		dSuma[i]=true;
		dDife[i]=true;
	}
	for(int i=0;i<DIM+1;i++)
		fila[i]=true;
};
int seleccionarLaPrimerAlternativa(){
	return 1;
};
bool hayMasAlternativas(int Fila){
	return Fila < DIM+1;
};
bool estaSegura(int columna,int Fila){
	return dSuma[columna+Fila] && dDife[columna-Fila+DIM] && fila[Fila];
};
void colocarTentativamenteLaReina(int columna,int Fila){
	assert(estaSegura(columna,Fila));
	dSuma[columna+Fila]=false;  
	dDife[columna-Fila+DIM]=false; 
	fila[Fila]=false;
	solucion[columna]=Fila;
};
void retirarLaReina(int columna,int Fila){
	assert(!estaSegura(columna,Fila));
	dSuma[columna+Fila]=true;  
	dDife[columna-Fila+DIM] =true;  
	fila[Fila]=true; 
};
int seleccionarLaSiguienteAlternativa(int Fila){
	return Fila+1;
};
bool termine(int reina){
	return reina == DIM;
};

void mostrarLaSolucion(){
	static int nro=1;
	cout << endl;
	cout.width(5);
	cout <<nro++<<"===> ";
	for(int i=1;i<=DIM;i++){
		cout.width(3);
		cout << solucion[i];
	};
}

void NReinas(int reina, bool & exito){
	int Fila;
	Fila=seleccionarLaPrimerAlternativa();
	while(hayMasAlternativas(Fila) && !exito){
		if(estaSegura(reina,Fila)){
			colocarTentativamenteLaReina(reina,Fila);
			if(termine(reina)){
				//exito=true;
				mostrarLaSolucion();
				retirarLaReina(reina,Fila);
			}else{
				NReinas(reina+1,exito);
				if(!exito){
					retirarLaReina(reina,Fila);
				};
			};
		};
		Fila=seleccionarLaSiguienteAlternativa(Fila);
	};
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////