/*
Código de movimiento MRUA en una dimensión con graficador
25.08.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co
El código calcula y representa el movimiento de una partícula en una dimensión con aceleración constante. Utiliza funciones para determinar la posición, la velocidad, la aceleración y el desplazamiento en función del tiempo. A partir de los valores iniciales y el tiempo final, genera archivos con los datos del movimiento y utiliza Gnuplot para elaborar las gráficas de posición, velocidad y aceleración respecto al tiempo. Además, muestra en pantalla la posición y velocidad finales y el desplazamiento realizado.
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
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
    double vxf=velocidad(v0x,ax,tf);

    cout<<"Posicion inicial: "<<x0<<" m"<<endl;
    cout<<"Velocidad inicial: "<<v0x<<" m/s"<<endl;
    cout<<"Aceleracion: "<<ax<<" m/s^2"<<endl;
    cout<<"Tiempo final: "<<tf<<" s"<<endl;
    cout<<"Posicion final: "<<xf<<" m"<<endl;
    cout<<"Velocidad final: "<<vxf<<" m/s"<<endl;
    cout<<"Desplazamiento: "<<deltaX<<" m"<<endl;

    FILE *gnuplot1=popen("gnuplot -persist","w");

    if(gnuplot1==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot1,"set grid\n");

    fprintf(gnuplot1,"set title \"Posicion vs Tiempo\"\n");
    fprintf(gnuplot1,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot1,"set ylabel \"Posicion x (m)\"\n");
    fprintf(gnuplot1,"plot \"posicion.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'blue' title 'x(t)'\n");

	FILE *gnuplot2=popen("gnuplot -persist","w");
	
	if(gnuplot2==NULL){
		cerr<<"No se pudo ejecutar Gnuplot"<<endl;
		return 1;
	}

    fprintf(gnuplot2,"set title \"Velocidad vs Tiempo\"\n");
    fprintf(gnuplot2,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot2,"set ylabel \"Velocidad vx (m/s)\"\n");
    fprintf(gnuplot2,"plot \"velocidad.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'red' title 'vx(t)'\n");

	FILE *gnuplot3=popen("gnuplot -persist","w");
	
	if(gnuplot3==NULL){
		cerr<<"No se pudo ejecutar Gnuplot"<<endl;
		return 1;
	}

    fprintf(gnuplot3,"set title \"Aceleracion vs Tiempo\"\n");
    fprintf(gnuplot3,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot3,"set ylabel \"Aceleracion ax (m/s^2)\"\n");
    fprintf(gnuplot3,"plot \"aceleracion.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'green' title 'ax(t)'\n");

    pclose(gnuplot1);
    pclose(gnuplot2);
    pclose(gnuplot3);

    return 0;
}
