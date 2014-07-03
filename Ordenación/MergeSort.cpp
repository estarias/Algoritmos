mergeSort: divide el arreglo a la mitad
Orden (nLog(n))
void MSort(int[] a, int[] temp, int izq, int der){
	if (izqz<der){
		medio = (izq+der)/2;
		MSort(a, izq, medio);
		MSort(a, medio+1, der);
		merge(a, temp, izq, medio+1, der);
	}
}
void merge(int[] a, int[] temp, int izqPos, int derPos, int derFin){
	int izqFin = derPos - 1;
	int pos = izqPos;
	while(izqPos <=izqFin && derPos <= derFin){
		if (a[izqPos]<=a[derPos])
			temp[pos++] = a[izqPos++];
		else
			temp[pos++] = a[derPos++];
	}
	
}

Cáculo de orden en página 79.

//O(nLogn):

T(1) = 1
T(n) = 2T(n/2) + n
						-->  T(n) = 4T(n/4) + 2n --> T(i) = 2^iT(n/2^i) + in --> n = 2^i --> i = nLogn --> T(n) = nLogn + n --> O(nLogn)
T(n/2) = 2T(n/4) + n/2

