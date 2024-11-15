//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColaprioridad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPrioridadKPMC::ColaPrioridadKPMC() {
	vc = new ColaP[MAX_COLA]; //CREA 3 COLAS
	vf = new int[MAX_COLA];
	for (int i = 0; i < MAX_COLA; i++) {
		vf[i] = 1;
	}
	cola_act = 0;
	cant = 0;
}

bool ColaPrioridadKPMC::Vacia() {
	for (int i = 0; i < MAX_COLA; i++) {
		if (!vc[i].Vacia())
			return false;
	}
	return true;
}

void ColaPrioridadKPMC::Primero(int &VALOR) {
	if (!Vacia()) {
		if (!vc[cola_act].Vacia()) {
			if (cant < vf[cola_act])
				//return vc[cola_act].Primero();
					VALOR= vc[cola_act].Primero();
		}
		else {
			while (vc[cola_act].Vacia()) {
				cola_act = (cola_act + 1) % MAX_COLA;
				cant = 0;
			}
			if (cant < vf[cola_act])
//				return vc[cola_act].Primero();
				VALOR= vc[cola_act].Primero();
		}
	}
}

void ColaPrioridadKPMC::Poner(int E, int prioridad) {
	if (prioridad > 0 && prioridad <= MAX_COLA) {
		vc[prioridad - 1].Poner(E);
	}
}

void ColaPrioridadKPMC::Sacar(int &E) {
	if (!Vacia()) {
		if (!vc[cola_act].Vacia()) {
			if (cant < vf[cola_act]) {
				cant++;
				vc[cola_act].Sacar(E);
				if (cant == vf[cola_act]) {
					cola_act = (cola_act + 1) % MAX_COLA;
					cant = 0;
				}
			}
		}
		else {
			while (vc[cola_act].Vacia()) {
				cola_act = (cola_act + 1) % MAX_COLA;
				cant = 0;
			}
			if (cant < vf[cola_act]) {
				cant++;
				vc[cola_act].Sacar(E);
				if (cant == vf[cola_act]) {
					cola_act = (cola_act + 1) % MAX_COLA;
					cant = 0;
				}
			}
		}
	}
}

void ColaPrioridadKPMC::Asignar_frec_prioridad(int frec, int prioridad) {
	if (prioridad > 0 && prioridad <= MAX_COLA) {
		vf[prioridad - 1] = frec;
	}
}

string ColaPrioridadKPMC::Mostrar() {

	string s = "Prioridad: \n";
	for (int i = 0; i < MAX_COLA; i++)
		s += vc[i].Mostrar() + "\n";
	return s;

}