//Helena R Gopar. Metodos numericos. Lagranja

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main (void){

//DECLARACIÓN DE VARIABLES
int i, j, N;
float x, y, numerador, denominador;




//TABULACIÓN DE DATOS
printf ("Cuantas parejas de datos tienes para evaluar con el metodo de Lagrange?\n\n");
scanf ("%d", &N);

float* ptrx = malloc( N * sizeof(float));
float* ptry = malloc( N * sizeof(float));


printf ("\n\nIntoduce de manera ordenada los valores 'x'\n\n");
for (i = 0; i < N; i ++){
	scanf ("%f", ptrx + i);
}

printf ("\n\nIntoduzca de manera ordenada los valores 'y'\n\n");
for (i = 0; i < N; i ++){
	scanf ("%f", ptry + i);
}

x = 0;
printf ("\n\nPara que valor de 'x' quieres interpolar?\n\n");
scanf ("%f", &x);



//APLICAR LAGRANGE

y = 0;

for ( i = 0 ; i < N; i++){

numerador = 1;
	for(j = 0; j < N; j++){
		if ( i != j){
			numerador *= x - (*(ptrx + j));
		}
	}

denominador = 1;
	for(j = 0; j < N; j++){
		if( i != j){
			denominador *=  ((*(ptrx + i)) - (*(ptrx + j))) ;
		}
	}

		y += (*(ptry + i )) * (numerador/denominador);

}


printf ("\n\nEl valor de x=%.3f interpolado a la tabulacion da un resultado de y = %.3f\n\n\n\n\n", x, y);

free (ptrx);
free (ptry);

}
