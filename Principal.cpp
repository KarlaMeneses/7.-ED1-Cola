#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>

#include "UColamemoria.h"

//added
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   // { Implementación con simulación de Memoria}
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
	k->Mostrar();


	system("pause");
	return 0;
}
