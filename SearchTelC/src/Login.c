#include "login.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


login::login(){
    nombre = new char[20];
    pass = new char[20];
}

login::login(char *n,char *p){
    nombre = new char[strlen(n)+1];
    strcpy(nombre,n);
    pass = new char[strlen(n)+1];
    strcpy(pass,p);


}


void login::iniciarSesion(){

 int i;
 for(i=1; i<4; i++){
    system("cls");

    cout << endl;
    cout << "Por favor ingrese su informacion de usuario" << endl;
    cout << endl;
    cout << "Nombre de usuario: ";
    cin >> nombre;
    if(strcmp(nombre,"usuario")==0){
        cout << "Nombre de usuario correcto, por favor ingrese su contrasena:" << endl;
        cin >> pass;
        if(strcmp(pass,"123")==0){
            cout<<"Contraseña correcta"<<endl;

            system("pause>null");
            cout<<"            " <<endl;
                cout<<"Bienvenido a SearchTel" <<endl;
            i=4;
        }else {
            cout << "Contrasena incorrecta, por favor ingrese un usuario y contrasena valida" << endl;
            system("pause>null");
        }
    }else {
        cout<<"Nombre de usuario incorrecto, por favor, intentelo de nuevo"<<endl;
        system("pause>null");
    }

    if(i!=4){
        if(i > 0){
            cout << endl;
            cout << "Ha realizado " << i << "/3 intentos" << endl;
            cout << endl;
            system("pause>null");
        }
        else if(i == 3){
            cout << endl;
            cout << "Ha realizado 3 intentos, por seguridad el programa se cerrara..." << endl;
            system("pause>null");
            exit(0);
        }
    }

 }

}

login::~login()
{
    delete[] nombre;
    delete[] pass;

}
