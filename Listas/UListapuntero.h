//---------------------------------------------------------------------------

#ifndef UListapunteroH
#define UListapunteroH
//---------------------------------------------------------------------------
//added
#include <iostream>
#include <string>
using namespace std; //para el string

struct NodoL{
	int elemento;//Cuando se crea de guarda un espacio con elem y sig en memoria
	NodoL* sig; //Puntero a nodo
};

typedef NodoL* direccionP;

class ListaP{
	private:
		direccionP PtrElementos;
		int longitud;
	public:
		ListaP();//
		direccionP fin();//
		direccionP primero();//
		direccionP siguiente(direccionP dir);//
		direccionP anterior(direccionP dir);//
		bool vacia();//
		void recupera(direccionP dir,int &E); //Saca elemento del nodo dir
		int longuitud ();//
		void inserta(direccionP dir,int element);//
		void inserta_primero(int element);//
		void inserta_ultimo(int element);//
		void suprime(direccionP dir); //
		void modifica(direccionP dir,int element); //		string mostrar(); //
};
#endif
