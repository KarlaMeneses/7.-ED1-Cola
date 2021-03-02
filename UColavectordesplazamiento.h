//---------------------------------------------------------------------------

#ifndef UColavectordesplazamientoH
#define UColavectordesplazamientoH
//---------------------------------------------------------------------------
#include <string>
using namespace std;
const int MAXVD = 12;
typedef int direccion;
class ColaVD{
	private:
		int* v;
		direccion ini;
		direccion fin;
	public:
		ColaVD();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		string Mostrar();
};
#endif
