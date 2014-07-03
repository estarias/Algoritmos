
//seudo codigo
def BFS(Vertice v):
	CrearCola(Q)
	marcar(v)
	encolar(Q,v)
	while !EsVacia(Q): 
		u = primero(Q) 
		Q = resto(Q) 
		for w in adyacentes(u):
			if !estaMarcado(w):
				marcar(w)
				encolar(Q,w) 

def main(): 
	//inicializo todos los vertices como no marcados
	for v in V[G]: DesMarcar(v)
	//recorro los vertices no marcados
	for v in V[G]:
		if !estaMarcado(v): BFS(v)