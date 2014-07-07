costo -> distancia
tiempo -> tope

void Sistema::buscoCaminoMasCorto(V origen, V destino, G g
	nat distActual, nat &distMejor, 
	nat tiempoActual, nat &tiempoMejor, nat tiempoMax, 
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
			//Si quiero todos los caminos, no pregunto si lo mejoré:
			//Puntero<Lista<Puntero<Estacion>>> c = caminoActual->Clonar();
			//caminos->Agregar(c);
		}else{
			foreach(v, g->Adyacentes(origen)) //seleccionarLaSiguienteAlternativa();
				nat dist = g->getDist(o,v);//CostoDistancia(g,origen,v)
				nat tiempo = g->getTiempo(o,v);
				
				buscoCaminoMasCorto(v,destino,g,
					distActual+dist, distMejor,
					tiempoActual+tiempo, tiempoMejor, tiempoMax,
					caminoActual,caminoMejor, noPasar);
			};
		};
		caminoActual->Borrar(origen);//retirarElOrigenDelCaminoActual(caminoActual);
	}
};



costo -> distancia
tiempo -> tope

void Sistema::buscoCaminosMasBaratos(V origen, V destino, G g
	nat distActual, nat &distMejor, 
	nat tiempoActual, nat &tiempoMejor,
	Puntero<Lista<V>> &caminoActual,  Puntero<Lista<Lista<V>>> &caminos){
	
	if (caminoActual->Pertenece(origen)) return;
	if(distActual < distMejor || distActual == distMejor && tiempoActual< tiempoMejor){ //Poda
		caminoActual->Agregar(origen);//colocarTentativamenteOrigenSobreDesitno(origen, caminoActual);
		if (origen==destino){ //llegue(origen, destino)
			if(distActual < distMejor) caminos->Vaciar();//encontreUnCaminoMejor
			tiempoMejor = tiempoActual;
			distMejor = distActual;
			caminos->Agregar(caminoActual->Clonar());
		}else{
			foreach(v, g->Adyacentes(origen)) //seleccionarLaSiguienteAlternativa();
				nat dist = g->getDist(o,v);//CostoDistancia(g,origen,v)
				nat tiempo = g->getTiempo(o,v);
				
				buscoCaminoMasCorto(v,destino,g,
					distActual+dist, distMejor,
					tiempoActual+tiempo, tiempoMejor
					caminoActual,caminos);
			};
		};
		caminoActual->Borrar(origen);//retirarElOrigenDelCaminoActual(caminoActual);
	}
};

