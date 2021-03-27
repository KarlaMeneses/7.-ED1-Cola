//---------------------------------------------------------------------------

#ifndef UColapunteroH
#define UColapunteroH
//---------------------------------------------------------------------------
#include <string>
using namespace std; //para el string

struct NodoC{
	int elemento;
	NodoC* sig;  //Puntero a Nodo
};
//typedef NodoC* direccion;
class ColaP{
	private:
		NodoC*  ini;
		NodoC*  fin;
	public:
		ColaP();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		string Mostrar();
};

#endif
