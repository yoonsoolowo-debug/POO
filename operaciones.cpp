/*
Programa de operaciones
05.08.2026
Alan Nathaniel Acosta Valderrama
Código: 20232135005
anacostav@udistrital.edu.co
Este programa le permite al usuario realizar operaciones entre dos números haciendo una comparación de magnitud entre los número ingresados y el resultado por operación: suma, resta, potencia y raíz.
*/
#include<iostream>
#include<cmath>

using namespace std;

float suma(float d, float e){
    return d+e;
    }
float resta(float f, float g){
    return f-g;
    }
float pot(float j, float k){
    return pow(j, k);
    }

float div(float n, float o){
    return n/o;
    }

float raiz(float r, float s){
    return pow(r,1.0/s);
    }

bool validardiv(float v){
	if (v==0){
		cout<<"Error: no se puede dividir entre cero."<<endl;
		return false;
	}
	return true;
}   
bool validarraiz(float w){
	if (w==0){
		cout<<"Error: el índice de la raíz no puede ser cero."<<endl;
		return false;
	}
	return true;
}   
void comparar(float x, float y, float z){
	if(z>y)
        cout<<"c es mayor que b"<<endl;
    else if(y>z)
        cout<<"b es mayor que c"<<endl;
    else
        cout<<"b y c son iguales"<<endl;

    if(z>x)
        cout<<"c es mayor que a"<<endl;
    else if(x>z)
        cout<<"a es mayor que c"<<endl;
    else
        cout<<"a y c son iguales"<<endl;
}

int main() {
	float a, b, c;
	cout<<"Ingresa el valor de a:"<<endl;
	cin>>a;
	cout<<"Ingresa el valor de b:"<<endl;
	cin>>b;
	c=suma(a,b);
	cout<<"La suma: a + b = "<<c<<endl;
	comparar(a,b,c);
	
	c=resta(a,b);
	cout<<"La resta: a - b = "<<c<<endl;
	comparar(a,b,c);
	
	c=resta(b,a);
	cout<<"La resta: b - a = "<<c<<endl;
	comparar(a,b,c);
	
	c=pot(a,b);
	cout<<"La potencia: a^(b) = "<<c<<endl;
	comparar(a,b,c);
	
	c=pot(b,a);
	cout<<"La potencia: b^(a) = "<<c<<endl;
	comparar(a,b,c);
	
	if(validardiv(b)){
    c = div(a,b);
	cout<<"La división: a/b = "<<c<<endl;
	comparar(a,b,c);
	}

	if(validardiv(a)){
    c = div(b,a);
	cout<<"La división: b/a = "<<c<<endl;
	comparar(a,b,c);
	}
	
	if(validarraiz(b)){
    c = raiz(a,b);
	cout<<"La raiz: a^(1/b) = "<<c<<endl;
	comparar(a,b,c);
	}
		
	if(validarraiz(a)){
    c = raiz(b,a);
	cout<<"La raiz: b^(1/a) = "<<c<<endl;
	comparar(a,b,c);
	}	
		
	return 0;
}
