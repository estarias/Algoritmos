//Practico 6.  ej1
Cadena Multi(Cadena x, Cadena y){
	if (x.Largo < 5){
		return x.toInt() * x.toInt();
	}else{
		nat n = x.Largo;
		Cadena x1 = x.SubCadena(0, x.Largo/2);
		Cadena x2 = x.SubCadena(x.Largo/2, x.Largo);
		Cadena y1 = y.SubCadena(0, x.Largo/2);
		Cadena y2 = y.SubCadena(x.Largo/2, x.Largo);

		Cadena x1y1 = Multi(x1, y1);
		Cadena x1y2 = Multi(x1, y2);
		Cadena x2y1 = Multi(x2, y1);
		Cadena x2y2 = Multi(x2, y2);

		Cadena sol = CompletaCeros(x1y1, n);
		sol = suma(sol, x2y2);

		Cadena aux = suma(x1y2, x2y1);
		aux = CompletaCeros(aux, n/2);

		return suma(sol, aux);
	}
}