/*
Programa de cinemática - Método de Euler mejorado (Heun)
08.09.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co

Este programa simula el movimiento de una partícula sobre el eje x
sometida a una aceleración variable ax=-1.58*x, usando el método
de Euler mejorado (predictor-corrector). Calcula posición, velocidad
y aceleración en función del tiempo, y genera archivos .dat para
graficar con Gnuplot.
*/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdio>

using namespace std;

double aceleracion(double x){
    return -1.58*x;
}

int main(){

    double x0,v0,t0,tf;
    int N;

    x0=0.1;
    v0=0.0;

    t0=0.0;
    tf=12.7;

    cout<<"Bienvenid@."<<endl;
    cout<<"Este programa simula el movimiento de una particula con aceleracion variable ax=-1.58*x,"<<endl;
    cout<<"usando el metodo de Euler mejorado (Heun)."<<endl;
    cout<<endl;

    cout<<"Ingrese el numero de pasos (N): ";
    cin>>N;

    double h=(tf-t0)/N;

    double t=t0;
    double x=x0;
    double v=v0;
    double a=aceleracion(x);

    ofstream archposicion("posicion.dat");
    ofstream archvelocidad("velocidad.dat");
    ofstream archaceleracion("aceleracion.dat");

    if(!archposicion || !archvelocidad || !archaceleracion){
        cerr<<"No se pudieron crear los archivos .dat"<<endl;
        return 1;
    }

    archposicion<<t<<" "<<x<<endl;
    archvelocidad<<t<<" "<<v<<endl;
    archaceleracion<<t<<" "<<a<<endl;

    for(int i=0;i<N;i++){

        double xp=x+h*v;
        double vp=v+h*a;

        double ap=aceleracion(xp);

        x=x+(h/2.0)*(v+vp);

        v=v+(h/2.0)*(a+ap);

        a=aceleracion(x);

        t=t+h;

        archposicion<<t<<" "<<x<<endl;
        archvelocidad<<t<<" "<<v<<endl;
        archaceleracion<<t<<" "<<a<<endl;
    }

    archposicion.close();
    archvelocidad.close();
    archaceleracion.close();

    FILE *gnuplot1=popen("gnuplot -persist","w");

    if(gnuplot1==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot1,"set grid\n");
    fprintf(gnuplot1,"set title \"Posicion vs Tiempo\"\n");
    fprintf(gnuplot1,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot1,"set ylabel \"Posicion (m)\"\n");
    fprintf(gnuplot1,"plot \"posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"x(t)\"\n");

    FILE *gnuplot2=popen("gnuplot -persist","w");

    if(gnuplot2==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot2,"set grid\n");
    fprintf(gnuplot2,"set title \"Velocidad vs Tiempo\"\n");
    fprintf(gnuplot2,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot2,"set ylabel \"Velocidad (m/s)\"\n");
    fprintf(gnuplot2,"plot \"velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"vx(t)\"\n");

    FILE *gnuplot3=popen("gnuplot -persist","w");

    if(gnuplot3==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot3,"set grid\n");
    fprintf(gnuplot3,"set title \"Aceleracion vs Tiempo\"\n");
    fprintf(gnuplot3,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot3,"set ylabel \"Aceleracion (m/s^2)\"\n");
    fprintf(gnuplot3,"plot \"aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"ax(t)\"\n");

    pclose(gnuplot1);
    pclose(gnuplot2);
    pclose(gnuplot3);

    return 0;
}
