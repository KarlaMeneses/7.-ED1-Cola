//---------------------------------------------------------------------------

#ifndef UColaprioridadH
#define UColaprioridadH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "UDicolavectorcircular.h"
#include "UColapuntero.h"
using namespace std;

const int MAX_COLA = 3;

class ColaPrioridadKPMC{
private:
	ColaP* vc;// esto es lo que puede cambiar
	int* vf;  //frecuencia
	int cola_act;
	int cant;

public:
	ColaPrioridadKPMC();
	bool Vacia();
	void Primero(int &VALOR);
	void Poner(int E, int prioridad);
	void Asignar_frec_prioridad(int frec, int prioridad);
	void Sacar(int &E);
	string Mostrar();

};
#endif
