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

int _tmain(int argc, _TCHAR* argv[])
{
	ColaM* k=new ColaM();
	k->Poner(45);
	k->Poner(55);
	k->Poner(65);
	k->Poner(75);
	system("pause");
	return 0;
}
