//---------------------------------------------------------------------------

#pragma hdrstop

#include "UColapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaP::ColaP(){
	ini = fin = NULL;
}

bool ColaP::Vacia(){
		 return ini == NULL;
}

void ColaP::Poner(int E){
       NodoC* aux = new NodoC();
    if(aux != NULL){
		aux->elemento = E;
        aux->sig = NULL;
		if(Vacia()){
            ini = fin = aux;
        }else{
            fin->sig = aux;
            fin = aux;
        }
	}
}

void ColaP::Sacar(int &E){
		if(!Vacia()){
		E = ini->elemento;
        NodoC* x = ini;
        if(ini == fin)
            ini = fin = NULL;
        else
            ini = ini->sig;
        delete(x);
	}
}

int ColaP::Primero(){		if(!Vacia())		return ini->elemento;}string ColaP::Mostrar(){
		string s = "Cola: << ";
	int e;
	ColaP* aux = new ColaP();
	while (!Vacia()) {
		Sacar(e);
		aux->Poner(e);
		s += to_string(e);
		if (!Vacia())
			s += ",";
	}
	while (!aux->Vacia()) {
		aux->Sacar(e);
		Poner(e);
	}
	return s + " <<";
}
