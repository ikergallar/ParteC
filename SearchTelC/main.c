#include <iostream>
#include "Buscador.h"
#include "Habitacion.h"
#include "login.h"
#include "Hotel.h"
#include <fstream>


using namespace std;
char menu(){
    char opcion;

printf("            \n");
    printf("1. Ver todos los hoteles\n");
    printf("2. Reservar una habitación en un hotel\n");
    printf("3. Cancelar la reserva de una habitación\n");
    printf("4. Añadir hotel al buscardor\n");
    printf("5. Eliminar hotel del buscador\n");
    printf("0. Salir\n");

    do{
        printf("Elige una opcion: \n");
        cin>>opcion;
    }while(opcion<'0' || opcion>'5');
    return opcion;
}

void volcarBuscadorAFichero(Buscador *buscador){
    ofstream f1;
    f1.open("Hoteles.txt",ios::out);
    f1<<buscador->getMaxHoteles()<<endl;
    f1<<buscador->getNumHoteles()<<endl;
    for(int i=0;i<buscador->getNumHoteles();i++){
            f1<<buscador->getHotel(i)->getNombre()<<endl;
            f1<<buscador->getHotel(i)->getDireccion()<<endl;
            f1<<buscador->getHotel(i)->getCiudad()<<endl;
            f1<<buscador->getHotel(i)->getNumEstrellas()<<endl;
            f1<<buscador->getHotel(i)->getMaxHabitaciones()<<endl;
            f1<<buscador->getHotel(i)->getNumHabitaciones()<<endl;
            for(int j=0;j<buscador->getHotel(i)->getNumHabitaciones();j++){
                f1<<buscador->getHotel(i)->getHabitacion(j)->getNumH()<<endl;
                f1<<buscador->getHotel(i)->getHabitacion(j)->getTipo()<<endl;
                f1<<buscador->getHotel(i)->getHabitacion(j)->getPrecio()<<endl;
                f1<<buscador->getHotel(i)->getHabitacion(j)->getOcupada()<<endl;
            }
    }
    f1.close();
}

Buscador *volcarFicheroABuscador(){
    Buscador *buscador=NULL;
    ifstream f1;
    f1.open("Hoteles.txt",ios::in);
    if(!f1.fail() && !f1.bad()){
        int maxH,numH;
        f1>>maxH;
        f1>>numH;
        buscador = new Buscador(maxH);
        for(int i=0;i<numH;i++){
                char nombre[20];
                char direccion[100];
                char ciudad[40];
                int numEstrellas;
                int maxHabitaciones;
                int numHabitaciones;
                f1>>nombre;
                f1>>direccion;
                f1>>ciudad;
                f1>>numEstrellas;
                f1>>numHabitaciones;
                f1>>maxHabitaciones;
                Hotel *h = new Hotel(nombre,direccion,ciudad,numEstrellas,maxHabitaciones);
                buscador->addHotel(h);
                for(int j=0;j<numHabitaciones;j++){
                        int numHabitacion;
                        char tipo[20];
                        float precio;
                        int ocupada;
                        f1>>numHabitacion;
                        f1>>tipo;
                        f1>>precio;
                        f1>>ocupada;
                        Habitacion *ha = new Habitacion(numHabitacion,tipo,precio,ocupada);
                        buscador->getHotel(i)->addHabitacion(ha);
                }
        }
    }
    f1.close();
    return buscador;
}
int main()
{
    int numHo,numHa,posHo,posHa;
    char opcion;
    char nombre[20],ciudad[20];
    Hotel *h;
    login *l = new login();

    Buscador *buscador= NULL;
    buscador = volcarFicheroABuscador();
    if(buscador==NULL){
        buscador = new Buscador(100);
    }
    l->iniciarSesion();
    do{
        opcion =  menu();
        switch(opcion){
            case '0': printf("Gracias por usar nuestro buscador. ¡Hasta otra!\n"); break;
            case '1':
                buscador->mostrarHoteles();
            break;
            case '2':
                buscador->mostrarHoteles();
                printf("Introduce el hotel que deseas elegir:\n");
                cin>>numHo;
                buscador->getHotel(numHo)->mostrarHabitaciones();
                printf(" \n");
                printf("Elige una habitacion: \n");
                cin>>numHa;
                buscador->getHotel(numHo)->getHabitacion(numHa)->setOcupada(1);
                printf("Habitación reservada correctamente\n");

                break;
            case '3':

                printf("Introduce el nombre del hotel:\n");
                cin>>nombre;
                printf("Introduce la ciudad: \n");
                cin>>ciudad;
                posHo = buscador->buscarHotel(nombre, ciudad);
                if(posHo==-1)
                    printf("Datos del hotel desconocidos\n");
                else{
                    printf("Introduce el numero de habitacion cuya reserva quieres cancelar:\n");
                    cin>>numHa;
                    posHa = buscador->getHotel(posHo)->buscarHabitacion(numHa);
                    if(posHa==-1)
                        printf("Datos de habitacion desconocida\n");
                    else{
                        buscador->getHotel(posHo)->getHabitacion(posHa)->setOcupada(0);
                        printf("Reserva cancelada correctamente\n");
                    }
                }

                break;
            case '4':
                h = new Hotel();
                h->pedirDatos();
                buscador->addHotel(h);
                      break;
            case '5': printf("Introduce el nombre del hotel: \n");
                cin>>nombre;
                printf("Introduce la ciudad: \n");
                cin>>ciudad;
                posHo = buscador->buscarHotel(nombre, ciudad);
                if(posHo==-1)
                    printf("Datos del hotel desconocidos\n");
                else{

                    buscador->revomeHotel(posHo);
                    printf("Hotel eliminado del buscador\n");
                }
            break;
        }
    }while(opcion!='0');
    volcarBuscadorAFichero(buscador);
    return 0;

}
