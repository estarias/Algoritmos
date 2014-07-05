//selectSort
//O(n^2)

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