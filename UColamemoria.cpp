//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>

ColaM::ColaM(){
	mem=new CSMemoria();
	int ini=-1;
	int fin=-1;
}

bool ColaM::Vacia(){
	return ini==NULO;
}

void ColaM::Poner(int E){
	int aux=mem->new_espacio(datoC); //Pedir Espacio de memoria para Nodo
	if (aux!=NULO) {
		mem->poner_dato(aux,elementoC,E);
		mem->poner_dato(aux,sigC,NULO);
		if (Vacia()){
			ini=aux;
			fin=aux;
		}else{
			mem->poner_dato(fin,sigC,aux);
			fin=aux;   //fin=al espacio en la cual comenzo el string
		}
	}else{
		cout<<"Error\n";
	}
	mem->mostrar_memoria();    //test
	cout<<"ini1: "<<ini<<endl;
	cout<<"Fin1: "<<fin<<endl;
}

void ColaM::Sacar(int &E){

}

int ColaM::Primero(){}string ColaM::Mostrar(){

}
