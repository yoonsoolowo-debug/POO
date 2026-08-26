/*
Programa de cinemática
06.08.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co

Este programa simula un MRUA en el plano cartesiano.
Calcula la posición, velocidad, aceleración, desplazamiento,
rapidez y dirección de la velocidad y aceleración de una
partícula. También genera archivos .dat para graficar
posición, velocidad, aceleración y trayectoria.
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdio>

using namespace std;

// Estructura para representar un vector en dos dimensiones.
// Cada vector tiene una componente en x y otra en y.
struct vector{
    double x,y;
};

// Función que suma dos vectores.
vector suma(vector a,vector b){
    vector r;
    r.x=a.x+b.x;
    r.y=a.y+b.y;
    return r;
}

// Función que multiplica un vector por un escalar.
vector producto(vector a,double k){
    vector r;
    r.x=a.x*k;
    r.y=a.y*k;
    return r;
}

// Función que calcula la posición de la partícula.
vector posicion(vector r0,vector v0,vector a,double t){
    vector r;
    r=suma(suma(r0,producto(v0,t)),producto(a,0.5*t*t));
    return r;
}

// Función que calcula la velocidad de la partícula.
vector velocidad(vector v0,vector a,double t){
    vector v;
    v=suma(v0,producto(a,t));
    return v;
}

// Función que calcula la magnitud de un vector.
double norma(vector v){
    return sqrt(v.x*v.x+v.y*v.y);
}

// Función que calcula el desplazamiento entre dos posiciones.
vector desplazamiento(vector r0,vector rf){
    vector d;
    d.x=rf.x-r0.x;
    d.y=rf.y-r0.y;
    return d;
}

// Función que imprime las componentes de un vector.
void imprimir(vector v){
    cout<<"("<<v.x<<", "<<v.y<<")"<<endl;
}

// Función que calcula el coseno director respecto al eje x.
double cosenoX(vector v){
    return v.x/norma(v);
}

// Función que calcula el coseno director respecto al eje y.
double cosenoY(vector v){
    return v.y/norma(v);
}

// Función que calcula el ángulo respecto al eje x.
double anguloX(vector v){
    return acos(cosenoX(v))*180.0/M_PI;
}

// Función que calcula el ángulo respecto al eje y.
double anguloY(vector v){
    return acos(cosenoY(v))*180.0/M_PI;
}

int main(){

    vector r0,v0,a;
    vector rf,vf;
    vector d;

    double t;

    cout<<"Bienvenid@."<<endl;
    cout<<"En este programa se simula un movimiento rectilineo uniformemente acelerado en el plano cartesiano."<<endl;
    cout<<"El programa calcula la posicion, velocidad, aceleracion, desplazamiento, rapidez y direccion de la particula."<<endl;
    cout<<endl;

    r0.x=-5.6;
    r0.y=7.8;

    v0.x=9.3;
    v0.y=-6.5;

    a.x=-4.2;
    a.y=6.4;

    t=5.1;

    rf=posicion(r0,v0,a,t);
    vf=velocidad(v0,a,t);
    d=desplazamiento(r0,rf);

    cout<<"===================================="<<endl;
    cout<<"RESULTADOS"<<endl;
    cout<<"===================================="<<endl;
    cout<<endl;

    cout<<"Posicion inicial:"<<endl;
    imprimir(r0);
    cout<<endl;

    cout<<"Velocidad inicial:"<<endl;
    imprimir(v0);
    cout<<endl;

    cout<<"Rapidez inicial = "<<norma(v0)<<" m/s"<<endl;
    cout<<endl;

    cout<<"Cosenos directores de la velocidad inicial:"<<endl;
    cout<<"cos(alpha) = "<<cosenoX(v0)<<endl;
    cout<<"cos(beta) = "<<cosenoY(v0)<<endl;
    cout<<endl;

    cout<<"Angulos de la velocidad inicial:"<<endl;
    cout<<"alpha = "<<anguloX(v0)<<" grados"<<endl;
    cout<<"beta = "<<anguloY(v0)<<" grados"<<endl;
    cout<<endl;

    cout<<"Aceleracion:"<<endl;
    imprimir(a);
    cout<<endl;

    cout<<"Magnitud de la aceleracion = "<<norma(a)<<" m/s^2"<<endl;
    cout<<endl;

    cout<<"Cosenos directores de la aceleracion:"<<endl;
    cout<<"cos(alpha) = "<<cosenoX(a)<<endl;
    cout<<"cos(beta) = "<<cosenoY(a)<<endl;
    cout<<endl;

    cout<<"Angulos de la aceleracion:"<<endl;
    cout<<"alpha = "<<anguloX(a)<<" grados"<<endl;
    cout<<"beta = "<<anguloY(a)<<" grados"<<endl;
    cout<<endl;

    cout<<"Posicion final:"<<endl;
    imprimir(rf);
    cout<<endl;

    cout<<"Velocidad final:"<<endl;
    imprimir(vf);
    cout<<endl;

    cout<<"Rapidez final = "<<norma(vf)<<" m/s"<<endl;
    cout<<endl;

    cout<<"Cosenos directores de la velocidad final:"<<endl;
    cout<<"cos(alpha) = "<<cosenoX(vf)<<endl;
    cout<<"cos(beta) = "<<cosenoY(vf)<<endl;
    cout<<endl;

    cout<<"Angulos de la velocidad final:"<<endl;
    cout<<"alpha = "<<anguloX(vf)<<" grados"<<endl;
    cout<<"beta = "<<anguloY(vf)<<" grados"<<endl;
    cout<<endl;

    cout<<"Desplazamiento total de la particula:"<<endl;
    imprimir(d);
    cout<<endl;

    cout<<"Magnitud del desplazamiento = "<<norma(d)<<" m"<<endl;
    cout<<endl;

    ofstream archposicion("posicion.dat");
    ofstream archvelocidad("velocidad.dat");
    ofstream archaceleracion("aceleracion.dat");
    ofstream archtrayectoria("trayectoria.dat");

    double dt=t/9.0;

    for(int i=0;i<10;i++){

        double ti=i*dt;

        vector rp=posicion(r0,v0,a,ti);
        vector vp=velocidad(v0,a,ti);

        archposicion<<ti<<" "<<rp.x<<" "<<rp.y<<endl;
        archvelocidad<<ti<<" "<<vp.x<<" "<<vp.y<<endl;
        archaceleracion<<ti<<" "<<a.x<<" "<<a.y<<endl;
        archtrayectoria<<rp.x<<" "<<rp.y<<endl;
    }

    archposicion.close();
    archvelocidad.close();
    archaceleracion.close();
    archtrayectoria.close();

    FILE *gnuplot1=popen("gnuplot -persist","w");

    if(gnuplot1==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot1,"set grid\n");
    fprintf(gnuplot1,"set title \"Posicion vs Tiempo\"\n");
    fprintf(gnuplot1,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot1,"set ylabel \"Posicion (m)\"\n");
    fprintf(gnuplot1,"plot \"posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"x(t)\", \"posicion.dat\" using 1:3 with linespoints pt 6 ps 1 title \"y(t)\"\n");

    FILE *gnuplot2=popen("gnuplot -persist","w");

    if(gnuplot2==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot2,"set grid\n");
    fprintf(gnuplot2,"set title \"Velocidad vs Tiempo\"\n");
    fprintf(gnuplot2,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot2,"set ylabel \"Velocidad (m/s)\"\n");
    fprintf(gnuplot2,"plot \"velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"vx(t)\", \"velocidad.dat\" using 1:3 with linespoints pt 6 ps 1 title \"vy(t)\"\n");

    FILE *gnuplot3=popen("gnuplot -persist","w");

    if(gnuplot3==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot3,"set grid\n");
    fprintf(gnuplot3,"set title \"Aceleracion vs Tiempo\"\n");
    fprintf(gnuplot3,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot3,"set ylabel \"Aceleracion (m/s^2)\"\n");
    fprintf(gnuplot3,"plot \"aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"ax(t)\", \"aceleracion.dat\" using 1:3 with linespoints pt 6 ps 1 title \"ay(t)\"\n");

    FILE *gnuplot4=popen("gnuplot -persist","w");

    if(gnuplot4==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot4,"set grid\n");
    fprintf(gnuplot4,"set title \"Trayectoria de la particula\"\n");
    fprintf(gnuplot4,"set xlabel \"x (m)\"\n");
    fprintf(gnuplot4,"set ylabel \"y (m)\"\n");
    fprintf(gnuplot4,"plot \"trayectoria.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Trayectoria\"\n");

    pclose(gnuplot1);
    pclose(gnuplot2);
    pclose(gnuplot3);
    pclose(gnuplot4);

    return 0;
}