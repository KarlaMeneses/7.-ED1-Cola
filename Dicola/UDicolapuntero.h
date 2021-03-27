//---------------------------------------------------------------------------

#ifndef UDicolapunteroH
#define UDicolapunteroH
//---------------------------------------------------------------------------
#include <string>
using namespace std; //para el string

struct NodoDC{
	NodoDC* ant;
	int elemento;
	NodoDC* sig;  //Puntero a Nodo
};
//typedef NodoC* direccion;
class DColaP{
	private:
		NodoDC*  ini;
		NodoDC*  fin;
	public:
		DColaP();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento        void Poner_frente(int E);		string Mostrar();
};

#endif
