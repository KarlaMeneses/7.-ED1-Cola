//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColavectordesplazamiento.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
// METODOS DE LA CLASE COLAVD
ColaVD::ColaVD(){
	fin=0;
	ini=0;

bool ColaVD::Vacia(){
	return ini==fin;
}

void ColaVD::Poner(int E){
	 if (fin<MAXVD){
		v[fin]=E;
		fin = fin +1;
	 }
}

void ColaVD::Sacar(int &E){
	if (!Vacia()){
		E= v[0];
		for(int i = 0;i < fin; i++){
			v[i] = v[i + 1];
		}
		fin = fin -1;
	}
}

int ColaVD::Primero(){
	}
	string k="<< ";
	int E;
	ColaVD* aux=new ColaVD();
	while (!Vacia()){
		Sacar(E);
		aux->Poner(E);
		k=k+to_string(E);
		if (!Vacia()) {
			k+=',';
		}

	}
	while (!aux->Vacia()){
		aux->Sacar(E);
		Poner(E);
	}
	return k+" <<";
}