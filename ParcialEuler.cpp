/*
Programa de cinemática - Método de Euler y Euler mejorado
09.09.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co

Este programa simula el movimiento de un objeto de masa m=3.2 kg
sobre el eje x, sometido a una fuerza neta variable.

La fuerza está dada por:
Fx=-62.720*x+10.464*x^3-0.544*x^5

El programa utiliza el método de Euler y el método de Euler
mejorado para calcular la posición, velocidad y aceleración
de la partícula en función del tiempo.

También genera archivos .dat para realizar las gráficas
de posición, velocidad y aceleración mediante Gnuplot.
*/

#include<iostream>   // Entrada y salida de datos.
#include<cmath>      // Funciones matemáticas.
#include<fstream>    // Manejo de archivos.
#include<cstdio>     // Comunicación con Gnuplot.

using namespace std;

// Función que calcula la fuerza neta en función de la posición.
double fuerza(double x){
    return -62.720*x+10.464*pow(x,3)-0.544*pow(x,5);
}

// Función que calcula la aceleración a partir de la fuerza.
double aceleracion(double x,double m){
    return fuerza(x)/m;
}

int main(){

    // Datos del problema.
    double m;
    double x0,v0;
    double t0,tf;
    int N;

    // Condiciones iniciales.
    m=3.2;
    x0=1.1;
    v0=0.0;
    t0=0.0;
    tf=6.7;

    cout<<"Bienvenid@."<<endl;
    cout<<"Este programa simula el movimiento de un objeto sobre el eje x."<<endl;
    cout<<"Se utilizan los metodos de Euler y Euler mejorado."<<endl;
    cout<<endl;

    cout<<"Masa = "<<m<<" kg"<<endl;
    cout<<"Posicion inicial = "<<x0<<" m"<<endl;
    cout<<"Velocidad inicial = "<<v0<<" m/s"<<endl;
    cout<<"Tiempo final = "<<tf<<" s"<<endl;
    cout<<endl;

    // Se solicita el número de pasos.
    cout<<"Ingrese el numero de pasos (N): ";
    cin>>N;

    // Incremento de tiempo.
    double h=(tf-t0)/N;

    // =========================================================
    // METODO DE EULER
    // =========================================================

    double te=t0;
    double xe=x0;
    double ve=v0;
    double ae=aceleracion(xe,m);

    // Archivos para guardar los resultados de Euler.
    ofstream eulerposicion("euler_posicion.dat");
    ofstream eulervelocidad("euler_velocidad.dat");
    ofstream euleraceleracion("euler_aceleracion.dat");

    if(!eulerposicion || !eulervelocidad || !euleraceleracion){
        cerr<<"No se pudieron crear los archivos de Euler."<<endl;
        return 1;
    }

    // Se guardan las condiciones iniciales.
    eulerposicion<<te<<" "<<xe<<endl;
    eulervelocidad<<te<<" "<<ve<<endl;
    euleraceleracion<<te<<" "<<ae<<endl;

    // Se aplica el método de Euler.
    for(int i=0;i<N;i++){

        // Se guarda la velocidad actual para utilizarla en x(n+1).
        double vactual=ve;

        // Euler para la velocidad:
        // v(n+1)=v(n)+h*a(n).
        ve=ve+h*ae;

        // Euler para la posición:
        // x(n+1)=x(n)+h*v(n).
        xe=xe+h*vactual;

        // Se actualiza el tiempo.
        te=te+h;

        // Se calcula la nueva aceleración con la nueva posición.
        ae=aceleracion(xe,m);

        // Se guardan los resultados.
        eulerposicion<<te<<" "<<xe<<endl;
        eulervelocidad<<te<<" "<<ve<<endl;
        euleraceleracion<<te<<" "<<ae<<endl;
    }

    // Se cierran los archivos de Euler.
    eulerposicion.close();
    eulervelocidad.close();
    euleraceleracion.close();

    // =========================================================
    // METODO DE EULER MEJORADO
    // =========================================================

    double tm=t0;
    double xm=x0;
    double vm=v0;
    double am=aceleracion(xm,m);

    // Archivos para guardar los resultados de Euler mejorado.
    ofstream mejoradoposicion("mejorado_posicion.dat");
    ofstream mejoradovelocidad("mejorado_velocidad.dat");
    ofstream mejoradoaceleracion("mejorado_aceleracion.dat");

    if(!mejoradoposicion || !mejoradovelocidad || !mejoradoaceleracion){
        cerr<<"No se pudieron crear los archivos de Euler mejorado."<<endl;
        return 1;
    }

    // Se guardan las condiciones iniciales.
    mejoradoposicion<<tm<<" "<<xm<<endl;
    mejoradovelocidad<<tm<<" "<<vm<<endl;
    mejoradoaceleracion<<tm<<" "<<am<<endl;

    // Se aplica el método de Euler mejorado.
    for(int i=0;i<N;i++){

        // Se conservan los valores actuales para el corrector.
        double vactual=vm;
        double aactual=am;

        // Predictor de la velocidad.
        double vpred=vactual+h*aactual;

        // Predictor de la posición.
        double xpred=xm+h*vactual;

        // Aceleración en la posición predicha.
        double apred=aceleracion(xpred,m);

        // Corrector de la velocidad.
        vm=vactual+(h/2.0)*(aactual+apred);

        // Corrector de la posición.
        xm=xm+(h/2.0)*(vactual+vpred);

        // Se actualiza el tiempo.
        tm=tm+h;

        // Se calcula la aceleración con la posición corregida.
        am=aceleracion(xm,m);

        // Se guardan los resultados.
        mejoradoposicion<<tm<<" "<<xm<<endl;
        mejoradovelocidad<<tm<<" "<<vm<<endl;
        mejoradoaceleracion<<tm<<" "<<am<<endl;
    }

    // Se cierran los archivos de Euler mejorado.
    mejoradoposicion.close();
    mejoradovelocidad.close();
    mejoradoaceleracion.close();

    // =========================================================
    // GRAFICA DE POSICION VS TIEMPO
    // =========================================================

    // Se abre Gnuplot.
    FILE *gnuplot1=popen("gnuplot -persist","w");

    if(gnuplot1==NULL){
        cerr<<"No se pudo ejecutar Gnuplot."<<endl;
        return 1;
    }

    fprintf(gnuplot1,"set grid\n");
    fprintf(gnuplot1,"set title \"Posicion vs Tiempo\"\n");
    fprintf(gnuplot1,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot1,"set ylabel \"Posicion (m)\"\n");

    // Se comparan Euler y Euler mejorado.
    fprintf(gnuplot1,"plot \"euler_posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler\", \"mejorado_posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler mejorado\"\n");

    // =========================================================
    // GRAFICA DE VELOCIDAD VS TIEMPO
    // =========================================================

    FILE *gnuplot2=popen("gnuplot -persist","w");

    if(gnuplot2==NULL){
        cerr<<"No se pudo ejecutar Gnuplot."<<endl;
        return 1;
    }

    fprintf(gnuplot2,"set grid\n");
    fprintf(gnuplot2,"set title \"Velocidad vs Tiempo\"\n");
    fprintf(gnuplot2,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot2,"set ylabel \"Velocidad (m/s)\"\n");

    // Se comparan Euler y Euler mejorado.
    fprintf(gnuplot2,"plot \"euler_velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler\", \"mejorado_velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler mejorado\"\n");

    // =========================================================
    // GRAFICA DE ACELERACION VS TIEMPO
    // =========================================================

    FILE *gnuplot3=popen("gnuplot -persist","w");

    if(gnuplot3==NULL){
        cerr<<"No se pudo ejecutar Gnuplot."<<endl;
        return 1;
    }

    fprintf(gnuplot3,"set grid\n");
    fprintf(gnuplot3,"set title \"Aceleracion vs Tiempo\"\n");
    fprintf(gnuplot3,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot3,"set ylabel \"Aceleracion (m/s^2)\"\n");

    // Se comparan Euler y Euler mejorado.
    fprintf(gnuplot3,"plot \"euler_aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler\", \"mejorado_aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler mejorado\"\n");

    // Se cierran las comunicaciones con Gnuplot.
    pclose(gnuplot1);
    pclose(gnuplot2);
    pclose(gnuplot3);

    return 0;
}