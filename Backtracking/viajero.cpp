void itinerario(Grafo<Ciudad,Arco>> * g,Ciudad origen,Ciudad actual,float costoActual,int cantCiudades,int cantPase,int tiempoActual,Lista<Ciudad> * noPasar,Lista<Ciudad> * Pasar,
    Lista<Ciudad> *caminoActual,float & mejorCosto, float & mejorCantCiuddades, int & mejorTiempo,
    Lista<Lista<Ciudad>> * mejoresCaminos){
    
    int ciudadPase=0;
    if (caminoActual->Pertenece(actual)) return;
    if (noPasar->Pertenece(actual)) return;	
    if(costoActual<mejorCosto || costoActual==mejorCosto && cantCiudades < mejorCantCiuddades ||
        costoActual==mejorCosto && cantCiudades == mejorCantCiuddades && tiempoActual <= mejorTiempo){
        caminoActual->Agregar(actual);//colocarTentativamenteActualEnElCamino
        if(Pasar->Pertenece(actual)) ciudadPase=1;
        if(origen==actual && cantPase == Pasar->Largo(){ //llegueAlOrigen(origen,actual) && pasePorTodas(cantPase,Pasar)
            if(encontreUnCaminoMejor(costoActual,cantCiudades,tiempoActual,mejorCosto,mejorCantCiuddades,mejorTiempo)
                mejoresCaminos->Vaciar();
            mejorCosto=costoActual;
            mejorCantCiudades=cantCiudades;
            mejorTiempo=tiempoActual;
            mejoresCaminos->Agregar(caminoActual->Clon());
        }else{
            foreach(c, g->Adyacentes(actual))
                itinerario(origen,c,costoActual+costo(g,actual,c),cantiCiudades+1,cantPasa+ciudadPase,tiempoActual+tiempo(g,actual,c),
                    noPasar,Pasar,caminoActual,mejorCosto,mejorCantCiudades,mejorTiempo);
            };
        }
        caminoActual->Borrar(actual)//retirarActualDelCamino
    }

};