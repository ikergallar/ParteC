#include "Habitacion.h"
#include <string.h>
#include <iostream>
using namespace std;
Habitacion::Habitacion(){
    ocupada = 0;
}
Habitacion::Habitacion(int numH, char *t, float p)
{
    tipo = new char[strlen(t)+1];
    strcpy(tipo,t);
    precio = p;
    ocupada = 0;
    numHabitacion = numH;
}

Habitacion::Habitacion(int numH, char *t, float p, int o)
{
    tipo = new char[strlen(t)+1];
    strcpy(tipo,t);
    precio = p;
    ocupada = o;
    numHabitacion = numH;
}

int Habitacion::getNumH() const{
    return numHabitacion;
}

char * Habitacion::getTipo() const {
    return tipo;
}

float Habitacion::getPrecio()const {
    return precio;
}

int Habitacion::getOcupada() const {
    return ocupada;
}
void Habitacion::setOcupada(int o){
    ocupada = o;
}
void Habitacion::mostrarHabitacion(){
    cout<<numHabitacion<<" "<<tipo<<" "<<precio<<"euros ";
    if(ocupada==1)
        cout<<"OCUPADA"<<endl;
    else
        cout<<"LIBRE"<<endl;
}
void Habitacion::pedirDatos(){
    cout<<"Introduce el numero de habitacion: "; cin>>numHabitacion;
    tipo = new char[20];
    cout<<"Introduce el tipo de habitacion: "; cin>>tipo;
    cout<<"Introduce el precio de la habitacion: "; cin>>precio;
}
Habitacion::~Habitacion()
{
    delete[] tipo;
}

