//---------------------------------------------------------------------------

#ifndef UColamemoriaH
#define UColamemoriaH
//---------------------------------------------------------------------------
#include<string>       //without this it makes an error in type string!
using namespace std;   //without this it makes an error in type string!

typedef int direccion;
class ColaM{
	private:
		direccion ini;
		direccion fin;
	public:
		ColaM();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero();

};
#endif