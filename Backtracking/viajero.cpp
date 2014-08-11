void itinerario(Grafo<V,A>> * g,V origen,V actual,
	float costoActual, int visitadasActual, int tiempoActual,
	float & mejorCosto, float & visitadasMejor, int & mejorTiempo,
	Lista<V> * noPasar, Lista<V> * Pasar,
    Lista<V> * &caminoActual, Lista<Lista<V>> * &caminos, int visitadas){
    
    int ciudadPase=0;
    if (caminoActual->Pertenece(actual)) return;
    if (noPasar->Pertenece(actual)) return;	
    if(costoActual<mejorCosto || costoActual==mejorCosto && visitadasActual < visitadasMejor ||
        costoActual==mejorCosto && visitadasActual == visitadasMejor && tiempoActual <= mejorTiempo){ //poda
        caminoActual->Agregar(actual);//colocarTentativamenteActualEnElCamino
        if(Pasar->Pertenece(actual)) ciudadPase=1;
        if(origen==actual && visitadas == Pasar->Largo(){ //llegueAlOrigen(origen,actual) && pasePorTodas(visitadas,Pasar)
           if(costoActual<mejorCosto || costoActual==mejorCosto && visitadasActual < visitadasMejor ||
				costoActual==mejorCosto && visitadasActual == visitadasMejor && tiempoActual < mejorTiempo) //encontreMejorCamino
                caminos->Vaciar();
            mejorCosto=costoActual;
            mejorCantCiudades=visitadasActual;
            mejorTiempo=tiempoActual;
            caminos->Agregar(caminoActual->Clon());
        }else{
            foreach(w, g->Adyacentes(actual))
                itinerario(g, origen,w,
							costoActual+costo(g,actual,w),visitadasActual+1,tiempoActual+tiempo(g,actual,w),
							mejorCosto,mejorCantCiudades,mejorTiempo,
							noPasar,Pasar,
							caminoActual,caminos, visitadas+ciudadPase);
            };
        }
        caminoActual->Borrar(actual)//retirarActualDelCamino
    }

};