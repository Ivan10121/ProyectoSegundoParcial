#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>


using namespace std;

void menu(){
    cout<<"Elija una opcion"<<endl;
    cout<<"1.Crear evento"<<endl<<"2.Modificar evento"<<endl<<"3.Eliminar evento"<<endl<<"4.Generar txt con resumen de eventos"<<endl;
}

bool archivo_existe(string nombre)
{
	ifstream archivo(nombre.c_str());
	return archivo.good();
}
void limpiarBuffer()
{
    char c;
    do
    {
        c = getchar();
    }while( c != '\n' );
}

ifstream registroLectura;
ofstream registroEcritura;


class Fecha
{
    private:
        int dia;
        int mes;
        int anio;

    public:

        time_t now=time(0);
        tm*tiempo=localtime(&now);
        int diahoy=tiempo->tm_mday;
        int meshoy=tiempo->tm_mon+1;
        int aniohoy=(tiempo->tm_year-100)+2000;
        //int hora=tiempo->tm_hour;

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
        int diasRestantes(Fecha);
        ~Fecha();
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

bool iguales(Fecha a,Fecha b){
    if(a.getDia()==b.getDia() && a.getMes()==b.getMes() && a.getAnio()==b.getAnio()){
        return true;
    }else{
        return false;
    }
}

int diasRestantes(Fecha a){
    time_t now=time(0);
    tm*tiempo=localtime(&now);
    int diahoy=tiempo->tm_mday;
    int meshoy=tiempo->tm_mon+1;
    int aniohoy=(tiempo->tm_year-100)+2000;
    Fecha hoy=Fecha(diahoy,meshoy,aniohoy);
    int contador=0;
    while(iguales(hoy,a)==false){
        hoy.avanzarDia();
        contador++;
    }
    return contador;
}

Fecha::~Fecha(){}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Evento
{
    private:
        string nombre;
        Fecha fechaEvento;

    public:
        Evento();
        Evento(string,int,int,int);
        Fecha getFecha();
        void setFecha(int,int,int);
        void setNombre(string);
        string getNombre();
        virtual string mostrar();
        ~Evento();
};

Fecha Evento::getFecha(){
    return fechaEvento;
}

void capturaEvento(vector<Evento>&eventos){
    cout<<"Ingrese el nombre del evento"<<endl;
    limpiarBuffer();
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    int dia;cin>>dia;
    int mes;cin>>mes;
    int anio;cin>>anio;
    eventos.push_back(Evento(nombre,dia,mes,anio));
    
    if(registroLectura.fail()){
            cout<<"No se pudo abrir el registro";
        }

    registroEcritura.open("Registro.txt",ios::out|ios::app);
    registroEcritura<<nombre<<endl<<dia<<endl<<mes<<endl<<anio<<endl;
    registroEcritura.close();

}

Evento crearEvento(){
    cout<<"Ingrese el nombre del evento"<<endl;
    limpiarBuffer();
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    int dia;cin>>dia;
    int mes;cin>>mes;
    int anio;cin>>anio;
    return Evento(nombre,dia,mes,anio);
}


Evento::Evento(){}

Evento::Evento(string nombre,int dia,int mes,int anio){
    fechaEvento=Fecha(dia,mes,anio);
    this->nombre=nombre;
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

string Evento::mostrar(){
    string cad=nombre+" "+fechaEvento.getFecha();
    return cad;
}

Evento::~Evento(){}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        ~improvedEvento();
};

void capturaImprovedEvento(vector<improvedEvento>&improvedeventos){
    limpiarBuffer();
    cout<<"Ingrese el nombre del evento"<<endl;
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    int dia;cin>>dia;
    int mes;cin>>mes;
    int anio;cin>>anio;
    cout<<"Ingrese el lugar del evento"<<endl;
    limpiarBuffer();
    string lugar;
    getline(cin,lugar);
    cout<<"Ingrese una descripcion"<<endl;
    string descripcion;
    getline(cin,descripcion);
    improvedeventos.push_back(improvedEvento(nombre,dia,mes,anio,lugar,descripcion));
}

improvedEvento crearImprovedEvento(vector<improvedEvento>&improvedEventos){
    cout<<"Ingrese el nombre del evento"<<endl;
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    int dia;cin>>dia;
    int mes;cin>>mes;
    int anio;cin>>anio;
    cout<<"Ingrese el lugar del evento"<<endl;
    limpiarBuffer();
    string lugar;
    getline(cin,lugar);
    cout<<"Ingrese una descripcion"<<endl;
    string descripcion;
    getline(cin,descripcion);
    improvedEventos.push_back(improvedEvento(nombre,dia,mes,anio,lugar,descripcion));
    if(registroLectura.fail()){
        cout<<"No se pudo abrir el registro";
    }
    registroEcritura.open("Registro2.txt",ios::out|ios::app);
    registroEcritura<<nombre<<endl<<dia<<endl<<mes<<endl<<anio<<endl<<lugar<<endl<<descripcion<<"\n";
    registroEcritura.close();


    return improvedEvento(nombre,dia,mes,anio,lugar,descripcion);
}


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
    cad+="\n"+lugar+"\n"+descripcion;
    return cad;
}

improvedEvento::~improvedEvento(){}


void obtenerRegistro(vector<Evento>& eventos){
    bool existe=archivo_existe("Registro.txt");

    if(existe){
        
        if(registroLectura.fail()){
            cout<<"No se pudo abrir el registro";
        }

        registroLectura.open("Registro.txt",ios::out|ios::app);



        while(!registroLectura.eof()){
            string nombre;
            int a,b,c;
            getline(registroLectura,nombre,'\n');
            registroLectura>>a;
            registroLectura>>b;
            registroLectura>>c;
            registroLectura.get();
            eventos.push_back(Evento(nombre,a,b,c));
        }
        registroLectura.close();
    }
}

/*void obtenerRegistro(vector<improvedEvento>& improvedeventos){
    bool existe=archivo_existe("Registro2.txt");

    if(existe){
        
        if(registroLectura.fail()){
            cout<<"No se pudo abrir el registro"<<endl;
        }

        registroLectura.open("Registro2.txt",ios::out|ios::app);



        while(!registroLectura.eof()){
            string nombre,a,b,c,lugar,descripcion;
            getline(registroLectura,nombre);
            improvedeventos.push_back(improvedEvento(nombre,10,02,2003,lugar,descripcion));
        }
        registroLectura.close();
    }
}*/



void repetirEvento(improvedEvento evento,int x,vector<improvedEvento>&improvedeventos){
    if(x==1){
        Fecha aux=evento.getFecha();
        for(int i=0;i<1;i++){
            for(int j=0;j<7;j++){
                aux.avanzarDia();
            }
            improvedeventos.push_back(improvedEvento(evento.getNombre(),aux.getDia(),aux.getMes(),aux.getAnio(),evento.getLugar(),evento.getDescripcion()));
            registroEcritura.open("Registro2.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<aux.getMes()<<endl<<aux.getAnio()<<endl<<evento.getLugar()<<endl<<evento.getDescripcion()<<endl;
            registroEcritura.close();
        }
    }
    if(x==2){
        
    }

    if(x==3){
        
    }

    if(x==4){
        
    }
}




















