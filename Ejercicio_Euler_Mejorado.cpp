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

#include<iostream>   // Permite utilizar cout y cin.
#include<cmath>      // Permite utilizar funciones matemáticas.
#include<fstream>    // Permite crear y escribir archivos.
#include<cstdio>     // Permite utilizar FILE, popen, pclose y fprintf.

using namespace std;

// Función que calcula la aceleración en función de la posición.
// La aceleración está dada por ax=-1.58*x.
double aceleracion(double x){
    return -1.58*x;
}

int main(){

    // Se declaran las condiciones iniciales y los límites de tiempo.
    double x0,v0,t0,tf;

    // Se declara el número de pasos del método numérico.
    int N;

    // Se asignan los valores iniciales de la posición y la velocidad.
    x0=0.1;
    v0=0.0;

    // Se asignan el tiempo inicial y el tiempo final.
    t0=0.0;
    tf=12.7;

    // Se muestra información inicial del programa.
    cout<<"Bienvenid@."<<endl;
    cout<<"Este programa simula el movimiento de una particula con aceleracion variable ax=-1.58*x,"<<endl;
    cout<<"usando el metodo de Euler mejorado (Heun)."<<endl;
    cout<<endl;

    // Se solicita al usuario el número de pasos.
    cout<<"Ingrese el numero de pasos (N): ";
    cin>>N;

    // Se calcula el tamaño de cada paso de tiempo.
    double h=(tf-t0)/N;

    // Se inicializan el tiempo, la posición, la velocidad y la aceleración.
    double t=t0;
    double x=x0;
    double v=v0;
    double a=aceleracion(x);

    // Se crean los archivos donde se almacenarán los resultados.
    ofstream archposicion("posicion.dat");
    ofstream archvelocidad("velocidad.dat");
    ofstream archaceleracion("aceleracion.dat");

    // Se verifica que los archivos hayan sido abiertos correctamente.
    if(!archposicion || !archvelocidad || !archaceleracion){
        cerr<<"No se pudieron crear los archivos .dat"<<endl;
        return 1;
    }

    // Se guardan en los archivos los valores correspondientes al instante inicial.
    archposicion<<t<<" "<<x<<endl;
    archvelocidad<<t<<" "<<v<<endl;
    archaceleracion<<t<<" "<<a<<endl;

    // Se inicia el método de Euler mejorado (Heun).
    for(int i=0;i<N;i++){

        // Predictor: se calcula una aproximación de la posición siguiente.
        double xp=x+h*v;

        // Predictor: se calcula una aproximación de la velocidad siguiente.
        double vp=v+h*a;

        // Se calcula la aceleración correspondiente a la posición predicha.
        double ap=aceleracion(xp);

        // Corrector: se promedian las velocidades inicial y predicha
        // para obtener una mejor aproximación de la posición siguiente.
        x=x+(h/2.0)*(v+vp);

        // Corrector: se promedian las aceleraciones inicial y predicha
        // para obtener una mejor aproximación de la velocidad siguiente.
        v=v+(h/2.0)*(a+ap);

        // Se calcula la aceleración utilizando la posición corregida.
        a=aceleracion(x);

        // Se actualiza el tiempo al siguiente instante.
        t=t+h;

        // Se guardan los resultados corregidos en los archivos .dat.
        archposicion<<t<<" "<<x<<endl;
        archvelocidad<<t<<" "<<v<<endl;
        archaceleracion<<t<<" "<<a<<endl;
    }

    // Se cierran los archivos que contienen los resultados.
    archposicion.close();
    archvelocidad.close();
    archaceleracion.close();

    // Se abre una comunicación con Gnuplot para realizar la gráfica de posición.
    FILE *gnuplot1=popen("gnuplot -persist","w");

    // Se verifica que Gnuplot se haya podido ejecutar correctamente.
    if(gnuplot1==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    // Se activa la cuadrícula de la gráfica.
    fprintf(gnuplot1,"set grid\n");

    // Se establece el título de la gráfica.
    fprintf(gnuplot1,"set title \"Posicion vs Tiempo\"\n");

    // Se establece la etiqueta del eje x.
    fprintf(gnuplot1,"set xlabel \"Tiempo (s)\"\n");

    // Se establece la etiqueta del eje y.
    fprintf(gnuplot1,"set ylabel \"Posicion (m)\"\n");

    // Se grafica la posición en función del tiempo.
    fprintf(gnuplot1,"plot \"posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"x(t)\"\n");

    // Se abre una comunicación con Gnuplot para realizar la gráfica de velocidad.
    FILE *gnuplot2=popen("gnuplot -persist","w");

    // Se verifica que Gnuplot se haya podido ejecutar correctamente.
    if(gnuplot2==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    // Se activa la cuadrícula de la gráfica.
    fprintf(gnuplot2,"set grid\n");

    // Se establece el título de la gráfica.
    fprintf(gnuplot2,"set title \"Velocidad vs Tiempo\"\n");

    // Se establece la etiqueta del eje x.
    fprintf(gnuplot2,"set xlabel \"Tiempo (s)\"\n");

    // Se establece la etiqueta del eje y.
    fprintf(gnuplot2,"set ylabel \"Velocidad (m/s)\"\n");

    // Se grafica la velocidad en función del tiempo.
    fprintf(gnuplot2,"plot \"velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"vx(t)\"\n");

    // Se abre una comunicación con Gnuplot para realizar la gráfica de aceleración.
    FILE *gnuplot3=popen("gnuplot -persist","w");

    // Se verifica que Gnuplot se haya podido ejecutar correctamente.
    if(gnuplot3==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    // Se activa la cuadrícula de la gráfica.
    fprintf(gnuplot3,"set grid\n");

    // Se establece el título de la gráfica.
    fprintf(gnuplot3,"set title \"Aceleracion vs Tiempo\"\n");

    // Se establece la etiqueta del eje x.
    fprintf(gnuplot3,"set xlabel \"Tiempo (s)\"\n");

    // Se establece la etiqueta del eje y.
    fprintf(gnuplot3,"set ylabel \"Aceleracion (m/s^2)\"\n");

    // Se grafica la aceleración en función del tiempo.
    fprintf(gnuplot3,"plot \"aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"ax(t)\"\n");

    // Se cierran las comunicaciones con Gnuplot.
    pclose(gnuplot1);
    pclose(gnuplot2);
    pclose(gnuplot3);

    // Se finaliza correctamente el programa.
    return 0;
}