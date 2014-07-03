#define A 0
#define T 1
#define N 10
#define M 10
int mapa[N][M]={
	{T,T,T,T,T,T,T,T,T,T},
	{T,A,A,A,A,A,A,A,T,T},
	{T,A,A,A,A,A,A,T,A,T},
	{T,A,A,T,T,T,T,T,A,T},
	{T,A,T,A,A,A,A,T,A,T},
	{T,A,T,A,T,T,A,T,A,T},
	{T,A,T,A,T,T,A,T,A,T},
	{T,A,T,A,A,A,A,T,A,T},
	{T,A,T,T,T,T,T,A,A,T},
	{T,A,A,A,A,A,A,A,A,T}
};

bool esTierra(int i,int j,int mapa[N][M]){
	assert(perteneceAlMapa(i,j));
	return mapa[i][j]==T;
};
void borrarPunto(int mapa[N][M],int i,int j,int marca){
	assert(perteneceAlMapa(i,j));
	mapa[i][j]=marca;
};
bool perteneceAlMapa(int i,int j){
	return i>-1 && i<N && j>-1 && j<M;
}
void borrarIsla(int mapa[N][M],int i,int j,int marca){
	if(perteneceAlMapa(i,j)){
		if(esTierra(i,j,mapa)){
			borrarPunto(mapa,i,j,marca);
			for(int dx=-1;dx<2;dx++)
				for(int dy=-1;dy<2;dy++)
					borrarIsla(mapa,i+dx,j+dy,marca);
		}
	};
};

int islas(int mapa[N][M]){
	int cont=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(esTierra(i,j,mapa)){
				cont++;
				borrarIsla(mapa,i,j,cont+1);
			};
		}
	}
	return cont;
};
void main()
{
	//bool exito=false;
	//inicializo();
	//NReinas(1,exito);
	//if(exito)
		//mostrarLaSolucion();
	cout << endl << islas(mapa);
};



