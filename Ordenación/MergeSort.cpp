/**

mergeSort: divide el arreglo a la mitad
Orden (nLog(n))

1.  divide la lista a la mitad
2. Ordenar cada sublista recursivamente aplicando el "ordenamiento por mezcla".
3. Mezclar las dos sublistas en una sola lista ordenada.

Otra forma de explicarlo:

1. Divide la lista en dos partes del mismo tamaño, 
2. y lo sigue dividiendo hasta que quede un elemento.
3. Cada una de las divisiones se ordena de manera separada 
4. luego se unen para formar el arreglo ya ordenado. 


**/
void mergesort(Array<nat> a, Array<nat> b, nat izq, nat der)
{
    if(izq<der){
        nat pivot=(izq+der)/2;
        mergesort(a,b,izq,pivot);
        mergesort(a,b,pivot+1,der);
        merge(a,b,izq,pivot+1,der);
    }
}

void merge (Array<int> A,  Array<int> T, int izq, int der, int derFin){	

	int i, izqFin, j, i;
	
	izqFin = der - 1;
	i = izq;
	j  = derFin - izq + 1;
	while ( izq <= izqFin && der <= derFin )
		if ( A[ izq ] <= A[ der ])
			T[ i++ ] = A[ izq++ ];
		else
			T[ i++ ] = A[ der++ ];
	}
	while ( izq <= izqFin ) T[ i++ ] = A[ izq++ ];
	while ( der <= derFin ) T[ i++ ] = A[ der++ ];
	for (i = 0 ; i < j ; i++, derFin--) A[ derFin ] = T[ derFin ];
}


Cáculo de orden en página 79.

//O(nLogn):

T(1) = 1
T(n) = 2T(n/2) + n
						-->  T(n) = 4T(n/4) + 2n --> T(i) = 2^iT(n/2^i) + in --> n = 2^i --> i = nLogn --> T(n) = nLogn + n --> O(nLogn)
T(n/2) = 2T(n/4) + n/2




