/**
insertSort: 

Algoritmo:
1. Tmo el primer elemento ylo coloco en la lista resultado.
2. Tomo el segundo elemento y lo comparo con el elemento que tengo en la lsita resultado, si es menor, lo coloco a la izq, y si es mauyor a la der.
3. Tomo el tercer elemento y lo comparao con los elementos que tengo en la lista resultado. Y lo coloco donde corresponde, desplazando los elementos de la lista resultado.
Repito este procedimiento hasta que me queden elementos por colocar.

O(n^2)

**/

void ISort (Array<int> a, int N){
 	int i, j;
	for (i = 1; i < N; i++){
		j = i;
		while (j > 0 && a[j] < a[j-1]){
			intercambio(a, j, j-1);
			j--;
		}
	}
}




Cáculo de orden en página 78.

//O(n^2):

T(0)=k
T(n) = T(n-1) + n
						--> T(n) = T(n-2) + (n-1) --> 
T(n-1) = T(n-2) + (n-1)
T(n-2) = T(n-3) + (n-2) ----------------------------->  T(n) = T(n-3) + (n-2) + (n-1) + n 

--> T(n) = T(0)
	i=n 		--> T(n) = sumatoria n(n+1)/2 --> T(n) = k + n(n+1)/2 --> O(n^2)





