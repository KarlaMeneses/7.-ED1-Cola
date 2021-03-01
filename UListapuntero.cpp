//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
#include <string>
#include "string.h"

using namespace std;

ListaP::ListaP(){
	longitud=0;
	PtrElementos=NULL; // No tiene direccion fisica asignada - Apunta a nulo
}                      //ptrElem----> ---//

direccionP ListaP::fin(){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		direccionP x=PtrElementos; //x apunta a lo mismo que apunta ptrelem
		direccionP PtrFin; //cuando solo se declara apunta a null
		while (x!=NULL){
			PtrFin=x; //ptrfin apunta a lo que apunta x
			x=x->sig; //x apunta al siguiente
		}
		return PtrFin;
	}
}
direccionP ListaP::primero(){
	if (!vacia()) {
		return PtrElementos;   //apunta al primero ptrelem
	}
	else{
		//cout << "Error: La lista esta vacia\n";
		return NULL;
	}
}
direccionP ListaP::siguiente(direccionP dir){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";
		return NULL;
	}
	else{
		if (dir==fin()) {
			//cout << "Error de direccion el sigiente es null\n";
			return NULL;
		}
		else{
			return dir->sig;//sig del nodo
		}
	}
}
direccionP ListaP::anterior(direccionP dir){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		if (dir==primero()) {
			cout << "Error de direccion no existe el anterior\n";
		}
		else{
			direccionP x=PtrElementos;
			direccionP ant=NULL;
			while (x!=NULL){
				if (x==dir) {
					return ant;
				}
				ant=x;
				x=x->sig;
			}
			return NULL;
		}
	}
}

bool ListaP::vacia(){
	return longitud==0;
}

void ListaP::recupera(direccionP dir,int &E){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		E=dir->elemento;
	}
}
int ListaP::longuitud (){
	return longitud;
}
void ListaP::inserta(direccionP dir,int element){
	NodoL* x= new NodoL;//creacion de un nuevo nodo es distinto a null
	if (x!=NULL) { //analizarlo
		x->elemento=element;
		x->sig=NULL;
		if (vacia()) {
			PtrElementos=x;
			longitud=1;
		}
		else{
			longitud++;
			if (dir==primero()) {
				x->sig=dir;
				PtrElementos=x;//variable apunta al primer elemento
			}
			else{
				direccionP ant=anterior(dir); //nodo anterior del ingresado
				ant->sig=x;
				x->sig=dir;
			}
		}
	}
	else{
		cout << "Error: No exite espacio en la memoria\n";
	}

}
void ListaP::inserta_primero(int element){
	NodoL* x=new NodoL; //creacion del nodo que no apunta a null
	if (x!=NULL) {
		x->elemento=element;
		x->sig=PtrElementos;
		longitud++;
		PtrElementos=x;
	}
	else{
		cout << "Error: No existe espacio en la memoria\n";
	}
}
void ListaP::inserta_ultimo(int element){
	NodoL* x= new NodoL;
	if (x!=NULL) {
		x->elemento=element;
		x->sig=NULL;
		if (longitud==0) {//al principio
			PtrElementos=x;
		}
		else{
			fin()->sig=x;
		}
		longitud++;
	}
	else{
		cout << "Error: No exite espacio en la memoria\n";
	}
}
void ListaP::suprime(direccionP dir){
	if (longitud==0) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		if (dir==PtrElementos) { //primer nodo
			direccionP x=PtrElementos;
			PtrElementos=PtrElementos->sig;
			delete(x);//Elimina la memoria del nodo
		}
		else{
			direccionP ant=anterior(dir);
			ant->sig=dir->sig;//dir->sig envia lo que realmente tiene.
			delete(dir);
		}
	}
	longitud--;
}

void ListaP::modifica(direccionP dir,int element){	if (vacia()) {		cout << "Error: La lista esta vacia\n";
	}	else{		dir->elemento=element;//modificar elemento que tiene por otro
	}}string ListaP::mostrar(){
	/*NodoL *x=PtrElementos;
	if (longitud==0)
	cout<<"<>"<<endl;
		else{
		cout<<'<'<<x->elemento;
		x=siguiente(x);
			while (x!=NULL){
			cout<<',';
			cout<<x->elemento;
			x=siguiente(x);
			}
		cout<<'>'<<endl;
		}  */
	string s = "[";
	direccionP aux = PtrElementos;
	while (aux != NULL) {
		int el = aux->elemento;
		s += to_string(el);
		aux = aux->sig;
		if (aux != NULL)
			s += ",";
	}
	return s + "]";
}

/*
 Recorrer con punteros
 direccionP aux = ptr_elementos;
 while(aux != NULL){
 aux = aux->sig;
 }
*/
