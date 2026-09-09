#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdio>

using namespace std;

double fuerza(double x){
	return -62.720*x+10.464*pow(x,3)-0,544*pow(x,5);
}

double aceleracion(double x, double m){
	return fuerza(x)/m;
}

int main(){
	double  x0, v0, t0, tf, m;
	int N;
	
	m=3.2;
	
	x0=1.1;
	v0=0.0;
	
	t0=0.0;
	tf=6.7;
	
    cout<<"Bienvenid@."<<endl;
    cout<<"Este programa simula el movimiento de un objeto sobre el eje x."<<endl;
    cout<<"Se utilizan los métodos de Euler y Euler mejorado."<<endl;
    cout<<endl;
	
	cout<<"Masa = "<<m<<" kg"<<endl;
	cout<<"Posición inicial = "<<x0<<" m"<<endl;
	cout<<"Velocidad inicial = "<<v0<<" m/s"<<endl;
	cout<<"Tiempo inicial = "<<t0<<" s"<<endl;
	cout<<"Tiempo final = "<<tf<<" s"<<endl;
	
	cout<<"Ingrese el numero de pasos (N): ";
    cin>>N;	
	
	double h=(tf-t0)/N;
	//Para el método de Euler
	
	double te=t0;
    double xe=x0;
    double ve=v0;
    double ae=aceleracion(xe, m);

    ofstream euler_posicion("euler_posicion.dat");
    ofstream euler_velocidad("euler_velocidad.dat");
    ofstream euler_aceleracion("euler_aceleracion.dat");

    if(!euler_posicion || !euler_velocidad || !euler_aceleracion){
        cerr<<"No se pudieron crear los archivos .dat"<<endl;
        return 1;
    }

    euler_posicion<<te<<" "<<xe<<endl;
    euler_velocidad<<te<<" "<<ve<<endl;
    euler_aceleracion<<te<<" "<<ae<<endl;

    for(int i=0;i<N;i++){

        double xe=xe+h*ve;
        double ve=ve+h*ae;

        double ae=aceleracion(xe, m);

        ae=aceleracion(xe, m);

        te=te+h;

        euler_posicion<<te<<" "<<xe<<endl;
        euler_velocidad<<te<<" "<<ve<<endl;
        euler_aceleracion<<te<<" "<<ae<<endl;
    }

    euler_posicion.close();
    euler_velocidad.close();
    euler_aceleracion.close();
	
	//Para Euler mejorado
	
	double tm=t0;
    double xm=x0;
    double vm=v0;
    double am=aceleracion(xm, m);

    ofstream mejorado_posicion("mejorado_posicion.dat");
    ofstream mejorado_velocidad("mejorado_velocidad.dat");
    ofstream mejorado_aceleracion("mejorado_aceleracion.dat");

    if(!mejorado_posicion || !mejorado_velocidad || !mejorado_aceleracion){
        cerr<<"No se pudieron crear los archivos .dat"<<endl;
        return 1;
    }

    mejorado_posicion<<tm<<" "<<xm<<endl;
    mejorado_velocidad<<tm<<" "<<vm<<endl;
    mejorado_aceleracion<<tm<<" "<<am<<endl;

    for(int i=0;i<N;i++){

        double xp=xm+h*vm;
        double vp=vm+h*am;

        double ap=aceleracion(xp, m);
        
        xm=xm+(h/2.0)*(vm+vp);
        vm=vm+(h/2.0)*(am+ap);
		am=aceleracion(xm, m);
        tm=tm+h;
        
        mejorado_posicion<<tm<<" "<<xm<<endl;
        mejorado_velocidad<<tm<<" "<<vm<<endl;
        mejorado_aceleracion<<tm<<" "<<am<<endl;
    }

    mejorado_posicion.close();
    mejorado_velocidad.close();
    mejorado_aceleracion.close();
    
    //Graficador
    
        FILE *gnuplot1=popen("gnuplot -persist","w");

    if(gnuplot1==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot1,"set grid\n");
    fprintf(gnuplot1,"set title \"Posicion vs Tiempo\"\n");
    fprintf(gnuplot1,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot1,"set ylabel \"Posicion (m)\"\n");
    fprintf(gnuplot1,"plot \"euler_posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler\", \"mejorado_posicion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"x(t)\"\n");

    FILE *gnuplot2=popen("gnuplot -persist","w");

    if(gnuplot2==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot2,"set grid\n");
    fprintf(gnuplot2,"set title \"Velocidad vs Tiempo\"\n");
    fprintf(gnuplot2,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot2,"set ylabel \"Velocidad (m/s)\"\n");
    fprintf(gnuplot2,"plot \"euler_velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler\", \"mejorado_velocidad.dat\" using 1:2 with linespoints pt 6 ps 1 title \"x(t)\"\n");

    FILE *gnuplot3=popen("gnuplot -persist","w");

    if(gnuplot3==NULL){
        cerr<<"No se pudo ejecutar Gnuplot"<<endl;
        return 1;
    }

    fprintf(gnuplot3,"set grid\n");
    fprintf(gnuplot3,"set title \"Aceleracion vs Tiempo\"\n");
    fprintf(gnuplot3,"set xlabel \"Tiempo (s)\"\n");
    fprintf(gnuplot3,"set ylabel \"Aceleracion (m/s^2)\"\n");
    fprintf(gnuplot3,"plot \"euler_aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"Euler\", \"mejorado_aceleracion.dat\" using 1:2 with linespoints pt 6 ps 1 title \"x(t)\"\n");


    pclose(gnuplot1);
    pclose(gnuplot2);
    pclose(gnuplot3);

	return 0;
}
