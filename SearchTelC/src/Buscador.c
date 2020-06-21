#include "Buscador.h"
#include <string.h>
#include <iostream>
using namespace std;
Buscador::Buscador(int maxH)
{
    hoteles = new Hotel*[maxH];
    maxHoteles = maxH;
    numHoteles = 0;
}
int Buscador::getNumHoteles() const
{
    return numHoteles;

}
int Buscador::getMaxHoteles() const
{
    return maxHoteles;
}

Hotel* Buscador::getHotel(int pos) const{
    return hoteles[pos];
}
void Buscador::addHotel(Hotel *h)
{
    hoteles[numHoteles] = h;
    numHoteles++;
}

void Buscador::mostrarHoteles(){
    if(numHoteles==0)
        cout<<"No tenemos hoteles registrados por el momento...";
    else{
        for(int i=0;i<numHoteles;i++){
            cout<<i<<" ";
            hoteles[i]->mostrarHotel();
        }

    }
}

int Buscador::buscarHotel(char *nom, char *ciu){
    int pos=0,enc=0;

    while(pos<numHoteles && enc==0){
        if(strcmp(hoteles[pos]->getNombre(), nom)== 0 && strcmp(hoteles[pos]->getCiudad(),ciu)==0)
            enc=1;
        else
            pos++;
    }
    if(!enc)
        pos=-1;
    return pos;
}

void Buscador::revomeHotel(int pos){
    int i;
    for(i=pos;i<numHoteles-1;i++)
        hoteles[i] = hoteles[i+1];
    hoteles[i] = NULL;
    numHoteles--;
}

Buscador::~Buscador()
{
    delete[] hoteles;
}

