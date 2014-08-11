/**selectSort
O(n^2)

Agoritmo:

1. selecciona el menor de los elementos de los N restantes desordenados, 
2. y lo mueve al final de los ya ordenados. 
3. Luego continúa la ejecución ordenando los N-1 restantes

**/
void SSort(int[] a){
	for (int i=1 i < n-1;i++){
	    int min = i;
	    for (int j=i+1; j < n; j++){
	        if (a[j] < a[min]){
	            min = j;
			}
	    }
	    intercambiar(a[i], a[min]);
	}
}