//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColalistapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
using namespace std;

ColaLP::ColaLP(){
	l=new ListaP();
}

bool ColaLP::Vacia(){
	return l->vacia();
}

void ColaLP::Poner(int E){
	l->inserta(l->primero(),E);
}

void ColaLP::Sacar(int &E){
	l->recupera(l->fin(),E);
	l->suprime(l->fin());
}

int ColaLP::Primero(){	int E;	l->recupera(l->fin(),E);	return E;}string ColaLP::Mostrar(){
	cout<<l->mostrar()<<endl;
	int E;
	string k="<< ";
	ColaLP* aux=new ColaLP();
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
