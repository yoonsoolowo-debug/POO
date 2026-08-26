/*
Programa de cinemática
06.08.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co
Este programa simula un MRUA, le permite al usuario ingresar datos de posición inicial, velocida inicial, aceleración constante y tiempo transcurrido. Le entrega al usuario la posición final, desplazamiento, velocidad final y un cojunto de archivos datos .data para la graficación de r(t), v(t) y trayectoria.
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct vector{double x,y;};

vector suma(vector a, vector b){
    vector r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

vector producto(vector a, double k){
    vector r;
    r.x = a.x * k;
    r.y = a.y * k;
    return r;
}

vector posicion(vector r0, vector v0, vector a, double t){
    vector r;
    r = suma(suma(r0, producto(v0,t)), producto(a,0.5*t*t));
    return r;
}

vector velocidad(vector v0, vector a, double t){
    vector v;
    v = suma(v0, producto(a,t));
    return v;
}

double norma(vector v){
    return sqrt(v.x*v.x + v.y*v.y);
}

vector desplazamiento(vector r0, vector rf){
    vector d;
    d.x = rf.x - r0.x;
    d.y = rf.y - r0.y;
    return d;
}

void imprimir(vector v){
    cout<<"("<<v.x<<", "<<v.y<<")"<<endl;
}

int main(){

    vector r0, v0, a;
    vector rf, vf;
    vector d;

    double t;
	cout<<"Bienvenid@."<<endl;
	cout<<"En este programa se simula un movimiento rectilíneo uniformemente acelerado en el plano cartesiano de una partícula. Usted tiene la libertad de poner las componentes (x, y e z) de la posición inicial, velocidad inicial y la aceleración que se admite constante, por consiguiente usted proporcionará al programa el tiempo transcurrido para calcular la posición final, velocidad final, desplazamiento total y un conjunto de datos .dat para la graficación de la posición, velocidad y trayectoria de la partícula en el tiempo dado."<<endl;
    cout<<endl;
    
    r0.x=-5.6;
    r0.y=7.8;

    v0.x=9.3;
    v0.y=-6.5;
    
	a.x=-4.2;
    a.y=6.4;

    t=5.1;

    rf = posicion(r0,v0,a,t);
    vf = velocidad(v0,a,t);
    d = desplazamiento(r0,rf);

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

    cout<<"Aceleracion:"<<endl;
    imprimir(a);
    cout<<endl;
    cout<<"Magnitud de la aceleración = "<<norma(a)<<endl;

    cout<<"Posicion final:"<<endl;
    imprimir(rf);
    cout<<endl;

    cout<<"Velocidad final:"<<endl;
    imprimir(vf);
    cout<<endl;
    cout<<"Magnitud de la velocidad en t=0; v = "<<norma(v0)<<endl;
    cout<<"Magnitud de la velocidad en t=5.1; v = "<<norma(vf)<<endl;


    cout<<"Desplazamiento total de la partícula:"<<endl;
    imprimir(d);
	cout<<endl;

    cout<<"Magnitud del desplazamiento = "<<norma(d)<<endl;
        
    ofstream archposicion("posicion.dat");
	ofstream archvelocidad("velocidad.dat");
	ofstream archtrayectoria("trayectoria.dat");

	double dt = t/9.0;
	for(int i = 0; i < 10; i++){
    double ti = i * dt;
    vector rp = posicion(r0,v0,a,ti);
    vector vp = velocidad(v0,a,ti);

    archposicion<<ti<< " "<<rp.x<<" "<<rp.y<<endl;
    archvelocidad<<ti<<" "<<vp.x<<" "<< vp.y<<endl;
    archtrayectoria<<rp.x<<" "<<rp.y<<endl;
}

	archposicion.close();
	archvelocidad.close();
	archtrayectoria.close();
	
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
