//---------------------------------------------------------------------------

#pragma hdrstop

#include "Umemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>   //  { Para poder usar el cout<< }
#include <iomanip>    //  { Para usar el setw }

//#include <ctype.h>//////////para la funcion esalpha
#include<string>
//using namespace std;
//#include <stdio.h>
//#include <ctype.h>

/************METODOS AUXILIARES ***********************************************/
void trim(string& cadena_id) {
	int i = 0;
	while(i < cadena_id.length())
	{
		if (cadena_id[i] ==' ' && (cadena_id[i+1] == ' ' || i+1==cadena_id.length() || i==0 )) // si se encuentra espacio y (el siguiente es espacio, estamos en la ultima posicion, estamos al principio)
		{
			cadena_id.erase(i, 1); //borramos el espacio incorrecto
		}
		else {
			i++;
		}
	}
}
//
//bool es_separador(char z){  //wchar_t
//	string  separadores= " ,.-,_:;�?!�";
//	return	separadores.Pos(z)>0;
//}
//

int numero_ids(string cadena_id){
	int cont=0;
	for (int i = 0; i < cadena_id.length(); i++) {
		if (cadena_id[i]==',') {
			cont++;
		}
	}
	cont++;
	return cont;
}

string obtener_id(string cadena_id,int &�){//
	string palabra="";
	int i=0;
	int aux=�;
	string prueba=cadena_id;
	while (palabra==""){
		if (cadena_id[�]==',' || ((aux+i)==cadena_id.length()-1) ) {
			palabra=cadena_id.substr(aux,i);
			if ((aux+i)==cadena_id.length()-1) {
				palabra=cadena_id.substr(aux,i+1);
			}
		}
		i++;
		�++;
	}
	trim(palabra);
	return palabra;
}


string Eliminar_flecha(string cadena_id){ //Entra si tiene una flecha, ya verificada sin espacios
	cadena_id.erase(0,2);
	return cadena_id;
}

/************METODOS DE LA CLASE MEMORIA***************************************/
CSMemoria::CSMemoria(){
	for (int i = 0; i < MAX; i++) {
		MEM[i].Link=i+1;
		MEM[i].Dato=0;
	}
	MEM[MAX-1].Link=-1;
	MEM[MAX-1].Dato=0;
	Libre =0;
}

direccion CSMemoria::new_espacio(string cadena_id){
	if (espacio_disponible()>0) { //last modified
		int d=Libre;
		int dir=Libre;
		int �=0;
		trim(cadena_id);
		int cant=numero_ids(cadena_id);
		for (int i=0; i < cant-1; i++) {
			MEM[d].Id=obtener_id(cadena_id,�);
			d=MEM[d].Link;
		}
		Libre=MEM[d].Link;
		MEM[d].Link=-1;
		MEM[d].Id=obtener_id(cadena_id,�);
		return dir;
	}else{
		//cout<<"No existe espacio en la memoria"<<endl;
		return NULO;
	}
}

void CSMemoria::poner_dato(int dir,string cadena_id,int valor,int ebx){
	trim(cadena_id);
	int z=dir;  //dir direccion de la variable E.g: dir=3
	if ((cadena_id[0] == '-') && (cadena_id[1] == '>')) {
		cadena_id=Eliminar_flecha(cadena_id);
		if (ebx==118) {
			int c=(espacio_ocupado()/2)-1;//3
			int ebx=Libre-2;//8
			while (c>0){
				MEM[ebx].Dato=MEM[ebx-2].Dato;
				MEM[ebx+1].Dato=ebx+2;
				ebx=ebx-2;
				c=c-2;
			}
			MEM[Libre-1].Dato=-1;
			MEM[dir].Dato=valor;
			MEM[dir+1].Dato=dir+2;
		}else{
			while (z != NULO){  //mientras que mi direccion de variable sea diferente a fin de direccion (-1)
				if (MEM[z].Id == cadena_id) {
					MEM[z].Dato= valor;//????
				}
				z=MEM[z].Link;
			}
		}
	}else{
		cout << "ERROR, Verificar el valor asignado: "<<cadena_id<<endl;
		cout << "Ejemplo: hola mundo \n " << "Insertar con la flecha: '->hola mundo'"<<endl;
	}
}


