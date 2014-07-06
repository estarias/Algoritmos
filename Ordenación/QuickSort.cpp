/***quickSort

Por caso: O(n^2)
Mejor caso: O(nLog(n)) (igual q merge sort) 
Ref: http://www.fing.edu.uy/inco/cursos/prog3/wiki/uploads/Site/Analisis%20del%20problema%20de%20Sorting_v2.1.pdf

***/

void quickSort(int[] a, int ini, int fin){
	if (ini >= fin) return;
	int posPivote = particion(a, ini, fin);
	quickSort(a, ini, posPivote-1);
	quickSort(a, posPivote+1, fin);
}

int particion(Array<int> a, int ini, int fin) {
	int pivote = a[ini];
	int posPivote = ini;
	
	for (int i = ini+1; i<=fin; i++){
		if (a[i]<pivote){
			posPivote++;
			intercambio(a, posPivote, i);
		}
	}
	intercambio(a, ini, posPivote);
	return posPivote;
}