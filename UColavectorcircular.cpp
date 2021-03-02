//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColavectorcircular.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
//METODO PRIVADO
direccion ColaVC::siguiente(int dir){
	if(dir == MAXVC - 1)
		return 0;
	else
		return dir + 1;
}
// METODOS PUNLICOS DE LA CLASE COLAVC
ColaVC::ColaVC(){
	fin=0;
	ini=0;	v = new int[MAXVC];}

bool ColaVC::Vacia(){
	return ini==fin;
}

void ColaVC::Poner(int E){
	 if (siguiente(fin) != ini){
		v[fin]=E;
		fin = siguiente(fin);
	 }
}

void ColaVC::Sacar(int &E){
	if (!Vacia()){
		E= v[ini];
		ini = siguiente(ini);
	}
}

int ColaVC::Primero(){	if (!Vacia()) {		return v[ini];
	}}string ColaVC::Mostrar(){
	string k="<< ";
	int E;
	ColaVC* aux=new ColaVC();
	while (!Vacia()){
		Sacar(E);
		//cout<<"INI: "<<ini<<endl;
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
//	cout<<"sig: "<<siguiente(0)<<endl;
//	cout<<"sig: "<<siguiente(1)<<endl;
//	cout<<"sig: "<<siguiente(2)<<endl;
//	cout<<"sig: "<<siguiente(3)<<endl;
//	cout<<"sig: "<<siguiente(4)<<endl;
//	cout<<"sig: "<<siguiente(5)<<endl;
//	cout<<"sig: "<<siguiente(6)<<endl;//si le mando un 6 me devuelve el sig7
	return k+" <<";
}


