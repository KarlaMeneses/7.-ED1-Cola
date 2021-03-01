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
	return mem->espacio_ocupado()==0;
	//return ini==-1;
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
		cout<<"No existe espacio en COLA memoria para agregar "<<E<<endl;
	}
//	mem->mostrar_memoria();    //test
//	cout<<"ini1: "<<ini<<endl; //test
//	cout<<"Fin1: "<<fin<<endl; //test
//	cout<<"espacio ocupado: " <<mem->espacio_ocupado()<<endl;
//	cout<<"espacio disponible: " <<mem->espacio_disponible()<<endl;
}

void ColaM::Sacar(int &E){
	if (!Vacia()) {
		E=mem->obtener_dato(ini,elementoC);//45
		int x=ini;
		//ini=mem->obtener_dato(ini,sigC);  /// init sigue siendo 0
		mem->delete_espacio(x);
		fin=fin-2;
		if (fin==-2) {
			fin=0;
		}
	}else{
		cout<<"La memoria (COLA) ya esta vacia no se puede sacar elemento"<<endl;
    }
}

int ColaM::Primero(){	if (!Vacia()) {		return mem->obtener_dato(ini,elementoC);
	}else{		cout<<"Error\n";
	}}string ColaM::Mostrar(){
	int x=mem->espacio_ocupado()/2;
	cout<<"Numero: "<<x<<endl;
	int g=0;
	string k="COLA: << ";
	while (x>0){
		k=k+to_string(mem->obtener_dato(g,elementoC));
		if (x>1) {
			k=k+',';
		}
		x--;
		g+=2;
	}
	cout<<k<<" <<"<<endl;
	cout<<"ini1: "<<ini<<endl; //test
	cout<<"Fin1: "<<fin<<endl; //test
	cout<<"espacio ocupado: " <<mem->espacio_ocupado()<<endl;
	cout<<"espacio disponible: " <<mem->espacio_disponible()<<endl;
	mem->mostrar_memoria();    //test
}
