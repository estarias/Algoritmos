/*
Se están desarrollando los juegos olímpicos. Uno de los asistentes es aficionado a un conjunto de disciplinas. Se
puede ingresar a un estadio abonando una entrada que tiene un costo dependiente del estadio. El aficionado
cuenta con una cantidad de dinero y tiempo.
En cada estadio se compite en un conjunto de disciplinas y, pagando la entrada al estadio, se puede asistir a todas
ellas. La jornada en cada estadio tiene una duración expresada en unidades de tiempo.
Como este aficionado se interesa en múltiples disciplinas se le dificulta elegir a que estadios concurrir. Para ello
le asignó a cada disciplina de su gusto un valor de su preferencia por ella (las que no le interesan valen 0) y
solicita su ayuda para elaborar una lista de los estadios a los que asistir para lograr la máxima suma de valores de
preferencia de las disciplinas a las que pudo asistir tomando en cuenta la suma de dinero y el tiempo de que
dispone. Usted deberá retornar una lista de los estadios a los que debe concurrir para obtener la mejor suma de
valores.
Se pide:
a) Resolver el problema anterior. Si usa TADs deberá especificarlos pero no implementarlos.
b) ¿Encuentra alguna ineficiencia en la solución propuesta? Fundamente su respuesta.
c) Si su repuesta a la pregunta anterior fue afirmativa
a. Proponga una técnica de diseño de algoritmos que permita levantar esta ineficiencia.
b. Desarrolle el algoritmo correspondiente
*/

/***

Mochila capacidad bidimensional dinero,tiempo
Los objetos son los estadios
El peso costo de la entrada tiempo de la jornada
El valor suma de las preferencias de los deportes que se ven en el estadio

***/
define N 20
Array<bool> solMejor(N);
Array<nat> valor(N);
Array<nat> costo(N);
Array<nat> tiempo(N);

void mochila(nat it,nat valorActual,nat costoActual,nat tiempoActual,
			nat costoMax,nat tiempoMax,nat & mejorValor,Array<bool> solMejor,
             Array<bool> solActual, Array<nat> valor, Array<nat> costo, Array<nat> tiempo){
    if(it==0 || costoActual>costoMax || tiempoActual>tiempoMax) return;
	if(valorActual > mejorValor){
		mejorValor=valorActual;
		copio(solActual,solMejor);
	}else{
		solActual[it]=true;
		mochila(it-1,valorActual+valor[it],costoActual+costo[it],tiempoActual+tiempo[it],
			costoMax,tiempoMax,mejorValor,solMejor,solActual,valor,costo,tiempo);
		solActual[it]=false;
		mochila(it-1,valorActual,costoActual,tiempoActual,costoMax,tiempoMax,mejorValor,
			solMejor,solActual,valor,costo,tiempo);
	}
};