//---------------------------------------------------------------------------

#ifndef UColalistavectorH
#define UColalistavectorH
//---------------------------------------------------------------------------
#include "UListavector.h"

class ColaLV{
	private:
		ListaV* l;
	public:
		ColaLV();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		string Mostrar();};
#endif
