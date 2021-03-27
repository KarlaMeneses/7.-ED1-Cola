//---------------------------------------------------------------------------

#ifndef UDicolalistamemoriaH
#define UDicolalistamemoriaH
//---------------------------------------------------------------------------
#include "UListamemoria.h"

class DicolaLSM{
	private:
		ListaSM* l;
	public:
		DicolaLSM();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento
		int Ultimo();
#endif