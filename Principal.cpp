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

#include "UColalistapuntero.h"
#include "UColalistavector.h"
#include "UColalistamemoria.h"

#include "UColavectordesplazamiento.h"
#include "UColavectorcircular.h"
using namespace std;

void invertir(ColaM* k);
int _tmain(int argc, _TCHAR* argv[])
{    //{ Implementación con simulación de Memoria}
	ColaM* k=new ColaM();
	k->Poner(45);
	k->Poner(55);
	k->Poner(65);
	k->Poner(75);
//	k->Poner(85);
//	k->Poner(95);
//	k->Poner(105);
//	k->Poner(115);
//	k->Poner(125);
//	k->Mostrar(); //mostrar siempre al inicio
//	int E;
//	k->Sacar(E);
//	k->Sacar(E);
//	k->Poner(105);
//	k->Poner(115);
//	k->Poner(125);
	k->Mostrar();
	invertir(k);
	//cout<<"new cola"<<endl;
	k->Mostrar();
	//k->Poner(85);
//	k->Poner(95);
	//k->Mostrar();
   // k->Mostrar();
	/* { Implementación con lista puntero}
	ColaLP* k=new ColaLP();
	k->Poner(10);
	k->Poner(20);
	k->Poner(30);
	k->Poner(40);
	cout<<k->Mostrar();
	int E;
	k->Sacar(E);
	cout<<k->Mostrar();
	k->Sacar(E);
	cout<<k->Mostrar();
	k->Sacar(E);
	cout<<k->Mostrar();  */

	/* { Implementación con lista vector}
	ColaLP* k=new ColaLP();
	k->Poner(10);
	k->Poner(20);
	k->Poner(30);
	k->Poner(40);
	cout<<k->Mostrar();
	int E;
	k->Sacar(E);
	cout<<k->Mostrar();
	k->Sacar(E);
	cout<<k->Mostrar();
	k->Sacar(E);
	cout<<k->Mostrar();  */

	/* { Implementación con lista simulacion de memoria}
	ColaLSM* k=new ColaLSM();
	k->Poner(10);
	k->Poner(20);
	k->Poner(30);
	k->Poner(40);
	cout<<k->Mostrar();
	int E;
	k->Sacar(E);
	k->Sacar(E);
	k->Sacar(E);
	k->Sacar(E);
	cout<<k->Mostrar();      */

	/* { Implementación con vector desplazamiento }
	ColaVD* k=new ColaVD();
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
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;
	k->Sacar(E);
	cout<<k->Mostrar()<<endl;   */

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
