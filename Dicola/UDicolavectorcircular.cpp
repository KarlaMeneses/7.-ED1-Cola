//---------------------------------------------------------------------------

#pragma hdrstop

#include "UDicolavectorcircular.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//added
#include <iostream>
//METODO PRIVADO
direccion DicolaVC::siguiente(int dir){
	if(dir == MAXDVC - 1)
		return 0;
	else
		return dir + 1;
}

int DicolaVC::anterior(int dir) {
	if (dir == 0)
		return MAXDVC - 1;
	else
		return dir - 1;
}
// METODOS PUBLICOS DE LA CLASE DicolaVC
DicolaVC::DicolaVC(){
	fin=-1;
	ini=0;

bool DicolaVC::Vacia(){
	return siguiente(fin)==ini;  //ini==fin;
}

void DicolaVC::Poner(int E){
	 if (siguiente(siguiente(fin))!= ini){
		v[siguiente(fin)]=E;
		fin = siguiente(fin);
	 }
	 //mi fin tendra el valor de la casilla perdida
}

void DicolaVC::Sacar(int &E){
	if (!Vacia()){
		E= v[ini];
		ini = siguiente(ini);
	}
}

int DicolaVC::Primero(){
	}
			v[siguiente(fin)]=E;
			fin = siguiente(fin);
		}
	}else{
			v[ini] = E;
		}
	}
			v[fin]=E;
			fin = siguiente(fin);
		}
	}else{
			}
			fin = siguiente(fin);
			v[ini] = E;
		}
	}         */


}
	if (!Vacia()) {
		E = v[fin-1];
		fin = anterior(fin);
	}
}

int DicolaVC::Ultimo(){
	}
	string k="<< ";
	int E;
	DicolaVC* aux=new DicolaVC();
	while (!Vacia()){
		Sacar(E);
		aux->Poner(E);
		k=k+to_string(E);
		if (!Vacia()) {
			k+=',';
		}
	}
	while (!aux->Vacia()){
		aux->Sacar(E);
		Poner(E);
	}
	return k+" <<";
}