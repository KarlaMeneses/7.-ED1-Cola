//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaSM::ListaSM(){
	PtrElementos=NULO;
	longitud=0;
	mem = new CSMemoria();
}

int ListaSM::fin(){
	if (vacia()){
		//cout << "ERROR: LISTA VACIA22222\n";
		return NULO;
	}
	else {
		int x = PtrElementos;
		int PtrFin;
		while (x != NULO) {
			PtrFin = x;
			x = mem->obtener_dato(x, sigL); // x->sig;
		}
		return PtrFin;
	}
}

int ListaSM::primero(){
	if (!vacia())
		return PtrElementos;
	else
		cout << "ERROR: LISTA VACIA1111\n";
}

int ListaSM::siguiente(int dir){
	if (vacia())
		cout << "ERROR: LISTA VACIA666\n";
	else {
		if (dir == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return mem->obtener_dato(dir, sigL); // d->sig;
	}
}

int ListaSM::anterior(int dir){
	if (vacia()){
		cout << "ERROR: LISTA VACIA999\n";
		return NULO;
	}
	else {
		if (dir == primero()){
			cout << "ERROR: DIRECCION ERRONEA\n";
			return NULO;
		}
		else {
			int x = PtrElementos;
			int ant = NULO;
			while (x != NULO) {
				if (x == dir)
					return ant;
				ant = x;
				x = mem->obtener_dato(x, sigL); // x->sig;
			}
			return NULO;
		}
	}
}

bool ListaSM::vacia(){
	return longitud==0;
}

void ListaSM::recupera(int dir,int &E){
	if (vacia())
		cout << "ERROR: LISTA VACIA55555\n";
	else
		E=mem->obtener_dato(dir, elementL); // d->elemento;
}

int ListaSM::longuitud (){
	return longitud;
}

// new Nodo; mem->new_espacio("elemento,sig"); mem->new_espacio(datosNL);
void ListaSM::inserta(int dir,int element){
	int x= mem->new_espacio(datoL); // NodoL* x = new NodoL; //creacion de un nuevo nodo es distinto a null
	if (x!=NULO) {
		mem->poner_dato(x, elementL, element); // x->elemento = e;
		mem->poner_dato(x, sigL, NULO); // x->sig = NULL;
		//cout<<mostrar(); //test
//		cout<<"dir:  "<<dir<<endl; //test
//		cout<<"fin:  "<<fin()<<endl; //test
		if (vacia()) {
			PtrElementos=x;
			longitud=1;
		}
		else{
			longitud++;
			//PtrElementos=x;
			//cout<<dir<<endl; //test

			if (dir==fin()) {
				mem->poner_dato(fin(), sigL, x); // ant->sig = x;
			}else{
				if (dir==primero()) {
					mem->poner_dato(primero(), sigL, x); // ant->sig = x;
				}//ERROR EN INSERTAR AL INICIO CON DESPLAZAMIENTO  solo se reemplaza
            }
		}
		//cout<<vacia()<<endl; //test
	}
	else{
		cout << "Error: No exite espacio en la memoria\n";
	}

}
void ListaSM::inserta_primero(int element){
	int x=mem->new_espacio(datoL); // NodoL* x = new NodoL;
	if (x!=NULO) {
		mem->poner_dato(x, elementL, element); // x->elemento = e;
		mem->poner_dato(x, sigL, PtrElementos); // x->sig = ptr_elementos
		longitud++;
		PtrElementos=x;
	}
	else{
		cout << "Error: No existe espacio en la memoria\n";
	}
}
void ListaSM::inserta_ultimo(int element){
	int x = mem->new_espacio(datoL); // NodoL* x = new NodoL;
	if (x!=NULO) {
		mem->poner_dato(x, elementL, element); // x->elemento = e;
		mem->poner_dato(x, sigL, NULO); // x->sig = NULL;
		if (longitud==0) {//al principio
			PtrElementos=x;
		}
		else{
			mem->poner_dato(fin(), sigL, x); // fin()->sig = x;
		}
		longitud++;
	}
	else{
		cout << "Error: No exite espacio en la memoria\n";
	}
}

// delete(x)     ->  mem->delete_espacio(x);
void ListaSM::suprime(int dir){
	//desplazamiento(dir);
	if (longitud==0) {
		cout << "Error: La lista esta vacia7777\n";
	}
	else{
		longitud--;
		if (dir==PtrElementos) { //primer nodo
			int x=PtrElementos;
			//PtrElementos=mem->obtener_dato(PtrElementos, sigL);//ptr elemen siempre es 0
			// ptr_elementos->sig;
			mem->delete_espacio(x); // delete(x);
			if (longuitud()==0) {
				PtrElementos=NULO;
			}
		}
		else{
			int ant=anterior(dir);
			mem->poner_dato(ant, sigL, mem->obtener_dato(dir, sigL));
			// ant->sig = d->sig;
			mem->delete_espacio(dir); // delete(d);
		}
	}
	//longitud--;
}


void ListaSM::modifica(int dir,int element){
	}
	}
	mem->mostrar_memoria();
	string s = "LISTA: [";
	int aux = PtrElementos;
	while (aux != NULO){
		int el = mem->obtener_dato(aux, elementL); // aux->elemento
		s += to_string(el);
		aux = mem->obtener_dato(aux, sigL); // aux->sig;
		if (aux != NULO)
			s += ",";
	}
	return s + "]";
}

int ListaSM::localiza(int e){
	int aux = PtrElementos;
	while (aux != NULO){
		if (mem->obtener_dato(aux, elementL) == e)
			return aux;
		aux = mem->obtener_dato(aux, sigL); // aux->sig;
	}
	return NULO;
}

void ListaSM::elimina_dato(int e){
	int aux = PtrElementos;
	while (aux != NULO){
		if (mem->obtener_dato(aux, elementL) == e){
			int sup = aux;
			aux = mem->obtener_dato(aux, sigL); // aux->sig;
			suprime(sup);
		}
		else
			aux = mem->obtener_dato(aux, sigL); // aux->sig;
	}
}

void ListaSM::anula(){
	while (!vacia())
		suprime(primero());
}