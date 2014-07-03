/*
[5,3,8,-50,20,4,-3,15,1]

LaMayorSumaDeElementosContiguos : [20..1]

*/


SM sumaMaxima(float *v, int izq, int der){
	SM SMIzq, SMDer, SMCen;
	int medio;
	
	if (izq == der){ //caso facil: cuando tengo un solo elemento
		SMIzq.suma = v[izq];
		SMIIzq.izq = izq;
		SMIIzq.der = izq;
	}else{ //caso dificil
		medio = (izq + der) / 2;
		SMIIzq = sumaMaxima(v, izq, medio);
		SMIDer = sumaMaxima(v, medio+1, der);
		
		int sumaBordeIzq, posIzq,sumaBordeDer, posDer, s;
		
		sumaBordeIzq = v[medio];
		posIzq = medio;
		s = v[medio];
		for (int i=medio-1;i>=izq;i--){ //voy sumando para la izquierda
			s = s + v[i];
			if (s>sumaBordeIzq){
				sumaBordeIzq = s; 
				posIzq = i;
			}
		}
		
		sumaBordeDer = v[medio+1];
		posDer = medio+1;
		s = v[medio+1];
		for (int i=medio+2;i <= der;i++){
			s = s + v[i];
			if (s>sumaBordeDer){
				sumaBordeDer = s; 
				posDer = i;
			}
		}
			
		SMICen.suma = sumaBordeIzq  + sumaBordeDer;
		SMICen.izq = posIzq;
		SMICen.der = posDer;
		
		}
		return mauorDe3(SMIzq, SMDer, SMCen);
	}
}