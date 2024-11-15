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

//*************COLA*******************
#include "UColamemoria.h"
//{ Implementación con simulación de Memoria} ColaM* k=new ColaM();
#include "UColalistapuntero.h"
// { Implementación con lista puntero} ColaLP* k=new ColaLP();
#include "UColalistavector.h"
// { Implementación con lista vector} ColaLV* k=new ColaLV();
#include "UColalistamemoria.h"
// { Implementación con lista simulacion de memoria} ColaLSM* k=new ColaLSM();
#include "UColapuntero.h"

#include "UColavectordesplazamiento.h"
// { Implementación con vector desplazamiento } ColaVD* k=new ColaVD();
#include "UColavectorcircular.h"
// { Implementación con vector circular } ColaVC* k=new ColaVC();

//*************DICOLA*******************
#include "UDicolalistapuntero.h"
// { Implementación con lista puntero} DicolaLP* k=new DicolaLP();
#include "UDicolalistavector.h"
// { Implementación con lista vector} ColaLV* 	DicolaLV* k=new DicolaLV();
#include "UDicolalistamemoria.h"

#include "UDicolamemoria.h"

#include "UDicolapuntero.h"


#include "UDicolavectorcircular.h"
// { Implementación con vector circular } DicolaVC* k=new DicolaVC(); //OJO
#include "UDicolavectordesplazamiento.h"
// { Implementación con vector desplazamiento } DicolaVD* k=new DicolaVD();

//*************COLA PRIORIDAD*******************
#include "UColaprioridad.h"
//ColaPrioridad* k=new ColaPrioridad();

#include "UListavector.h"
#include "UListamemoria.h"
using namespace std;

void menu1();
void invertir(ColaM* k);
int _tmain(int argc, _TCHAR* argv[])
{

//	ColaLV* k=new ColaLV();   LISTA VECTOR CORREGIR!!!!!!!!!!

/*
	ListaSM* l=new ListaSM();
	l->inserta_primero(10);
	cout<<l->mostrar()<<endl;
	l->inserta_primero(20);
	cout<<l->mostrar()<<endl;
	l->inserta_primero(30);
	cout<<l->mostrar()<<endl;
	l->inserta_primero(40);
	cout<<l->mostrar()<<endl;             */

/*	ColaPrioridadKPMC* k = new ColaPrioridadKPMC();

	k->Poner(10,1);
	k->Poner(20,1);
	k->Poner(30,1);
	k->Poner(100,2);
	cout<<k->Mostrar()<<endl;
	int ff;
	k->Primero(ff);
	cout<<"primero: "<<ff<<endl;
	k->Poner(200,2);
	int E;
	//void Asignar_frec_prioridad(int frec, int prioridad);
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
																 */
	ColaVC* k=new ColaVC();
	ColaVC* cola1=new ColaVC();
	cola1->Poner(10);
	cola1->Poner(20);
	cola1->Poner(30);
	ColaVC* cola2=new ColaVC();
	cola2->Poner(100);
	cola2->Poner(200);
	cola2->Poner(300);
	k->concatenar(cola1,cola2,k);
    cout<<k->Mostrar()<<endl;


	//menu1();
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
	ColaPrioridadKPMC* CPKPMC;
	int opcion;
	do {
		cout << "1.crear colaPrioridad\n";
		cout << "2.poner en la colaPrioridad\n";
		cout << "3.mostrar colaPrioridad\n";
		cout << "4.sacar de la colaPrioridad\n";
		cout << "5.Llamar al metodo vacia\n";
		cout << "6.salir\n";
		cout << "Opcion:";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				CPKPMC=new ColaPrioridadKPMC();
			} break;
		case 2: {
				int valor;
				cout << "Ingrese un valor para la colaPrioridad: ";
				cin >> valor;
				int priori;
				cout << "Ingrese la prioridad: ";
				cin >> priori;
				CPKPMC->Poner(valor,priori);
			} break;
		case 3: {
				cout<<CPKPMC->Mostrar()<<endl;
			} break;
		case 4: {
				int E;
				CPKPMC->Sacar(E);
				cout <<E<<endl;
			} break;
		case 5: {
				bool w=CPKPMC->Vacia();
				if (w==0) {
					cout << "FALSE"<<endl;
				}else{
					cout << "TRUE"<<endl;
				}
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
