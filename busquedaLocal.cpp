* Busqueda local: 
- Aplica transformaciones a la solución, para mejorar la misma.

* ArbolCubrimientoMin
- Prim: O(v2 )
- kruskal: O(A.logA)
- Busqueda Local: O(v.Min(V,A))

-> Si grafo es denso (v2 = A) -> me conviene prim
-> Si grafo es disperso (A<V) -> me conviene BL o kruskal.

* Problema del agente viajero
- Backtracking: se va el orden al carajo
- Busqueda Local: transfomar la solucion, a invertir arcos. Sustituir los arcos, por los arcos cruzados. O(n^5)

