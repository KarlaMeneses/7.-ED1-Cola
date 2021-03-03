//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolalistapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
using namespace std;

DicolaLP::DicolaLP(){
	l=new ListaP();
}

bool DicolaLP::Vacia(){
	return l->vacia();
}

int DicolaLP::Primero(){
	int E;	l->recupera(l->fin(),E);	return E;}

void DicolaLP::Poner(int E){
	l->inserta(l->primero(),E);
}

void DicolaLP::Sacar(int &E){
	l->recupera(l->fin(),E);
	l->suprime(l->fin());
}

void DicolaLP::Poner_frente(int E){	l->inserta_ultimo(E);}void DicolaLP::Sacar_Final(int &E){
	l->recupera(l->primero(),E);
	l->suprime(l->primero());
}

int DicolaLP::Ultimo(){	int E;	l->recupera(l->primero(),E);	return E;}string DicolaLP::Mostrar(){
	cout<<l->mostrar()<<endl;
	int E;
	string k="<< ";
	DicolaLP* aux=new DicolaLP();
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