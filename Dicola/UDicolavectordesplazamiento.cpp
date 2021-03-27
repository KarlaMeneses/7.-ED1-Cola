//---------------------------------------------------------------------------
#pragma hdrstop
#include "UDicolavectordesplazamiento.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
// METODOS DE LA CLASE DicolaVD
DicolaVD::DicolaVD(){
	fin=0;
	ini=0;	v = new int[MAXDVD];}

bool DicolaVD::Vacia(){
	return ini==fin;
}

void DicolaVD::Poner(int E){
	 if (fin<MAXDVD){
		v[fin]=E;
		fin = fin +1;
	 }
}

void DicolaVD::Sacar(int &E){
	if (!Vacia()){
		E= v[0];
		for(int i = 0;i < fin; i++){
			v[i] = v[i + 1];
		}
		fin = fin -1;
	}
}

int DicolaVD::Primero(){	if (!Vacia()) {		return v[0];
	}}void DicolaVD::Poner_frente(int E){// 4-5-6-7-8-9	if (fin<MAXDVD){		fin = fin +1;		for(int i = fin-1;i > 0; i--){
			v[i] = v[i - 1];
		}
		v[ini]=E;
	}}int DicolaVD::finc(){	return fin;}int DicolaVD::inic(){	return ini;}void DicolaVD::Sacar_Final(int &E){
	if (!Vacia()){
		E= v[fin-1];
		fin = fin -1;
	}
}

int DicolaVD::Ultimo(){	if (!Vacia()) {		return v[fin-1];
	}}string DicolaVD::Mostrar(){
	string k="<< ";
	int E;
	DicolaVD* aux=new DicolaVD();
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