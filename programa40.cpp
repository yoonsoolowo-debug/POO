/*
Programa ejemplo.

*/
#include <stdio.h>
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
    printf("La suma de %d y %d es %d.\n",a2,a3,a1);     
    return 0;
}

