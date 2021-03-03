#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
//added
#include <iostream>
#include "UColamemoria.h"
//{ Implementación con simulación de Memoria} ColaM* k=new ColaM();

#include "UColalistapuntero.h"
// { Implementación con lista puntero} ColaLP* k=new ColaLP();

#include "UColalistavector.h"
// { Implementación con lista vector} ColaLV* k=new ColaLV();

#include "UColalistamemoria.h"
// { Implementación con lista simulacion de memoria} ColaLSM* k=new ColaLSM();

#include "UColavectordesplazamiento.h"
// { Implementación con vector desplazamiento } ColaVD* k=new ColaVD();

#include "UColavectorcircular.h"


//////////////////
#include "UDicolalistapuntero.h"
#include "UDicolalistavector.h"

#include "UListavector.h"
using namespace std;

void menu1();
void invertir(ColaM* k);
int _tmain(int argc, _TCHAR* argv[])
{
	/* //incompleto!!!!!
	ColaVC* k=new ColaVC();
	k->Poner(10);
	//cout<<k->Mostrar()<<endl;
	k->Poner(20);
	//cout<<k->Mostrar()<<endl;
	k->Poner(30);
	//cout<<k->Mostrar()<<endl;
	k->Poner(40);
	cout<<k->Mostrar()<<endl;
	invertir(k);
	 /*	int E;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;  */


	//DICOLA
	/*Lista puntero
	DicolaLP* k=new DicolaLP();
	k->Poner(10);
	cout<<k->Mostrar()<<endl;
	k->Poner(20);
	cout<<k->Mostrar()<<endl;
	k->Poner(30);
	cout<<k->Mostrar()<<endl;
	k->Poner(40);
	cout<<k->Mostrar()<<endl;
	int E;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
	k->Poner_frente(88);
	cout<<k->Mostrar()<<endl;
	cout<<k->Ultimo()<<endl;
	cout<<k->Mostrar()<<endl;
	k->Poner(70);
	cout<<k->Mostrar()<<endl;
	k->Poner_frente(223);
	cout<<k->Mostrar()<<endl; */


   //	DicolaLV* k=new DicolaLV();
   //	k->Poner(10);
	//cout<<k->Mostrar()<<endl;
	//k->Poner(20);
	//cout<<k->Mostrar()<<endl;
//	ListaV* l=new ListaV();
//	l->inserta(l->primero(),10);
//	l->mostrar();
	system("pause");
	return 0;
}

void invertir(ColaM* k){//modifica los valores de k
	int E;
	string r="";
	string d="";
	while (!k->Vacia()) { //saca de la cola y lo pone en el string
		k->Sacar(E);
		r=to_string(E)+r;
		if (!k->Vacia()) {
			r=','+r;
		}
	}
	while (r.length()>0){
		if (isdigit(r[0])) {
			d=d+r[0];
			r=r.substr(1,r.length());
		}else{
			int oo=stoi(d);
			d="";
			k->Poner(oo);
			r=r.substr(1,r.length());
		}
	}
	k->Poner(stoi(d));
}


void menu1(){
	ColaKPMC* CKPMC;
	int opcion;
	do {
		cout << "1.crear cola\n";
		cout << "2.poner en la cola\n";
		cout << "3.mostrar cola\n";
		cout << "4.invertir cola\n";
		cout << "5.mostrar memoria\n";
		cout << "6.salir\n";
		cout << "Opcion:";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				CKPMC=new ColaKPMC();
			} break;
		case 2: {
				int valor;
				cout << "Ingrese un valor para la cola: ";
				cin >> valor;
				CKPMC->Poner(valor);
			} break;
		case 3: {
				int e;
				CKPMC->Mostrar();
			} break;
		case 4: {
				invertir(CKPMC);
			} break;
		case 5: {
				CKPMC->Mostrarmemoria();
			} break;
		case 6: {
				opcion=6;
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion == 1|| opcion == 2|| opcion == 3 ||opcion == 4||opcion == 5);
}
