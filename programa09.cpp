/*
Programa de funciones para operaciones de número enteros y decimales                                                                                          
06.08.2026                                                                                                        
Alan Nathaniel Acosta Valderrama                                                                                  
Código: 20232135005                                                                                               
anacostav@udistrital.edu.co
El código presente realiza distintas operaciones aritméticas: suma, resta, multiplicación, división, potencia y raiz, para número de tipo entero y punto flotante, los cuales ya están definidos.
Las operaciones realizadas se operan mediante el uso de funciones.
*/
#include<iostream>
#include<cmath>
using namespace std;

int suma1(int a, int b){
    return a+b;
}    
//
float suma2(float a, float b){
      return a+b;
}   
int resta1(int a, int b){
    return a-b;
}    
//
float resta2(float a, float b){
      return a-b;
}
int division1(int a, int b){
    return a/b;
}    
//
float division2(float a, float b){
      return a/b;
}   
int multiplica1(int a, int b){
    return a*b;
}    
//
float multiplica2(float a, float b){
      return a*b;
}
int potencia1(int a, int b){
    return pow(a,b);
}    
//
float potencia2(float a, float b){
      return pow(a,b);
}
int raiz1(int a, int b){
    return pow(a,1.0/b);
}    
//
float raiz2(float a, float b){
      return pow(a, 1/b);
}   

int main(){
    int multiplica1(int,int);
    float multiplica2(float,float);    
    int a1, a2, a3, result1,result3, result5, result7, result9,result11;
    float a4, a5, a6, result2,result4,result6,result8,result10,result12;
    a1=12;
    a2=3;
    a3=2;
    a4=12.43;
    a5=3.52;
    a6=2.67;
    
    result1=multiplica1(a1,a2);  
    result2=multiplica2(a4,a5);
    result3=resta1(a1,a3);
    result4=resta2(a5,a4);
    result5=division1(a3,a1);                        
    result6=division2(a4,a6);
    result7=suma1(a1,a2);
    result8=suma2(a5,a6);
    result9=potencia1(a3,a1);
    result10=potencia2(a5,a6);
    result11=raiz1(a1,a3);
    result12=raiz2(a5,a4);
    
    cout<<"Los valores son:"<<endl;
	cout<<"a1 = "<<a1<<endl;
	cout<<"a2 = "<<a2<<endl;
	cout<<"a3 = "<<a3<<endl;
	cout<<"a4 = "<<a4<<endl;
	cout<<"a5 = "<<a5<<endl;
	cout<<"a6 = "<<a6<<endl;

    
	cout<<"La multiplicación de "<<a1<<" por "<<a2<<" es "<<result1<<"."<<endl;
	cout<<"La multiplicación de "<<a4<<" por "<<a5<<" es "<<result2<<"."<<endl;

	cout<<"La resta de "<<a1<<" menos "<<a3<<" es "<<result3<<"."<<endl;
	cout<<"La resta de "<<a5<<" menos "<<a4<<" es "<<result4<<"."<<endl;

	cout<<"La división de "<<a3<<" entre "<<a1<<" es "<<result5<<"."<<endl;
	cout<<"La división de "<<a4<<" entre "<<a6<<" es "<<result6<<"."<<endl;

	cout<<"La suma de "<<a1<<" más "<<a2<<" es "<<result7<<"."<<endl;
	cout<<"La suma de "<<a5<<" más "<<a6<<" es "<<result8<<"."<<endl;

	cout<<"La potencia de "<<a3<<" elevada a "<<a1<<" es "<<result9<<"."<<endl;
	cout<<"La potencia de "<<a5<<" elevada a "<<a6<<" es "<<result10<<"."<<endl;

	cout<<"La raíz de "<<a1<<" con índice "<<a3<<" es "<<result11<<"."<<endl;
	cout<<"La raíz de "<<a5<<" con índice "<<a4<<" es "<<result12<<"."<<endl;

    return 0;
}
