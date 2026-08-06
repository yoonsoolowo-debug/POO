/*
Programa de cinemática
06.08.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co
Este programa simula un MRUA, le permite al usuario ingresar datos de posición inicial, velocida inicial, aceleración constante y tiempo transcurrido. Le entrega al usuario la posición final, desplazamiento, velocidad final y un cojunto de archivos datos .data para la graficación de r(t), v(t) y trayectoria.
*/
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

struct vector{double x,y,z;};

vector suma(vector a, vector b){
    vector r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

vector producto(vector a, double k){
    vector r;
    r.x = a.x * k;
    r.y = a.y * k;
    r.z = a.z * k;
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
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vector desplazamiento(vector r0, vector rf){
    vector d;
    d.x = rf.x - r0.x;
    d.y = rf.y - r0.y;
    d.z = rf.z - r0.z;
    return d;
}

void imprimir(vector v){
    cout<<"("<<v.x<<", "<<v.y<<", "<<v.z<<")"<<endl;
}

int main(){

    vector r0, v0, a;
    vector rf, vf;
    vector d;

    double t;
	cout<<"Bienvenid@."<<endl;
	cout<<"En este programa se simula un movimiento rectilíneo uniformemente acelerado en el plano cartesiano de una partícula. Usted tiene la libertad de poner las componentes (x, y e z) de la posición inicial, velocidad inicial y la aceleración que se admite constante, por consiguiente usted proporcionará al programa el tiempo transcurrido para calcular la posición final, velocidad final, desplazamiento total y un conjunto de datos .dat para la graficación de la posición, velocidad y trayectoria de la partícula en el tiempo dado."<<endl;
    cout<<endl;
    
    cout<<"Ingrese las componentes de la posición inicial:"<<endl;
    cout<<"x = ";
    cin>>r0.x;
    cout<<"y = ";
    cin>>r0.y;
    cout<<"z = ";
    cin>>r0.z;
    cout<<endl;

    cout<<"Ingrese las componentes de la velocidad inicial:"<<endl;
    cout<<"vx = ";
    cin>>v0.x;
    cout<<"vy = ";
    cin>>v0.y;
    cout<<"vz = ";
    cin>>v0.z;
    cout<<endl;

    cout<<"Ingrese las componentes de la aceleración constante:"<<endl;
    cout<<"ax = ";
    cin>>a.x;
    cout<<"ay = ";
    cin>>a.y;
    cout<<"az = ";
    cin>>a.z;
    cout<<endl;

    cout<<"Ingrese el valor del tiempo transcurrido: ";
    cin>>t;
    cout<<endl;

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

    cout<<"Posicion final:"<<endl;
    imprimir(rf);
    cout<<endl;

    cout<<"Velocidad final:"<<endl;
    imprimir(vf);
    cout<<endl;

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

    archposicion<<ti<< " "<<rp.x<<" "<<rp.y<<" "<<rp.z<<endl;
    archvelocidad<<ti<<" "<<vp.x<<" "<< vp.y<<" "<<vp.z<<endl;
    archtrayectoria<<rp.x<<" "<<rp.y<<" "<<rp.z<<endl;
}

	archposicion.close();
	archvelocidad.close();
	archtrayectoria.close();
    return 0;
}
