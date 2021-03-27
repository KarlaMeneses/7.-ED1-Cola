//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DColaP::DColaP(){
	ini = fin = NULL;
}
void DColaP::Poner_frente(int E){
	NodoDC* aux = new NodoDC();
	if(aux != NULL){
		if(Vacia()){
			aux->elemento = E;
			ini = fin = aux;
			aux->sig=NULL;
			aux->ant = fin->sig;
		}else{
			aux->elemento = E;
			aux->sig = ini->ant;
			aux->ant = fin->sig;
			ini = aux;
		}
	}
}
