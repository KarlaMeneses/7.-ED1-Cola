//---------------------------------------------------------------------------

#ifndef UColamemoriaH
#define UColamemoriaH
//---------------------------------------------------------------------------
//added
#include "Umemoria.h"
#include<string>       //without this it makes an error in type string!
using namespace std;   //without this it makes an error in type string!

//When uso simulacion de memoria add estas 3 consts it makes more easy to use!!!
const string datoC = "elemento,sig";
const string elementoC = "->elemento";
const string sigC = "->sig";

typedef int direccion;

class ColaM{
	private:
		direccion ini;
		direccion fin;
		CSMemoria* mem;
	public:
		ColaM();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero();		string Mostrar();
		void Mostrarmemoria();
};
#endif
