SM sumaMaxima(int * v,int izq,int der){
	SM smI,smD;
	int sumaBordeIzq, posIzq,s;
	int medio;
	if(izq==der){ //caso f'acil 1 elemento
		smI.desde=izq;
		smI.hasta=izq;
		smI.suma=v[izq];
		return smI;
	}else{
		//caso difiicil, dividimos el problema
		medio=(izq+der)/2;
		smI=sumaMaxima(v,izq,medio);
		smD=sumaMaxima(v,medio+1,der);
		// falta particio centro

		sumaBordeIzq=v[medio];s=v[medio];posIzq=medio;
		for(int i=medio-1;i>=izq;i--){
			s=s+v[i];
			if(s>sumaBordeIzq){
				sumaBordeIzq=s;
				posIzq=i;
			};
		};
		int sumaBordeDer,posDer;
		sumaBordeDer=v[medio+1];s=v[medio+1];posDer=medio+1;
		for(int i=medio+2;i<=der;i++){
			s=s+v[i];
			if(s>sumaBordeDer){
				sumaBordeDer=s;
				posDer=i;
			};
		};
		SM smC;
		smC.desde=posIzq;
		smC.hasta=posDer;
		smC.suma=sumaBordeDer+sumaBordeIzq;
		return mejorDe3(smC,smI,smD);
	};
};

SM mejorDe3(SM s1,SM s2,SM s3){
	SM ret=s1;
	if(ret.suma<s2.suma) ret=s2;
	if(ret.suma<s3.suma) ret=s3;
	return ret;
};