int CSMemoria::obtener_dato(int dir,string cadena_id){
	int z=dir;
	bool ex=false;
	cadena_id=Eliminar_flecha(cadena_id); //last modified
	while(z!=NULO){
		if (MEM[z].Id == cadena_id){
			return MEM[z].Dato;
		}
		z=MEM[z].Link;
	}
}

void CSMemoria::delete_espacio(int dir){  //
	if (dir==Libre-2) {
		int x = dir;
		while (MEM[x].Link != -1){
			MEM[x].Dato=0;
			MEM[x].Id="";
			x = MEM[x].Link;
		}
		//MEM[x-1].Link=-1;
		MEM[x].Dato=0;
		MEM[x].Id="";
		MEM[x].Link = Libre;
		Libre = dir;
	}else{
		desplazamiento(dir);
	}
}

void CSMemoria::desplazamiento(int dir){
	int c=(espacio_ocupado()/2)-1;  //-1
	int d=dir; //0
	int g=MEM[dir].Link; //1-->2
	g=obtener_dato(g,"->sig"); //dir 2
	while (c>0){
		//while(MEM[d].Link!=-1){
			int t=obtener_dato(g,"->elemento");
			poner_dato(d,"->elemento",t,0);
			d=MEM[d].Link;
	   //	}
		d=g; //d=4
		g=obtener_dato(g,"->sig");//6
		c--;//3-2-1
	}
	poner_dato(d-1,"->sig",-1,0);
	MEM[d].Dato=0;    ///important!!!
	//poner_dato(d,"->elemento",0);
	MEM[d].Id="";
	MEM[d+1].Dato=0;   ///important!!!
	//poner_dato(d,"->sig",0);
	MEM[d+1].Id="";
	if (d+1<MAX-1) {
		MEM[d+1].Link=d+2;
	}
	Libre=d;
}

int CSMemoria::espacio_disponible(){
	int x= Libre;
	int c=0;
	while (x!=-1){
		c++;
		x=MEM[x].Link;
	}
	return c;
}

int CSMemoria::espacio_ocupado(){ ///La inversa
	int c =MAX - espacio_disponible();//last modified
	return c;
}

bool CSMemoria::dir_libre(int dir){ ///
	int x=Libre; bool c=false;
	while (x!=-1 && c==false){
		if (x==dir) {
			c=true;
		}
		x=MEM[x].Link;
	}
	return c;
}

void CSMemoria::mostrar_memoria(){
	cout.fill('-'); // rellena los espacios vacios con el char asigando
	cout << "+" << setw(6) << "-" << setw(15) << "-" << setw(10) << setw(7)
		<< "-" << setw(10) << "+" << endl;
	cout << "|" << " DIR " << "|" << "  DATO  " << "|" << "      ID       |" <<
		" LINK |" << endl;
	for (int i = 0; i < MAX ; i++) { //{ MAX+1 wait! }
		cout.fill('-');//RELLENA TODOS LOS ESPACIOS EN BLANCO
		cout << "+" << setw(6) <<  "-" << setw(10)<< "-" << setw(15)
			<< "-" <<setw(7)<< "+" << endl;
		cout.fill(' ');
		cout << "|";

		cout.width(5); //distancia del proximo cout e.g.: 40 hasta la distacia 5
		cout << i << "|";

		cout.width(8);
		cout << MEM[i].Dato << "|";

		cout.width(15);
		cout << MEM[i].Id << "|";

		cout.width(6);

		cout << MEM[i].Link << "|" << endl;
	}
	cout.fill('-');
	cout << "+" << setw(6) << "+" << setw(9) << "+" << setw(16) << "+" << setw(7)
		<< "+" << endl;
	cout.fill(' ');
	//setw() = espacios en blancos hasta cierto punto
    //cout<<"Libre: "<<Libre<<endl;
}
