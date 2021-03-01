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
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{    /*{ Implementación con simulación de Memoria}
	ColaM* k=new ColaM();
	k->Poner(45);
	k->Poner(55);
	k->Poner(65);
	k->Poner(75);
	k->Poner(85);
	k->Poner(95);
	k->Poner(105);
	k->Poner(115);
	k->Poner(125);
	k->Mostrar(); //mostrar siempre al inicio
	int E;
	k->Sacar(E);
	k->Sacar(E);
	k->Poner(105);
	k->Poner(115);
	k->Poner(125);
	k->Mostrar();     */

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
	system("pause");
	return 0;
}
