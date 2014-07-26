/**selectSort
O(n^2)

Agoritmo:

1. Buscar el mínimo elemento de la lista
2. Intercambiarlo con el primero
3. Buscar el siguiente mínimo en el resto de la lista
4. Intercambiarlo con el segundo

Y en general:

1.  Buscar el mínimo elemento entre una posición i y el final de la lista
2. Intercambiar el mínimo con el elemento de la posición i

**/
void SSort(int[] a){
	for (int i=1 i < n-1;i++){
	    int min = i;
	    for (int j=i+1; j < n){
	        if (a[j] < a[minimo]){
	            min = j;
			}
	    }
	    intercambiar(a[i], a[min]);
	}
}