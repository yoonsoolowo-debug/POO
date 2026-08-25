#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

double posicion(double x0,double v0x,double ax,double t){
    return x0+v0x*t+0.5*ax*t*t;
}

double velocidad(double v0x,double ax,double t){
    return v0x+ax*t;
}

double aceleracion(double ax){
    return ax;
}

double desplazamiento(double xf,double x0){
    return xf-x0;
}

int main(){

    double x0=-5.6;
    double v0x=9.3;
    double ax=-4.2;
    double tf=4.1;

    int n=10;

    ofstream archivoPosicion("posicion.txt");
    ofstream archivoVelocidad("velocidad.txt");
    ofstream archivoAceleracion("aceleracion.txt");

    for(int i=0;i<=n;i++){

        double t=i*tf/n;

        double x=posicion(x0,v0x,ax,t);
        double vx=velocidad(v0x,ax,t);
        double a=aceleracion(ax);

        archivoPosicion<<t<<" "<<x<<endl;
        archivoVelocidad<<t<<" "<<vx<<endl;
        archivoAceleracion<<t<<" "<<a<<endl;
    }

    archivoPosicion.close();
    archivoVelocidad.close();
    archivoAceleracion.close();

    double xf=posicion(x0,v0x,ax,tf);
    double deltaX=desplazamiento(xf,x0);

    cout<<"Posicion inicial: "<<x0<<" m"<<endl;
    cout<<"Velocidad inicial: "<<v0x<<" m/s"<<endl;
    cout<<"Aceleracion: "<<ax<<" m/s^2"<<endl;
    cout<<"Tiempo final: "<<tf<<" s"<<endl;
    cout<<"Posicion final: "<<xf<<" m"<<endl;
    cout<<"Desplazamiento: "<<deltaX<<" m"<<endl;

    FILE *gnuplot=popen("gnuplot -persist","w");

    if(gnuplot==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot,"set grid\n");

    fprintf(gnuplot,"set title \"Posicion vs Tiempo\"\n");
    fprintf(gnuplot,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot,"set ylabel \"Posicion x (m)\"\n");
    fprintf(gnuplot,"plot \"posicion.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'blue' title 'x(t)'\n");

    fprintf(gnuplot,"set title \"Velocidad vs Tiempo\"\n");
    fprintf(gnuplot,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot,"set ylabel \"Velocidad vx (m/s)\"\n");
    fprintf(gnuplot,"plot \"velocidad.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'red' title 'vx(t)'\n");

    fprintf(gnuplot,"set title \"Aceleracion vs Tiempo\"\n");
    fprintf(gnuplot,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot,"set ylabel \"Aceleracion ax (m/s^2)\"\n");
    fprintf(gnuplot,"plot \"aceleracion.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'green' title 'ax(t)'\n");

    pclose(gnuplot);

    return 0;
}