
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void free_mtrz ( void **M, unsigned int max);

void main (void){

int num, i,j, bandera, iter;
float ** Matriz, * Resultados, error, error_actual, * Solucion, * SolucionAnterior, diag, resto, suma;

//Primero lo primero, indicar el tamaño del sistema.
printf ("\nFavor de Indicar tamano de sistema\n\n");
scanf ("%d", &num);

//Ya que sabemos el tamaño, creamos la matriz muajajaja
Matriz = NULL;
Matriz = malloc(num * sizeof(float *));
if ( Matriz == NULL){ 
	printf ("Error: Falta de memoria\n");
	exit (EXIT_FAILURE);
}

for(i=0; i<num; i++){
	*(Matriz + i) = (float *) malloc(num * sizeof(float));
	if ( *(Matriz+i) == NULL){
		printf ("Error: Falta de memoria\n");
		exit (EXIT_FAILURE);
   	}
}

//Ahora creamos el vector dónde guardaremos los resultados del sistema
Resultados = NULL;
Resultados = (float *) malloc(num * sizeof(float));
if ( Resultados == NULL){ 
	printf ("Error: Falta de memoria\n");
	exit (EXIT_FAILURE);
}


//Ahora, le pediremos al usuario que llene el sistema.
for(i=0; i<num; i++){
	for(j=0; j<num; j++){
		printf ("Favor de colocar el coeficiente a(%d)(%d)   ", i+1, j+1);
		scanf ("%f", (*(Matriz +i) +j) );
	}
	printf ("Favor de colocar el resultado de la ecuacion %d   ", i+1);
	scanf ("%f", Resultados +i );
	printf ("\n");
}

//Ahora chingamos al usuario forzándolo a poner una diagonal pesada :3
for(i=0; i<num; i++){
	diag = 0;
	resto = 0;
	for(j=0; j<num; j++){
		if (i == j){
			diag = fabs(*(*(Matriz + i) +j));
		} else {
			resto += fabs(*(*(Matriz + i) +j));
		}
	}
	if (resto>=diag){
		printf ("El sistema no es diagonalmente dominante. Intentalo de nuevo :D (jaja) \n");
		exit (EXIT_FAILURE);
	}
}


error = 0;
printf ("Favor de indicar la precision (error) con la que deseas trabajar   ");
scanf ("%f", &error );
printf ("Su error es de %f\n", error);


//Creamos los vectores solución :D (el actual y el anterior!)
Solucion = NULL;
Solucion = (float *) calloc(num, sizeof(float));
if ( Solucion == NULL){ 
	printf ("Error: Falta de memoria\n");
	exit (EXIT_FAILURE);
}
SolucionAnterior = NULL;
SolucionAnterior = (float *) calloc(num, sizeof(float));
if ( SolucionAnterior == NULL){ 
	printf ("Error: Falta de memoria\n");
	exit (EXIT_FAILURE);
}


// La talacha gaussseideliana 

error_actual =0;
iter = 0;

do{

	bandera = 0;
	iter++;

	for(i=0; i<num; i++){
		suma = 0;
		for(j=0; j<num; j++){
			if (i == j){
				continue;
			} else {
				suma += (*(*(Matriz + i) +j)) * (*(SolucionAnterior + j));
			}
		}
		*(Solucion + i) = ((*(Resultados + i))-(suma))/(*(*(Matriz + i) +i));

		
		error_actual = ( *(Solucion + i)  - *(SolucionAnterior + i) )/(*(Solucion + i));

 	   if (error_actual > error){
			bandera=1;
		}
		

		*(SolucionAnterior + i) = *(Solucion + i);
		//printf ("\nEl resultado de x%d es: %f", i+1, *(SolucionAnterior + i));

	}

}while (bandera);

for(i=0; i<num; i++){
	printf ("\nEl resultado de x%d es: %f", i+1, *(SolucionAnterior + i));
}
printf ("\nSe obtuvo el resultado en %d iteraciones\n\n\n", iter);

free_mtrz ((void **)Matriz, num);
free (Solucion);
free(SolucionAnterior);
free(Resultados);

}

void free_mtrz ( void **M, unsigned int max) {
	unsigned int x;
	for (x=0; x < max; x++) {
		free ( *(M+x) );
	}
	free (M);
}

