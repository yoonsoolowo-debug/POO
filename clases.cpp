#include<iostream>
using namespace std;

class gato{
	public:
	unsigned int edad;
	unsigned int peso;
	
	void maullar(){
		cout<<"miau~"<<endl;
	}
};

int main(){

	gato pelusa;
	pelusa.edad=5;
	
	
	cout<<"Pelusa es mi gato y tiene "<<pelusa.edad<<" años de edad"<<endl;
	cout<<"Mi gato hace: "<<endl;
	pelusa.maullar();
	
	return 0;
}
