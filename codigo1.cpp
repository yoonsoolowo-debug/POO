#include<iostream>
using namespace std;

 float suma(float a, float b){
	 return a+b;
 }

int main(){
	float a1, a2, c1;
	a1=12.43;
	a2=2.81;
	c1=suma(a1,a2);
	cout<<"El resultado de "<<a1<<"+"<<a2<<"="<<c1<<endl;
	return 0;
}
