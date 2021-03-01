//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColalistamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
using namespace std;

ColaLSM::ColaLSM(){
	l=new ListaSM();
}

bool ColaLSM::Vacia(){
	return l->vacia();
}

void ColaLSM::Poner(int E){
	l->inserta(l->primero(),E);
}

void ColaLSM::Sacar(int &E){
	l->recupera(l->fin(),E);
	l->suprime(l->fin());
}

int ColaLSM::Primero(){	int E;	l->recupera(l->fin(),E);	return E;}string ColaLSM::Mostrar(){
	l->mostrar();
	int E;
	string k="<< ";
	ColaLSM* aux=new ColaLSM();
	while (!Vacia()){
		Sacar(E);
		k=k+to_string(E);
		aux->Poner(E);
		if (!Vacia()) {
			k=k+',';
		}
	}
	while (!aux->Vacia()){
		aux->Sacar(E);
		Poner(E);
	}
	return k+" <<";
}

