/*
Dada matriz binaria, tal que 1 es pared, y 0 es que esta libre.
Se necesita ir de entrada a la salida, derrumbando paredes, si es necesario.(o sea, el minimo de paredes)
Y retornar el camino.

Movimientos: arriba, derecha, izq y der.

retorna si tiene o no solución

*/
//		 "arriba" ,         abajo,          izq,              der
movs = [(-1, 0), (1,0), (0,-1), (0,1)] //movimientos
//por si lueog quiero agregar diagonales

bool laberinto(Tupla<int, int> origen, Tupla <int , int> destino, Matriz<int> matriz, Array<Tupla<int, int>> movs, 
			Puntero<Lista<Tupla<int, int>>> &sol, int & paredes, Matriz<bool> &visitado){
									"cant paredes rotas" 
									
	//Caso Base
	if (origen.Dato1 == destino.Dato1 && origen.Dato2 == destino.Dato2){
		paredes = 0;
		sol = new ListaEnc<Tupla<int, int>>();
		sol.AgregarEn(destino, 0); 
		return true;
	}
	
	visitados[origen.Dato1][origen.Dato2] = true;
	int min_paredes;
	bool haySol = false;
	Puntero<Lista<Tupla<int, int>>> min_sol;
	
	for (int i=0; i<movs.Largo;i++){ //para cada movimiento posible 
			Tupla<int, int> proxpos(origen.Dato1 + movs[i].Dato1, origen.Dato2 + movs[i].Dato2);
			if (proxpos.Dato1 >=0 && proxpos.Dato1 < matriz.Largo &&
				proxpos.Dato2 >=0 && proxpos.Dato2 < matriz.Ancho && //si nome sali de la matriz
				!visitados[proxpos.Dato1][proxpos.Dato2]){ // si no lo visite
				if (laberinto(proxpos, destino, matriz, movs, sol, paredes, visitados)){
					if (!haySol || paredes < min_paredes){
						sol_min = sol;
						min_paredes = paredes;
					}
				}
			}
	}
	
	visitados[origen.Dato1][origen.Dato2] = false;
	if (haySol){
		sol = sol_min;
		sol->AgregarEn(origen,0);
		paredes = min_pared + matriz[origen.Dato1][origen.Dato2];
		return true;
	}else{
		return false;
	}
	
	
	
	
}