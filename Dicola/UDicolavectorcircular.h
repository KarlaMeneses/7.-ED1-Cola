//---------------------------------------------------------------------------

#ifndef UDicolavectorcircularH
#define UDicolavectorcircularH
//---------------------------------------------------------------------------
#include <string>
using namespace std;
const int MAXDVC = 8;
typedef int direccion;
class DicolaVC{
	private:
		int* v;
		direccion ini;
		direccion fin;
		direccion siguiente(int dir);
		int anterior(int dir);
	public:
		DicolaVC();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento		void Poner_frente(int E);		int inic();		void Sacar_Final(int &E);
		int Ultimo();		string Mostrar();
};
#endif
