#include<iostream>
#include<cmath>

using namespace std;

class particula{
	double masa;
	double posicion;
	double velocidad;
	
	public:
//Constructor
	particula(double m, double x, double v){
		masa = m;
		posicion = x;
		velocidad = v;
}
// Destructor
	~particula(){}		
	double momento(){
		return masa*velocidad;
		}
	
};

int main(){
	particula bloque(1.0,0.0,2.0);
	
	bloque.momento();
	
	particula electron(9.1e-31,0.1,5.0e7);
	electron.momento();
	
	cout<<"para la partícula: "<<endl;
	cout<<"momento: "<<bloque.momento()<<endl;
	
	cout<<"para el electrón"<<endl;
	cout<<"momento: "<<electron.momento()<<endl;
	
	return 0;
}
