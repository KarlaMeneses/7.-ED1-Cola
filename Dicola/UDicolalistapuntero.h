//---------------------------------------------------------------------------

#ifndef UDicolalistapunteroH
#define UDicolalistapunteroH
//---------------------------------------------------------------------------
#include "UListapuntero.h"

class DicolaLP{
	private:
		ListaP* l;
	public:
		DicolaLP();
		bool Vacia();
		int Primero(); // Tipoelemento
		void Poner(int E);
		void Sacar(int &E);
		void Poner_frente(int E);
		void Sacar_Final(int &E);
		int Ultimo();
		string Mostrar();};
#endif
