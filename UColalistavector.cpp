//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColalistavector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
using namespace std;

ColaLV::ColaLV(){
	ListaV* l=new ListaV();
}

bool ColaLV::Vacia(){
	return l->vacia();
}

void ColaLV::Poner(int E){
	l->inserta(l->primero(),E);
}

void ColaLV::Sacar(int &E){
	l->recupera(l->fin(),E);
	l->suprime(l->fin());
}

int ColaLV::Primero(){	int E;	l->recupera(l->fin(),E);	return E;}string ColaLV::Mostrar(){
	l->mostrar();
	int E;
	string k="<< ";
	ColaLV* aux=new ColaLV();
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



