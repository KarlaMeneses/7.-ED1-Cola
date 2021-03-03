//---------------------------------------------------------------------------

#ifndef UDicolalistavectorH
#define UDicolalistavectorH
//---------------------------------------------------------------------------
#include "UListavector.h"

class DicolaLV{
	private:
		ListaV* l;
	public:
		DicolaLV();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento
		int Ultimo();
#endif