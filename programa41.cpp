/*
Programa ejemplo.

*/
#include <stdio.h>
#include <iostream>
class enteros1{
    int x, y;
    public:
        void fijar(int a, int b){
            x=a;
            y=b;
        }    
        void incremento(){
            x++;
            y++;
        }
        int suma1(){
            int c;
            c=x+y;
            return c;
        }
        int valx(){
            return x;
        }
        int valy(){
            return y;
        }        
};   

int main(){
    int a1,a2,a3;
    enteros1 E1;
    E1.fijar(7,-9);
    a1=E1.suma1();
    a2=E1.valx();
    a3=E1.valy();    
    std::cout << "Hola mundo aquí C++" << "\n";
    std::cout << "La suma de "  << a2 << " más " << a3 << " es: " << a1 << "." <<"\n";
    printf("La suma de %d más %d es: %d.\n",a2,a3,a1);     
    return 0;
}

