//---------------------------------------------------------------------------

#ifndef UColalistapunteroH
#define UColalistapunteroH
//---------------------------------------------------------------------------
#include "UListapuntero.h"

class ColaLP{
	private:
		ListaP* l;
	public:
		ColaLP();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		string Mostrar();};
#endif
