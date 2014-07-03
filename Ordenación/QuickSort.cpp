quickSort

Por caso: O(n^2)
Mejor caso: O(nLog(n)) (igual q merge sort) 

void quicksort(int[] a, int izq, int der){
	int pivot = particion(a, izq, der);
	int i = izq;
	int j = der -1;
	for (;;){
		while (a[i] < pivot) i++;
		while (a[j] >= pivot) j--;
		if (i<j) 
			intercambio(a[i], a[j]);
		else
			break;
	}
	intercambio(a[i], a[der-1]);
}

int divide(int []a , int izq, int der) {
    int medio = (izq+der)/2;
	if (a[medio]<a[izq])
		intercambio(a[medio], a[izq]);
	
	if (a[der]<a[izq])
		intercambio(a[der], a[izq]);
	
	if (a[der]<a[medio])
		intercambio(a[der], v[izq]);
	
	intercambio(a[medio], a[der-1]);
	
	return a[der-1];
}