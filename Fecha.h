#include <iostream>

using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha();
        Fecha(int,int,int);
        int getDia();
        int getMes();
        int getAnio();
        int getDias();
        string getFecha();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        void setFecha(int,int,int);
        void avanzarDia();
        ~Fecha();

        bool operator>(const Fecha & other){
            bool res=false;
            if(this->anio>other.anio){
                
            }
            return res;
        }

        bool operator<(const Fecha &other) const 
        {
            bool res=false;
            if( (this->anio<=other.anio) && (this->mes<=other.mes) && (this->dia<=other.dia) ){
                res=true;
                return res;
            }
            return res;
        }
};

Fecha::Fecha(){}

Fecha::Fecha(int dia,int mes,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

int Fecha::getDias(){
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        return 31;
    }
    else if(mes==2){
            return 28;
        }
        else{
            return 30;
        }
}

string Fecha::getFecha(){
    string cad;
    cad=to_string(getDia())+("/")+to_string(getMes())+("/")+to_string(getAnio());
    return cad;
}

void Fecha::setDia(int dia){
    this->dia=dia;
}

void Fecha::setMes(int mes){
    this->mes=mes;
}

void Fecha::setAnio(int anio){
    this->anio=anio;
}

void Fecha::setFecha(int dia,int mes,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}

void Fecha::avanzarDia(){
    if(dia==getDias() && mes!=12){
        mes++;
        dia=1;
    }
    else if(dia==getDias() && mes==12){
        mes=1;
        dia=1;
        anio++;
    }
    else{
        dia++;
    }
}

Fecha::~Fecha(){}