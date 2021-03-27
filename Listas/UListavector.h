//---------------------------------------------------------------------------

#ifndef UListavectorH
#define UListavectorH
//---------------------------------------------------------------------------
//added
#include<string>     //without this it makes an error in type string!
using namespace std; //without this it makes an error in type string!

const int MAXVE=10;
const int NULOVE=0;

typedef int direccion;

class ListaV{
	private:
		int elementos[MAXVE]; //guarda dato
		int longitud;
	public:
		ListaV();//
		direccion fin();//
		direccion primero();//
		direccion siguiente(direccion dir);//
		direccion anterior(direccion dir);//
		bool vacia();//
		void recupera(direccion dir,int &E);// devuelve el valor de la posicion
		int longuitud();//
		void inserta(direccion dir, int element );//
		void inserta_primero(int element);//
		void inserta_ultimo(int element);//
		void suprime(direccion dir);//
		void modifica(direccion dir, int element);//
		string mostrar();//
		/////
		direccion localiza(int element);//
		void eliminaDato(int element);//
		void anula();//
};
#endif
