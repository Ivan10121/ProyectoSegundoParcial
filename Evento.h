#include <iostream>
#include "Fecha.h"

class Evento
{
    protected:
    Fecha fechaEvento;

    private:
        string nombre;

    public:
        Evento();
        Evento(string,int,int,int);
        Fecha getFecha();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        void setFecha(int,int,int);
        void setNombre(string);
        string getNombre();
        virtual string mostrar();
        bool operator<(const Evento &other) const
        {
            Evento aux=other;
            Fecha a=aux.getFecha();
            return fechaEvento<a;
        }

        ~Evento();
};

Evento::Evento(){}

Evento::Evento(string nombre,int dia,int mes,int anio){
    fechaEvento=Fecha(dia,mes,anio);
    this->nombre=nombre;
}

void Evento::setDia(int x){
    fechaEvento.setDia(x);
}

void Evento::setMes(int x){
    fechaEvento.setMes(x);
}

void Evento::setAnio(int x){
    fechaEvento.setAnio(x);
}

void Evento::setFecha(int dia,int mes,int anio){
    fechaEvento=Fecha(dia,mes,anio);
}

void Evento::setNombre(string nombre){
    this->nombre=nombre;
}

string Evento::getNombre(){
    return nombre;
}

Fecha Evento::getFecha(){
    return fechaEvento;
}

string Evento::mostrar(){
    string cad="\nEvento: "+nombre+"\n"+"Fecha: "+fechaEvento.getFecha();
    return cad;
}

Evento::~Evento(){}


class improvedEvento:public Evento
{
    private:
        string lugar;
        string descripcion;

    public:
        improvedEvento();
        improvedEvento(string,int,int,int,string,string);
        void setLugar(string);
        void setDescripcion(string);
        string getLugar();
        string getDescripcion();
        string mostrar();
        bool operator<(const improvedEvento &other) const
        {
            improvedEvento aux=other;
            Fecha a=aux.getFecha();
            Fecha b=this->fechaEvento;
            return b<a;
        }
        ~improvedEvento();
};


improvedEvento::improvedEvento(){}

improvedEvento::improvedEvento(string nombre,int dia,int mes,int anio,string lugar,string descripcion):Evento(nombre,dia,mes,anio){
    this->lugar=lugar;
    this->descripcion=descripcion;
}

void improvedEvento::setLugar(string lugar){
    this->lugar=lugar;
}

void improvedEvento::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

string improvedEvento::getLugar(){
    return lugar;
}

string improvedEvento::getDescripcion(){
    return descripcion;
}

string improvedEvento::mostrar(){
    string cad=Evento::mostrar();
    cad+="\nLugar: "+lugar+"\nDescripcion: "+descripcion;
    return cad;
}

improvedEvento::~improvedEvento(){}