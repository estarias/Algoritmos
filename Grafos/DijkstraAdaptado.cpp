//Camino mas corto ponderado costo negativo

//*******************Ini Seudocódigo:*******************
//El visitado, indica si el vertice ya esta en la cola
Cola * c = new ColaImp()
c->Encolar(origen)
tabla[origen].visitado = true
while (!cola.EstaVacia()):
	V v = cola.Desencolar()
	for (w in Adyacentes(v)):
		costoAcumulado = tabla[v].costo + costo(v,w)
		if (costoAcumulado < tabla[w].costo):
			tabla[w].costo = costoAcumulado
			if (!tabla[w].visitado): 
				cola->Encolar(w)
//*******************Fin Seudocodigo*******************

