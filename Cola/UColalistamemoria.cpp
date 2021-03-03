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
	l->inserta(l->fin(),E);
	//l->inserta_ultimo(E);
	//l->mostrar();
}

void ColaLSM::Sacar(int &E){
	if (!Vacia()) {
		l->recupera(l->primero(),E);
		l->suprime(l->primero());

	}else{
		cout<<"La memoria (COLA) ya esta vacia no se puede sacar elemento"<<endl;
	}
}

int ColaLSM::Primero(){	int E;	l->recupera(0,E);	return E;}string ColaLSM::Mostrar(){
	cout<<l->mostrar()<<endl;
	int E;
	string k="COLA: << ";
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
	return k+" <<\n";
}

