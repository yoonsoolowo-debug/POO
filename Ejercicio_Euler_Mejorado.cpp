/*
Programa de cinemática - Método de Euler mejorado (Heun)
08.09.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co

Este programa simula el movimiento de una partícula sobre el eje x
sometida a una aceleración variable ax = -1.58*x, usando el método
de Euler mejorado (predictor-corrector). Calcula posición, velocidad
y aceleración en función del tiempo, y genera archivos .dat para
graficar con Gnuplot.
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdio>
#include<vector>

using namespace std;

// Función que calcula la aceleración en función de la posición.
// ax = -1.58 * x
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
    cout<<"Este programa simula un MRUV con aceleracion variable ax=-1.58x,"<<endl;
    cout<<"usando el metodo de Euler mejorado (Heun)."<<endl;
    cout<<endl;

    cout<<"Ingrese el numero de pasos (N): ";
    cin>>N;

    double h=(tf-t0)/N;

    vector<double> t(N+1), x(N+1), v(N+1), a(N+1);

    t[0]=t0;
    x[0]=x0;
    v[0]=v0;
    a[0]=aceleracion(x[0]);

    // Método de Euler mejorado (predictor-corrector).
    for(int i=0;i<N;i++){

        // Predictor: se usan las pendientes en el punto actual.
        double xp=x[i]+h*v[i];
        double vp=v[i]+h*a[i];
        double ap=aceleracion(xp);

        // Corrector: se promedian las pendientes inicial y predicha.
        x[i+1]=x[i]+ (h/2.0)*(v[i]+vp);
        v[i+1]=v[i]+ (h/2.0)*(a[i]+ap);
        a[i+1]=aceleracion(x[i+1]);
        t[i+1]=t[i]+h;
    }

    cout<<endl;
    cout<<"===================================="<<endl;
    cout<<"TABLA DE RESULTADOS"<<endl;
    cout<<"===================================="<<endl;
    cout<<"t(s)\tIndice\tvx(m/s)\t\tx(m)\t\tax(m/s^2)"<<endl;

    for(int i=0;i<=N;i++){
        cout<<t[i]<<"\t"<<i<<"\t"<<v[i]<<"\t"<<x[i]<<"\t"<<a[i]<<endl;
    }
    cout<<endl;

    ofstream archposicion("posicion.dat");
    ofstream archvelocidad("velocidad.dat");
    ofstream archaceleracion("aceleracion.dat");

    for(int i=0;i<=N;i++){
        archposicion<<t[i]<<" "<<x[i]<<endl;
        archvelocidad<<t[i]<<" "<<v[i]<<endl;
        archaceleracion<<t[i]<<" "<<a[i]<<endl;
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
