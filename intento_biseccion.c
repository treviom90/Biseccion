//MÉTODO BISECCIÓN DE LA FORMA X^3+X^2+X+C
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

double iteracion_anterior=1,iteracion_actual=1;
int iteracion=0;

double leer_doble();
int validacion_intervalo(double x1,double xu,double c1,double c2,double c3,double c4);
double calcular_xr(double x1,double xu);
double casos(double x1,double xr,double c1,double c2,double c3,double c4);
double error_aprox(double iteracion_actual,double iteracion_anterior);

int main(){
	double error_aproximado=100,validacion=0,res=0,raiz=0;
	double x1=0,xu=0,xr=0,Ea=0,c1=0,c2=0,c3=0,c4=0;

	
	printf("\t--------------METODO DE BISECCION-------------\n\n");
	printf("\t\tDA SOLUCION A LA FORMA x%c+x%c+x+c\n\n",252,253);
	
	do{
		printf("\tIngresa el valor minimo de tu intervalo: ");
        x1 = leer_doble();
		printf("\n\tIngresa el valor maximo de tu intervalo: ");
		xu = leer_doble();
		printf("\n\tIngresa el maximo valor del error aproximado que puede tener: ");
		Ea = leer_doble();
	
		printf("\n\n\tIngresa el coeficiente del termino x%c: ",252);
		c1 = leer_doble();
		printf("\n\tIngresa el coeficiente del termino x%c: ",253);
		c2 = leer_doble();
		printf("\n\tIngresa el coeficiente del termino x: ");
		c3 = leer_doble();
		printf("\n\tIngresa el valor de tu constante: ");
		c4 = leer_doble();
		validacion=validacion_intervalo(x1,xu,c1,c2,c3,c4);
	}while(validacion==0);
	
	
	do{
		xr=calcular_xr(x1,xu);
		++iteracion;
		iteracion_anterior=iteracion_actual;
		iteracion_actual=xr;
		res= casos(x1,xr,c1,c2,c3,c4);
		if(res<0){
			xu=xr;
		}else if(res>0){
			x1=xr;
		}else{
			raiz=xr;
			printf("\n\tAproximacion a la raiz: %lf",raiz);
			break;
		}
		if(iteracion>1){
			error_aproximado=error_aprox(iteracion_actual,iteracion_anterior);
		}

	}while (error_aproximado>Ea);
	
	raiz=xr;
	printf("\n\tAproximacion a la raiz: %lf",raiz);
	printf("\n\tError aproximado: %lf%c",error_aproximado,37);
	
	return 0;
}

double leer_doble() {
    char cadena[127];   // cadena temporal para leer valores
    char *ap; // apuntador necesario para convertir a real
    fgets(cadena, 127, stdin);
    return strtod(cadena, &ap);
}

int validacion_intervalo(double x1,double xu,double c1,double c2,double c3,double c4){
	int a=0;
	double fx1=0,fxr=0,res=0;
	fx1= (c1*(pow(x1,3)))+(c2*(pow(x1,2)))+(c3*x1)+c4;
	//printf("%lf\n",fx1);
	fxr= (c1*(pow(xu,3)))+(c2*(pow(xu,2)))+(c3*xu)+c4;
	//printf("%lf\n",fxr);
	res=fx1*fxr;
	if(res>0){
		printf("\n\n\t----NO CONTIENE LA RAIZ -----\n\n");
		return a;
	}
	else{
		a=1;
	}
	return a;
}

double calcular_xr(double x1,double xu){
	double respuesta=0;
	respuesta= (x1+xu)/2;
	return respuesta;
}

double casos(double x1,double xr,double c1,double c2,double c3,double c4){
	double fx1=0,fxr=0,respuesta=0;
	fx1= (c1*(pow(x1,3)))+(c2*(pow(x1,2)))+(c3*x1)+c4;
	fxr= (c1*(pow(xr,3)))+(c2*(pow(xr,2)))+(c3*xr)+c4;
	respuesta=fx1*fxr;
	
	return respuesta;
}

double error_aprox(double iteracion_actual,double iteracion_anterior){
	double error_aproximado=0;
	error_aproximado= fabs((iteracion_actual-iteracion_anterior)/(iteracion_actual))*100;

	return error_aproximado;
}
