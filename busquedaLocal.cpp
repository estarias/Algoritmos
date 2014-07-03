//aplica transformaciones a la solución, para mejorar la misma.

Prim: O(v2 )
kruskal: O(A.logA)
Busqueda Local: O(v.Min(V,A))

Si grafo es denso ->(v2 = A), me conviene prim
Si el grafo es disperso (A<V), me conviene BL o kruskal.

//

Problema del agente viajero -> Backtracking, pero se va el orden al carajo, entonces para mejorarlo, podría: 
transfomar la solucion, a invertir arcos. Sustituri los arcos, por los arcos cruzados. 
Voy aplicando la transformacion a medida q puedo.
O(n^5)


//




