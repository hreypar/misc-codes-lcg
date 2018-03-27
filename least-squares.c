#include <stdio.h>
# include <stdlib.h>
#include <math.h>

float Sumatoria_X ( float *x, int num_datos, int potencia );
float Sumatoria_Y ( float *x, float *y, int num_datos, int potencia );
void free_mtrz ( void **M, unsigned int max);
float * GaussJordan ( float ** X, float * Y, int num);


void main (void){

	int n, grado , k, j; 
	float ** Matriz, * Resultados, * Solucion, * vectorx, * vectory;    

	// Primero se piden los datos generales.
	printf("\nCual es el grado del polinomio que deseas ajustar a tus datos: \n 	(Recuerda que si deseas ajustar a una recta, el grado es 1, \n y si deseas ajustar a una potencial, debes introducir los datos en Ln) ");
	scanf("%d", &grado);
	printf ("\nIndica el numero de parejas (x,y) con las que cuentas : ");
	scanf("%d", &n);

	//Se declaran los vectores para la tabulación de "x" & de "y"
	vectorx = (float*) malloc (n*sizeof(float));
	vectory = (float*) malloc (n*sizeof(float));

	//Meter valores de x & y para los cálculos
	for ( k=0; k<n ; k++){  
		printf("Proporciona el valor de x%d :  ", k+1);
		scanf("%f", (vectorx+k));
		printf("Proporciona el valor de y%d :  ", k+1);
		scanf("%f", (vectory+k));
	}

	//Se declara el vector de los resultados del sistema de ecuaciones
	Resultados = (float*) malloc ((grado+1)*sizeof (float ));
	
	//Se declara la matriz para el sistema de ecuaciones
	Matriz = malloc ((grado+1) * sizeof (float *));
	for ( k=0; k<=grado; k++){  
		*(Matriz+k) = (float*) malloc((grado+1)*sizeof(float));
	}


//Se llena la matriz para el sistema de ecuaciones, y el vector de soluciones
	for ( k=0; k<(grado+1); k++){
		for ( j=0; j<(grado+1); j++){		
			*(*(Matriz+k)+j)=Sumatoria_X(vectorx, n, (k+j));
		}
		*(Resultados+k)=Sumatoria_Y(vectorx, vectory, n, k);
	}


//Se manda llamar la funcion que resuelve el effing sistema!!
	Solucion = (float*) malloc ((grado+1) * sizeof(float));
	Solucion = GaussJordan ( Matriz, Resultados, grado);


//Se imprimen los bellos resultados (al revés, para que queden derechos en la impresion)
	puts ("\n\nEl polinomio que se ajusta a tus datos es el siguiente:\n\n");
	for (k= grado ; k >= 0 ; k--) {
		if (k==0) {
			printf ( "%.2f = 0", *(Solucion+k));
		} else {
			printf ( "%.2f(x^%d) + ", *(Solucion+k), k);
		}
	}
printf("\n\n\n\n");
//Se libera memoria para que no estemos tristes todos.
	free_mtrz ( (void**)Matriz, grado+1);
	free(Resultados);
	free(Solucion);
	free(vectorx);
	free(vectory);

//FIN :D
}


float Sumatoria_X ( float *x, int num_datos, int potencia ){
	float suma=0;
	int m;
	for(m=0; m<num_datos; m++){
		suma+=pow((*(x+m)), potencia);
	}
	return suma;
}

float Sumatoria_Y ( float *x,float *y,  int num_datos, int potencia ){
	float suma =0;
	int m;
	for(m=0; m<num_datos; m++){
		suma+=pow((*(x+m)), potencia)*(*(y+m));
	}
	return suma;
}

void free_mtrz ( void **M, unsigned int max) {
	unsigned int x;
	for (x=0; x < max; x++) {
		free ( *(M+x) );
	}
	free (M);
}

float* GaussJordan ( float ** X, float * Y, int num){

	float  pivote, valor, *VectorSolucion, **MatrizExtendida;
	int i, j, k, x, y;


// 1. Crear una matriz extendida (juntar el sistema con las soluciones)
	MatrizExtendida = malloc ((num+1) * sizeof (float *));
	for ( i=0; i < (num+1); i++){  
		*(MatrizExtendida+i) = (float*) malloc((num+2)*sizeof(float));
	}

//2. Llenar la matriz extendida con los valores del sistema (x) y la solución (y)
	for ( i=0; i<(num+1); i++){
		for ( j=0; j<(num+1); j++){		
			*(*(MatrizExtendida+i)+j)=*(*(X+i)+j);
		}
		*(*(MatrizExtendida+i)+(num+1))=*(Y+i);
	}

//3. Aplicar la eliminación Gaussiana (Gauss-Jordan para un sólo vector

for (i = 0; i < (num+1); i++){
	pivote = *(*(MatrizExtendida+i)+i);	

	for (j=0; j < (num+2); j++){
		 *(*(MatrizExtendida+i)+j) /= pivote;
	}

	for (j=0; j < (num+1); j++){
		if (i!=j){
			valor = -*(*(MatrizExtendida+j)+i) ;
			for (k = 0; k < (num+2); k++){
				*(*(MatrizExtendida+j)+k) = *(*(MatrizExtendida+i)+k)*valor + *(*(MatrizExtendida+j)+k);
			}
		}
	}

}

	for (x = 0; x < (num+1); x++) {
		printf ("\n");
		for (y = 0; y < (num+2); y++ ) {
			printf ("%.2f  ", *(*(MatrizExtendida+x)+y) );
		}
	}

//4. Declaro unn vector donde voy a copiar lo que regresará el programa

	VectorSolucion = (float*) malloc ((num+1)*sizeof (float ));

	for (i = 0; i < (num+1); i++){
		*(VectorSolucion + i) = *(*(MatrizExtendida+i)+(num+1));
	}

	return (VectorSolucion);

}



