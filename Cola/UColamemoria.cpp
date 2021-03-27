//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>

ColaM::ColaM(){
	mem=new CSMemoria();
	ini=-1;
	fin=-1;
}

bool ColaM::Vacia(){
	//return mem->espacio_ocupado()==0;cuando se pide espacio ya no esta vacia
	return ini==-1;
}

void ColaM::Poner(int E){
	int aux=mem->new_espacio(datoC); //Pedir Espacio de memoria para Nodo
	if (aux!=NULO) {
		mem->poner_dato(aux,elementoC,E,0);
		mem->poner_dato(aux,sigC,NULO,0);
		if (Vacia()){
			ini=aux;
			fin=aux;
		}else{
			mem->poner_dato(fin,sigC,aux,0);
			fin=aux;   //fin=al espacio en la cual comenzo el string
		}
	}else{
		cout<<"No existe espacio en COLA memoria para agregar "<<E<<endl;
	}
}

void ColaM::Sacar(int &E){
	if (!Vacia()) {
		E=mem->obtener_dato(ini,elementoC);
		int x=ini;
		//ini=mem->obtener_dato(ini,sigC); i am using desplazament
		mem->delete_espacio(x);
		fin=fin-2;
		if (fin==-2) {
			fin=-1;
			ini=-1;
		}
	}else{
		cout<<"La memoria (COLA) ya esta vacia no se puede sacar elemento"<<endl;

	}
}

int ColaM::Primero(){	if (!Vacia()) {		return mem->obtener_dato(ini,elementoC);
	}else{		cout<<"Error\n";
	}}string ColaM::Mostrar(){
	string k="COLA: << ";
	mem->mostrar_memoria();    //test
	int E;
	ColaM* aux=new ColaM();
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
//	cout<<"ini4 de aux"<<aux->inic()<<endl;
//	cout<<"fin4 de aux"<<aux->finc()<<endl;
//	cout<<"ini1: "<<ini<<endl; //test
//	cout<<"Fin1: "<<fin<<endl; //test
//	cout<<"espacio ocupado: " <<mem->espacio_ocupado()<<endl;
//	cout<<"espacio disponible: " <<mem->espacio_disponible()<<endl;
	return k+" <<";
}
