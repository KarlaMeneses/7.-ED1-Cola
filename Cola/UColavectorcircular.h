//---------------------------------------------------------------------------

#ifndef UColavectorcircularH
#define UColavectorcircularH
//---------------------------------------------------------------------------
#include <string>
using namespace std;
const int MAXVC = 6;
typedef int direccion;
class ColaVC{
	private:
		int* v;
		direccion ini;
		direccion fin;
		direccion siguiente(int dir);
	public:
		ColaVC();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		string Mostrar();
};
#endif
