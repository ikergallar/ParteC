#include "Hotel.h"
#include "Habitacion.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

Hotel::Hotel(){
    nombre = new char[20];
    ciudad = new char[20];
    direccion = new char[40];
    maxHabitaciones = 0;
    numHabitaciones = 0;
}
Hotel::Hotel(char *n, char *d, char *c, int numE, int maxH)
{
    nombre = new char[strlen(n)+1];
    strcpy(nombre,n);
    direccion = new char[strlen(d)+1];
    strcpy(direccion,d);
    ciudad = new char[strlen(c)+1];
    strcpy(ciudad,c);
    numEstrellas = numE;
    maxHabitaciones = maxH;
    habitaciones = new Habitacion*[maxHabitaciones];
    numHabitaciones = 0;
}
char *Hotel::getNombre() const
{
    return nombre;
}
char *Hotel::getDireccion() const
{
    return direccion;
}
char *Hotel::getCiudad() const
{
    return ciudad;
}
void Hotel::addHabitacion(Habitacion *h)
{
    habitaciones[numHabitaciones] = h;
    numHabitaciones++;
}
void Hotel::reservarHabitacion(int pos)
{
    habitaciones[pos]->setOcupada(1);
}
void Hotel::mostrarHabitaciones()
{
    for(int i=0;i<numHabitaciones;i++){
        cout<<i<<" ";
        habitaciones[i]->mostrarHabitacion();
    }
}

Habitacion * Hotel::getHabitacion(int pos) const{
    return habitaciones[pos];
}

int Hotel::buscarHabitacion(int numH){
    int pos=0,enc=0;

    while(pos<numHabitaciones && enc==0){
        if(habitaciones[pos]->getNumH() == numH)
            enc=1;
        else
            pos++;
    }
    if(!enc)
        pos=-1;

    return pos;
}

int Hotel::getNumEstrellas() const{
    return numEstrellas;
}

int Hotel::getNumHabitaciones() const{
    return numHabitaciones;
}
int Hotel::getMaxHabitaciones() const{
    return numHabitaciones;
}

void Hotel::pedirDatos(){

    cout<<"Introduce el nombre: "; cin>>nombre;
    cout<<"Introduce la direccion: "; cin>>direccion;
    cout<<"Introduce la ciudad: "; cin>>ciudad;
    cout<<"Introduce el numero de estrellas: "; cin>>numEstrellas;
    cout<<"Introduce el numero maximo de habitaciones: "; cin>>maxHabitaciones;
    habitaciones = new Habitacion*[maxHabitaciones];
    cout<<"¿Quieres añadir habitaciones (s/n)? ";
    char resp; cin>>resp;
    if(resp=='s'){
        cout<<"Introduce el numero de habitaciones: "; cin>>numHabitaciones;
        for(int i=0;i<numHabitaciones;i++){
            Habitacion *h= new Habitacion();
            h->pedirDatos();
            habitaciones[i] = h;

        }

    }
    cout<<" "<<endl;
    cout<<"Hotel agregado correctamente "<<endl;

}
void Hotel::mostrarHotel(){
    cout<<" " <<endl;
    cout<<"NOMBRE HOTEL: "<<nombre<<endl;
    cout<<"DIRECCION: "<<direccion<<endl;
    cout<<"CIUDAD: "<<ciudad<<endl;
    cout<<"NUM ESTRELLAS: "<<numEstrellas<<endl;
    cout<<"NUM HABITACIONES: "<<numHabitaciones<<endl;
    cout<<"INFORMACIÓN DE LAS HABITACIONES..."<<endl;

    mostrarHabitaciones();

}
Hotel::~Hotel()
{
    delete[] nombre,direccion,ciudad,habitaciones;
}
