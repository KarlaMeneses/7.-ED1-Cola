//---------------------------------------------------------------------------

#ifndef UDicolalistavectorH
#define UDicolalistavectorH
//---------------------------------------------------------------------------
#include "UListavector.h"
//added
#include<string>     //without this it makes an error in type string!
using namespace std; //without this it makes an error in type string!

class DicolaLV{
	private:
		ListaV* l;
	public:
		DicolaLV();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		void Poner_frente(int E);		void Sacar_Final(int &E);
		int Ultimo();		string Mostrar();};
#endif
