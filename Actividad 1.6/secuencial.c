#include <stdio.h>
#include <math.h>
#include <omp.h>

void runge1(int n,  int rhe, char d[]){
	FILE *fptr;

	fptr=fopen(d,"w");
	printf("Pasos:%d Thread:%d\n", n,rhe);
	fprintf(fptr, "Datos Euler");
	double h,t,w,ab,k1,k2,k3,k4;
	double w0=M_PI/4,a=0,b=M_PI;
	int i;
	w=w0;
	fprintf(fptr, "%f\t %f\n", a, w);
	for(i=0;i<=n;i++){
		h=(b-a)/n;
		t=a+(h*i);
		ab=t*t;
		k1= h*(t*exp(3*t)-2*w);
		k2= h*((t+h/2.0)*exp(3*(t+h/2.0))-2*(w+k1/2.0));
		k3= h*((t+h/2.0)*exp(3*(t+h/2.0))-2*(w+k2/2.0));
		k4= h*((t+h)*exp(3*(t+h))-2*(w+k3));
		w=w+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		fprintf(fptr, "%f\t %f\n", t, w);
		
	}
	fclose(fptr);
}

void runge2(int n,  int rhe, char d[]){
	FILE *fptr;

	fptr=fopen(d,"w");
	printf("Pasos:%d Thread:%d\n", n,rhe);
	fprintf(fptr, "Datos Euler");
	double h,t,w,ab,k1,k2,k3,k4;
	double w0=M_PI/4,a=0,b=M_PI;
	int i;
	w=w0;
	fprintf(fptr, "%f\t %f\n", a, w);
	for(i=0;i<=n;i++){
		h=(b-a)/n;
		t=a+(h*i);
		ab=t*t;
		k1= h*(1+pow(t-w,2));
		k2= h*(1+pow((t+h/2.0)-(w+k1/2.0),2));
		k3= h*(1+pow((t+h/2.0)-(w+k2/2.0),2));
		k4= h*(1+pow((t+h)-(w+k3),2));
		w=w+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		fprintf(fptr, "%f\t %f\n", t, w);
		
	}
	fclose(fptr);
}

void runge3(int n,  int rhe, char d[]){
	FILE *fptr;

	fptr=fopen(d,"w");
	printf("Pasos:%d Thread:%d\n", n,rhe);
	fprintf(fptr, "Datos Euler");
	double h,t,w,ab,k1,k2,k3,k4;
	double w0=M_PI/4,a=0,b=M_PI;
	int i;
	w=w0;
	fprintf(fptr, "%f\t %f\n", a, w);
	for(i=0;i<=n;i++){
		h=(b-a)/n;
		t=a+(h*i);
		ab=t*t;
		k1= h*(1+t/w);
		k2= h*(1+(t+h/2.0)/(w+k1/2.0));
		k3= h*(1+(t+h/2.0)/(w+k2/2.0));
		k4= h*(1+(t+h)/(w+k3));
		w=w+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		fprintf(fptr, "%f\t %f\n", t, w);
		
	}
	fclose(fptr);
}


void runge4(int n,  int rhe, char d[]){
	FILE *fptr;

	fptr=fopen(d,"w");
	printf("Pasos:%d Thread:%d\n", n,rhe);
	fprintf(fptr, "Datos Euler");
	double h,t,w,ab,k1,k2,k3,k4;
	double w0=M_PI/4,a=0,b=M_PI;
	int i;
	w=w0;
	fprintf(fptr, "%f\t %f\n", a, w);
	for(i=0;i<=n;i++){
		h=(b-a)/n;
		t=a+(h*i);
		ab=t*t;
		k1= h*(cos(2*t*w)+sin(3*t*w));
		k2= h*(cos(2*(t+h/2.0)*(w+k1/2.0))+sin(3*(t+h/2.0)*(w+k1/2.0)));
		k3= h*(cos(2*(t+h/2.0)*(w+k2/2.0))+sin(3*(t+h/2.0)*(w+k2/2.0)));
		k4= h*(cos(2*(t+h)*(w+k3))+sin(3*(t+h)*(w+k3)));
		w=w+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		fprintf(fptr, "%f\t %f\n", t, w);
		
	}
	fclose(fptr);
}

void main(int argc, char const *argv[])
{
	const double start = omp_get_wtime();
	int N = 50000;
	runge1(N, 1, "Secuencial_1.txt");
	runge2(N, 2, "Secuencial_2.txt");
	runge3(N, 3, "Secuencial_3.txt");
	runge4(N, 4, "Secuencial_4.txt");
	const double end = omp_get_wtime();
	printf("Segundos: %lf\n", (end - start));
}