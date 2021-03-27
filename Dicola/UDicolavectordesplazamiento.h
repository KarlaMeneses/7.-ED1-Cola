//---------------------------------------------------------------------------

#ifndef UDicolavectordesplazamientoH
#define UDicolavectordesplazamientoH
//---------------------------------------------------------------------------
#include <string>
using namespace std;
const int MAXDVD = 12;
typedef int direccion;
class DicolaVD{
	private:
		int* v;
		direccion ini;
		direccion fin;
	public:
		DicolaVD();
		bool Vacia();
		void Poner(int E);
		void Sacar(int &E);
		int Primero(); // Tipoelemento
		int Ultimo();
		int finc();
		int inic();
};
#endif