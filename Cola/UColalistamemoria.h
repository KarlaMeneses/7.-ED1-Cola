//---------------------------------------------------------------------------

#ifndef UColalistamemoriaH
#define UColalistamemoriaH
//---------------------------------------------------------------------------
#include "UListamemoria.h"

class ColaLSM{
	private:
		ListaSM* l;
	public:
		ColaLSM();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		string Mostrar();};
#endif
