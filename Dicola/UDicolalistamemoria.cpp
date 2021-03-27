//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolalistamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//added
#include <iostream>
using namespace std;

DicolaLSM::DicolaLSM(){
	l=new ListaSM();
}

bool DicolaLSM::Vacia(){
	return l->vacia();
}

void DicolaLSM::Poner(int E){
	//cout<<"fin c111:"<< l->fin()<<endl;
	l->inserta(l->fin(),E);
		//cout<<"fin c222:"<< l->fin()<<endl;
	//l->inserta_ultimo(E);
	//l->mostrar();
}

void DicolaLSM::Sacar(int &E){
	if (!Vacia()) {
		l->recupera(l->primero(),E);
		//cout<<"Recupera: "<<E<<endl;
		l->suprime(l->primero());

	}else{
		cout<<"La memoria (COLA) ya esta vacia no se puede sacar elemento"<<endl;
	}
}

int DicolaLSM::Primero(){	int E;	l->recupera(0,E);	return E;}void DicolaLSM::Poner_frente(int E){	l->inserta_primero(E);}void DicolaLSM::Sacar_Final(int &E){
if (!Vacia()) {
	//cout<<"fin de sacar mostrar:"<< l->fin()<<endl;
		l->recupera(l->fin(),E);
		l->suprime(l->fin());
//cout<<"despues de sacar final: "<<endl;

	}else{
		cout<<"La memoria (COLA) ya esta vacia no se puede sacar elemento"<<endl;
	}
}

int DicolaLSM::Ultimo(){	int E;	l->recupera(l->primero(),E);	return E;}string DicolaLSM::Mostrar(){
	cout<<l->mostrar()<<endl;
	int E;
	string k="COLA: << ";
	DicolaLSM* aux=new DicolaLSM();
	while (!Vacia()){
		//cout<<l->mostrar()<<endl;
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
