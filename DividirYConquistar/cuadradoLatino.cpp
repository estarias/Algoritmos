void cuadradoLatino(int n){
	if (n==1){
		m[0][0] = 1;
	}else{
		assert(esPar(n));
		cuadradoLatino(n/2);
		copiar(0,0,0,n/2, n/2, n/2); //desde_x, desde_y, hasta_x, hasta_y, dimension, incremento
		copiar(0,0,n/2,n/2, n/2, 0);
		copiar(0,0,n/2,0, , n/2);
	}
}