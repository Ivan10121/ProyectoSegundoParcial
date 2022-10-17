#include "MyLib.h"

int main(){

    vector<Evento*>eventos;

    eventos.push_back(new improvedEvento("Graduacion",10,2,2003,"Universidad","Hay graduacion este dia"));

    cout<<eventos[0]->mostrar();


    return 0;

}