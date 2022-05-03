#include <iostream>
#include "maxsolape.hpp"
// Cada fila de inters representa un intervalo. La primera columna
// es el inicio del intervalo, y la segunda el final. Por ejemplo:
//    double inters[N][2] = {
//        {1.5, 8.0},
//        {0.0, 4.5},
//        {2.0, 4.0},
//        {1.0, 6.0},
//        {3.5, 7.0}
//    };
// tiene cinco intervalos, el primero empieza en 1.5 y termina en 8.0.


// maxSolFBruta devuelve un registro tpSolape en el que el campo solape
// es el maximo solape entre parejas de los n primeros intervalos de inters,
// y los campos interA e interB son los indices de dichos intervalos.
// Para la matriz inters de ejemplo, el resultado es solape=4.5, interA=0,
// interB=3
// (los valores de interA e interB pueden estar intercambiados, es decir,
// el resultado para el ejemplo anterior tambi�n puede ser solape=4.5,
// interA=3, interB=0).
tpSolape maxSolFBruta(double inters[N][2], int n){
	tpSolape max;
	max.solape = 0;
	tpInter aux;
	double diff;
	for( int i=0; i<n; i++){
		for( int j=1;i+j<n;j++){
			if(inters[i][0]<inters[i+j][0] ){
				aux.ini = inters[i+j][0];
			}else{
				aux.ini = inters[i][0];
			}
			if(inters[i][1]<inters[i+j][1] ){
				aux.fin = inters[i][1];
			}else{
				aux.fin = inters[i+j][1];
			}
			diff = aux.fin-aux.ini;
			if(max.solape<diff){
				max.solape = diff;
				max.interA = i;
				max.interB = i+j;
			}
			
		}
	}

	return max;


}

// Crea un vector de tpInter con los n primeros intervalos de inters.
// Por ejemplo para la matrix inters de la funcion anterior y n=5, los
// valores de indinters seran:
// [{ind: 0, ini: 1.5, fin: 8.0},
//  {ind: 1, ini: 0.0, fin: 4.5},
//  {ind: 2, ini: 2.0, fin: 4.0},
//  {ind: 3, ini: 1.0, fin: 6.0},
//  {ind: 4, ini: 3.5, fin: 7.0}]
void crearvind(double inters[N][2], tpInter indinters[N], int n){
	for(int i = 0; i<n; i++){
		indinters[i].ini=inters[i][0];
		indinters[i].fin=inters[i][1];
		indinters[i].ind=i;
	}

}

/*
// Ordena con el algoritmo mergesort los intervalos de indinters
// comprendidos entre las componentes indexadas por p y f, ambas incluidas,
// de acuerdo al valor de inicio de los intervalos (orden creciente).
// Por ejemplo, para el vector de la funcion anterior, p=0 y f=4, el vector
// ordenado sera:
// [{ind: 1, ini: 0.0, fin: 4.5},
//  {ind: 3, ini: 1.0, fin: 6.0},
//  {ind: 0, ini: 1.5, fin: 8.0},
//  {ind: 2, ini: 2.0, fin: 4.0},
//  {ind: 4, ini: 3.5, fin: 7.0}]
void mergesortIndInters(tpInter indinters[N], int p, int f){

	if(p<f){
		int medio = (p+f)/2;
		mergesortIndInters(indinters,p,medio);
		mergesortIndInters(indinters, medio+1, f);
		merge(indinters, p, medio, f);
	}
}

// Dado un vector indinters, utiliza la tecnica de Divide y Venceras para
// devolver el maximo solape entre parejas de intervalos comprendidos
// entre las componentes indexadas por p y f, ambas incluidas.
// Por ejemplo, para el vector del procedimiento anterior,
// el resultado es solape=4.5, interA=0, interB=3
tpSolape maxSolDyV(tpInter indinters[N], int p, int f);
*/
