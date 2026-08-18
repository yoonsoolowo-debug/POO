/*
Programa ejemplo 
Operaciones aritmétricas.
Se definen y se inicializan variables
y se utilizan varios operadores.
*/
#include <stdio.h>
int main(){
    int multiplica1(int,int);
    float multiplica2(float,float);    
    int a1, a2, a3, result1;
    int c1, c2, c3, c4;    
    float a4, a5, a6, result2;
    float c5, c6, c7, c8;    
// Inicializa las variables.    
    a1=12;
    a2=3;
    a3=2;
    a4=12.43;
    a5=3.52;
    a6=2.67;
// Operaciones.
    c1=a1+a2;    
    c2=a1-a2;        
    c3=a1/a2; 
    c4=a1*a2;
    c5=a4+a5;    
    c6=a4-a5;        
    c7=a4/a5; 
    c8=a4*a5; 
    result1=multiplica1(a1,a2);  
    result2=multiplica2(a4,a5);                         
// Pesenta las operaciones.    
    printf("La multiplicación de %d por %d es %d. \n", a1, a2, result1);
    printf("La multiplicación de %f por %fd es %f. \n", a4, a5, result2);     
    printf("La suma de a1 mas a2 es c1= %d \n", c1);  
    return 0;
}
//
int multiplica1(int a, int b){
    int c;
    c=a*b;
    return c;
}    
//
float multiplica2(float a, float b){
      float c;
      c=a*b;
      return c;
}   