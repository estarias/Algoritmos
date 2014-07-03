costo -> distancia
tiempo -> tope

void Sistema::buscoCaminoMasCorto(V origen, V destino, G g
	nat distActual, nat &distMejor, 
	nat tiempoActual, nat tiempoMax, nat &tiempoMejor, 
	Puntero<Lista<V>> &caminoActual,  Puntero<Lista<V>> &caminoMejor, 
	Puntero<Lista<V>> noPasar){
	
	if (tiempoActual > tiempoMax) return; //Factibilidad
	if (caminoActual->Pertenece(origen)) return;
	if (noPasar->Pertenece(origen)) return;		
	if(distActual < distMejor || distActual == distMejor && tiempoActual< tiempoMejor){ //Poda
		caminoActual->Agregar(origen);//colocarTentativamenteOrigenSobreDesitno(origen, caminoActual);
		if (origen==destino){ //llegue(origen, destino)
			tiempoMejor = tiempoActual;
			distMejor = distActual;
			caminoMejor = caminoActual->Clonar();
		}else{
			for(Iterador<V> it = g->Adyacentes(origen);it.HayElemento();it++){
				V v= (V)it.ElementoActual();//seleccionarLaSiguienteAlternativa();

				nat dist = g->getDist(o,v);//CostoDistancia(g,origen,v)
				nat tiempo = g->getTiempo(o,v);
				
				buscoCaminoMasCorto(v,destino,g,
					distActual+dist, distMejor,
					tiempoActual+tiempo,tiempoMax, tiempoMejor, 
					caminoActual,caminoMejor, noPasar);
			};
		};
		caminoActual->Borrar(origen);//retirarElOrigenDelCaminoActual(caminoActual);
	}
};

