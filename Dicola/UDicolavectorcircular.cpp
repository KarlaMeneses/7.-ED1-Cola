//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolavectorcircular.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//added
#include <iostream>
//METODO PRIVADO
direccion DicolaVC::siguiente(int dir){
	if(dir == MAXDVC - 1)
		return 0;
	else
		return dir + 1;
}

int DicolaVC::anterior(int dir) {
	if (dir == 0)
		return MAXDVC - 1;
	else
		return dir - 1;
}
// METODOS PUBLICOS DE LA CLASE DicolaVC
DicolaVC::DicolaVC(){
	fin=-1;
	ini=0;	v = new int[MAXDVC];}

bool DicolaVC::Vacia(){
	return siguiente(fin)==ini;  //ini==fin;
}

void DicolaVC::Poner(int E){
	 if (siguiente(siguiente(fin))!= ini){
		v[siguiente(fin)]=E;
		fin = siguiente(fin);
	 }
	 //mi fin tendra el valor de la casilla perdida
}

void DicolaVC::Sacar(int &E){
	if (!Vacia()){
		E= v[ini];
		ini = siguiente(ini);
	}
}

int DicolaVC::Primero(){	if (!Vacia()) {		return v[ini];
	}}void DicolaVC::Poner_frente(int E){	if (Vacia()) {		if (siguiente(siguiente(fin)) != ini){
			v[siguiente(fin)]=E;
			fin = siguiente(fin);
		}
	}else{		if (siguiente(siguiente(fin)) != ini){			ini = anterior(ini);
			v[ini] = E;
		}
	}/*	if (Vacia()) {		if (siguiente(fin) != ini){
			v[fin]=E;
			fin = siguiente(fin);
		}
	}else{		if (siguiente(fin) != ini){			for (int i = fin; i > 0; i--){					v[i] = v[i - 1];
			}
			fin = siguiente(fin);
			v[ini] = E;
		}
	}         */


}int DicolaVC::inic(){	return ini;}void DicolaVC::Sacar_Final(int &E){
	if (!Vacia()) {
		E = v[fin-1];
		fin = anterior(fin);
	}
}

int DicolaVC::Ultimo(){	if (!Vacia()) {		return v[fin-1];
	}}string DicolaVC::Mostrar(){
	string k="<< ";
	int E;
	DicolaVC* aux=new DicolaVC();
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