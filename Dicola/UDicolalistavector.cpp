//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolalistavector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//added
#include <iostream>
using namespace std;

DicolaLV::DicolaLV(){
	ListaV* l=new ListaV();
	//l->mostrar();
}

bool DicolaLV::Vacia(){
	return l->vacia();
}

void DicolaLV::Poner(int E){
	int k=l->primero();//prueba
	l->inserta(k,E);
	//l->inserta_primero(E);
	l->mostrar();
}

void DicolaLV::Sacar(int &E){
	l->recupera(l->fin(),E);
	l->suprime(l->fin());
}

int DicolaLV::Primero(){
	l->recupera(l->primero(),E);
	l->suprime(l->primero());
}

int DicolaLV::Ultimo(){
	//l->mostrar();
	int E;
	string k="<< ";   /*
	DicolaLV* aux=new DicolaLV();
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
	}              */
	return k+" <<";
}