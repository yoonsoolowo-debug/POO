/*
Programa de cinemática
06.08.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co

*/
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

struct Vector3{
    double x;
    double y;
    double z;
};

Vector3 suma(Vector3 a, Vector3 b){
    Vector3 r;

    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;

    return r;
}

Vector3 producto(Vector3 a, double k){
    Vector3 r;

    r.x = a.x * k;
    r.y = a.y * k;
    r.z = a.z * k;

    return r;
}

Vector3 posicion(Vector3 r0, Vector3 v0, Vector3 a, double t){
    Vector3 r;

    r = suma(suma(r0, producto(v0,t)), producto(a,0.5*t*t));

    return r;
}

Vector3 velocidad(Vector3 v0, Vector3 a, double t){
    Vector3 v;

    v = suma(v0, producto(a,t));

    return v;
}

double norma(Vector3 v){
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vector3 desplazamiento(Vector3 r0, Vector3 rf){
    Vector3 d;

    d.x = rf.x - r0.x;
    d.y = rf.y - r0.y;
    d.z = rf.z - r0.z;

    return d;
}

void imprimir(Vector3 v){
    cout << "("
         << v.x << ", "
         << v.y << ", "
         << v.z << ")"
         << endl;
}

int main(){

    Vector3 r0, v0, a;
    Vector3 rf, vf;
    Vector3 d;

    double t;

    cout<<"Ingrese las componentes de la posición inicial:"<<endl;
    cout<<"x = ";
    cin>>r0.x;
    cout<<"y = ";
    cin>>r0.y;
    cout<<"z = ";
    cin>>r0.z;

    cout<<endl;

    cout<<"Ingrese las componentes de la posición inicial:"<<endl;
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

    cout<<"Desplazamiento:"<<endl;
    imprimir(d);

    cout<<endl;

    cout<<"Magnitud del desplazamiento = "
        << norma(d)
        << endl;
        
    ofstream archposicion("posicion.dat");
	ofstream archvelocidad("velocidad.dat");
	ofstream archtrayectoria("trayectoria.dat");

	double dt = t/9.0;

	for(int i = 0; i < 10; i++){
	
    double ti = i * dt;

    Vector3 rp = posicion(r0,v0,a,ti);
    Vector3 vp = velocidad(v0,a,ti);

    archposicion<<ti<< " "<<rp.x<<" "<<rp.y<<" "<<rp.z<<endl;

    archvelocidad<<ti<<" "<<vp.x<<" "<< vp.y<<" "<<vp.z<<endl;

    archtrayectoria<<rp.x<<" "<<rp.y<<" "<<rp.z<<endl;
}

	archposicion.close();
	archvelocidad.close();
	archtrayectoria.close();
    return 0;
}
