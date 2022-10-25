#include <iostream>
#include "Evento.h"
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <ctime>
#include <pthread.h>

using namespace std;

Evento ev1=Evento("Día de la Constitución",5,2,2022);
Evento ev2=Evento("Natalicio de Benito",21,3,2022);
Evento ev3=Evento("Domingo de Pascua",17,4,2022);
Evento ev4=Evento("Día del trabajo",1,5,2022);
Evento ev5=Evento("Día del maestro",15,5,2022);
Evento ev6=Evento("Día de la independencia",16,9,2022);
Evento ev7=Evento("Día de la raza",12,10,2022);
Evento ev8=Evento("Día de muertos",2,11,2022);
Evento ev9=Evento("Día de la Revolucion",20,11,2022);
Evento ev10=Evento("Navidad",25,12,2022);
Evento ev11=Evento("Fiesta de fin de año",31,12,2022);


ifstream registroLectura;
ofstream registroEcritura;

time_t now=time(0);
tm*tiempo=localtime(&now);
int diahoy=tiempo->tm_mday;
int meshoy=tiempo->tm_mon+1;
int aniohoy=(tiempo->tm_year-100)+2000;
Fecha todayy=Fecha(diahoy,meshoy,aniohoy);


void menu(){
    cout<<"Elija una opcion"<<endl;
    cout<<"1.Crear evento"<<endl<<"2.Modificar evento"<<endl<<"3.Eliminar evento"<<endl<<"4.Buscar evento"<<endl<<"5.Dias restantes"<<endl<<"6.Generar txt con resumen del mes"<<endl;
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


void obtenerRegistro(vector<Evento>& eventos){
    bool existe=archivo_existe("Registro.txt");

    if(existe){
        
        registroLectura.open("Registro.txt",ios::out|ios::app);



        while(!registroLectura.eof()){
            string nombre;
            string cad="";
            int a,b,c;
            getline(registroLectura,nombre);
            if(nombre.compare(cad)!=0){
                registroLectura>>a;
                registroLectura>>b;
                registroLectura>>c;
                eventos.push_back(Evento(nombre,a,b,c));
            }
        }
        registroLectura.close();
    }
}

void obtenerRegistro(vector<improvedEvento>& improvedeventos){
    bool existe=archivo_existe("Registro2.txt");

    if(existe){
    
        registroLectura.open("Registro2.txt",ios::out|ios::app);



        while(!registroLectura.eof()){
            string nombre,a,b,c,lugar,descripcion;
            string cad="";
            getline(registroLectura,nombre);
            if(nombre.compare(cad)!=0){
                getline(registroLectura,a);
                getline(registroLectura,b);
                getline(registroLectura,c);
                getline(registroLectura,lugar);
                getline(registroLectura,descripcion);
                int dia=stoi(a);
                int mes=stoi(b);
                int anio=stoi(c);
                improvedeventos.push_back(improvedEvento(nombre,dia,mes,anio,lugar,descripcion));
            }
        }
        registroLectura.close();
    }
}

void capturaEvento(vector<Evento>&eventos){
    cout<<"Ingrese el nombre del evento"<<endl;
    limpiarBuffer();
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    string dia;
    string mes;
    string anio;
    cin>>dia;
    cin>>mes;
    cin>>anio;

    try{
        int a=stoi(dia);
        int b=stoi(mes);
        int c=stoi(anio);
        eventos.push_back(Evento(nombre,a,b,c));
        registroEcritura.open("Registro.txt",ios::out|ios::app);
        registroEcritura<<nombre<<endl<<a<<endl<<b<<endl<<c<<endl;
        registroEcritura.close();
    }
    catch(exception e){
        cout<<"Por favor ingrese la fecha con el formato especificado"<<endl<<endl;
    }
}

Evento crearEvento(vector<Evento>&eventos){
    
    cout<<"Ingrese el nombre del evento"<<endl;
    limpiarBuffer();
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    string dia;
    string mes;
    string anio;
    cin>>dia;
    cin>>mes;
    cin>>anio;

    try{
        int a=stoi(dia);
        int b=stoi(mes);
        int c=stoi(anio);
        eventos.push_back(Evento(nombre,a,b,c));
        registroEcritura.open("Registro.txt",ios::out|ios::app);
        registroEcritura<<nombre<<endl<<a<<endl<<b<<endl<<c<<endl;
        registroEcritura.close();
        return Evento(nombre,a,b,c);
    }
    catch(exception e){
        throw "Por favor ingrese la fecha con el formato especificado\n\n";
    }
}

void capturaImprovedEvento(vector<improvedEvento>&improvedeventos){
    limpiarBuffer();
    cout<<"Ingrese el nombre del evento"<<endl;
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;

    string dia;
    string mes;
    string anio;
    cin>>dia;
    cin>>mes;
    cin>>anio;

    try{
        int a=stoi(dia);
        int b=stoi(mes);
        int c=stoi(anio);
        cout<<"Ingrese el lugar del evento"<<endl;
        limpiarBuffer();
        string lugar;
        getline(cin,lugar);
        cout<<"Ingrese una descripcion"<<endl;
        string descripcion;
        getline(cin,descripcion);
        improvedeventos.push_back(improvedEvento(nombre,a,b,c,lugar,descripcion));

        registroEcritura.open("Registro2.txt",ios::out|ios::app);
        registroEcritura<<nombre<<endl<<a<<endl<<b<<endl<<c<<endl<<lugar<<endl<<descripcion<<endl;
        registroEcritura.close();
    }
    catch(exception e){
        cout<<"Por favor ingrese la fecha con el formato especificado"<<endl<<endl;
    }
}

improvedEvento crearImprovedEvento(vector<improvedEvento>&improvedEventos){
    limpiarBuffer();
    cout<<"Ingrese el nombre del evento"<<endl;
    string nombre;
    getline(cin,nombre);
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    string dia;
    string mes;
    string anio;
    cin>>dia;
    cin>>mes;
    cin>>anio;
    try{
        int a=stoi(dia);
        int b=stoi(mes);
        int c=stoi(anio);
        cout<<"Ingrese el lugar del evento"<<endl;
        limpiarBuffer();
        string lugar;
        getline(cin,lugar);
        cout<<"Ingrese una descripcion"<<endl;
        string descripcion;
        getline(cin,descripcion);
        improvedEventos.push_back(improvedEvento(nombre,a,b,c,lugar,descripcion));
        registroEcritura.open("Registro2.txt",ios::out|ios::app);
        registroEcritura<<nombre<<endl<<a<<endl<<b<<endl<<c<<endl<<lugar<<endl<<descripcion<<"\n";
        registroEcritura.close();
        return improvedEvento(nombre,a,b,c,lugar,descripcion);
    }
    catch(exception e){
        throw "Por favor ingrese la fecha con el formato especificado\n\n";
    }
    
}

void repetirEvento(Evento evento,int x,vector<Evento>&eventos,int frec){
    if(x==1){
        Fecha aux=evento.getFecha();
        for(int i=0;i<48;i++){
            for(int j=0;j<7;j++){
                aux.avanzarDia();
            }
            eventos.push_back(Evento(evento.getNombre(),aux.getDia(),aux.getMes(),aux.getAnio()));
            registroEcritura.open("Registro.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<aux.getMes()<<endl<<aux.getAnio()<<endl;
            registroEcritura.close();
        }
    }
    if(x==2){
        Fecha aux=evento.getFecha();
        int mes=aux.getMes();
        int anio=aux.getAnio();
        for(int i=0;i<12;i++){
            mes++;
            if(mes==13){
                mes=1;
                anio++;
            }
            eventos.push_back(Evento(evento.getNombre(),aux.getDia(),mes,anio));
            registroEcritura.open("Registro.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<mes<<endl<<anio<<endl;
            registroEcritura.close();
        }
    }

    if(x==3){
        Fecha aux=evento.getFecha();
        int anio=aux.getAnio();
        for(int i=0;i<5;i++){
            anio++;
            eventos.push_back(Evento(evento.getNombre(),aux.getDia(),aux.getMes(),anio));
            registroEcritura.open("Registro.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<aux.getMes()<<endl<<anio<<endl;
            registroEcritura.close();
        }
    }

    if(x==4){
        Fecha aux=evento.getFecha();
        for(int i=0;i<10;i++){
            for(int j=0;j<frec;j++){
                aux.avanzarDia();
            }
            eventos.push_back(Evento(evento.getNombre(),aux.getDia(),aux.getMes(),aux.getAnio()));
            registroEcritura.open("Registro.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<aux.getMes()<<endl<<aux.getAnio()<<endl;
            registroEcritura.close();
        }
        
    }
}




void repetirEvento(improvedEvento evento,int x,vector<improvedEvento>&improvedeventos,int frec){
    if(x==1){
        Fecha aux=evento.getFecha();
        for(int i=0;i<48;i++){
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
        Fecha aux=evento.getFecha();
        int mes=aux.getMes();
        int anio=aux.getAnio();
        for(int i=0;i<12;i++){
            mes++;
            if(mes==13){
                mes=1;
                anio++;
            }
            improvedeventos.push_back(improvedEvento(evento.getNombre(),aux.getDia(),mes,anio,evento.getLugar(),evento.getDescripcion()));
            registroEcritura.open("Registro2.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<mes<<endl<<anio<<endl<<evento.getLugar()<<endl<<evento.getDescripcion()<<endl;
            registroEcritura.close();
        }
    }

    if(x==3){
        Fecha aux=evento.getFecha();
        int anio=aux.getAnio();
        for(int i=0;i<5;i++){
            anio++;
            improvedeventos.push_back(improvedEvento(evento.getNombre(),aux.getDia(),aux.getMes(),anio,evento.getLugar(),evento.getDescripcion()));
            registroEcritura.open("Registro2.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<aux.getMes()<<endl<<anio<<endl<<evento.getLugar()<<endl<<evento.getDescripcion()<<endl;
            registroEcritura.close();
        }
    }

    if(x==4){
        Fecha aux=evento.getFecha();
        for(int i=0;i<10;i++){
            for(int j=0;j<frec;j++){
                aux.avanzarDia();
            }
            improvedeventos.push_back(improvedEvento(evento.getNombre(),aux.getDia(),aux.getMes(),aux.getAnio(),evento.getLugar(),evento.getDescripcion()));
            registroEcritura.open("Registro2.txt",ios::out|ios::app);
            registroEcritura<<evento.getNombre()<<endl<<aux.getDia()<<endl<<aux.getMes()<<endl<<aux.getAnio()<<endl<<evento.getLugar()<<endl<<evento.getDescripcion()<<endl;
            registroEcritura.close();
        }
        
    }
}

int modificarEvento(vector<Evento>&eventos,vector<improvedEvento>&improvedeventos){
    bool vec1=false,vec2=false;
    cout<<"Ingrese el nombre del evento que desea modificar"<<endl;
    limpiarBuffer();
    string nombre;getline(cin,nombre);
    map<string,Evento> mapa1;
    map<string,improvedEvento> mapa2;

    for(auto it=eventos.begin();it != eventos.end(); it++){
        Evento aux=*it;
        string cad=aux.getNombre();
        mapa1.insert(make_pair(cad,aux));
    }

    for(auto it=improvedeventos.begin();it != improvedeventos.end(); it++){
        improvedEvento aux=*it;
        string cad=aux.getNombre();
        mapa2.insert(make_pair(cad,aux));
    }

    if(mapa1.find(nombre) != mapa1.end()){
        vec1=true;
    }
    if(mapa2.find(nombre) != mapa2.end()){
        vec2=true;
    }

    if(!vec1 && !vec2){
        cout<<"El evento no existe"<<endl;
    }

    if(vec1){
        int op;
        cout<<"Que desea modificar?"<<endl;
        printf("1.Nombre            2.Dia          3.Mes            4.A%co\n",164);
        cin>>op;

        if(op==1){
            string cad;
            cout<<"Ingrese el nuevo nombre"<<endl;
            limpiarBuffer();
            getline(cin,cad);
            for(int i=0;i<eventos.size();i++){
                if(eventos[i].getNombre().compare(nombre)==0){
                    eventos[i].setNombre(cad);
                }
            }

        }

        if(op==2){
            int dia;
            cout<<"Ingrese el nuevo dia"<<endl;
            cin>>dia;
            for(int i=0;i<eventos.size();i++){
                if(eventos[i].getNombre().compare(nombre)==0){
                    eventos[i].setDia(dia);
                }
            }
        }

        if(op==3){
            int mes;
            cout<<"Ingrese el nuevo mes"<<endl;
            cin>>mes;
            for(int i=0;i<eventos.size();i++){
                if(eventos[i].getNombre().compare(nombre)==0){
                    eventos[i].setMes(mes);
                }
            }
        }

        if(op==4){
            int anio;
            printf("Ingrese el nuevo a%co\n",164);            
            cin>>anio;
            for(int i=0;i<eventos.size();i++){
                if(eventos[i].getNombre().compare(nombre)==0){
                    eventos[i].setAnio(anio);
                }
            }
        }
        return 1;
    }

    if(vec2){
        int op;
        cout<<"Que desea modificar?"<<endl;
        printf("1.Nombre            2.Dia          3.Mes            4.A%co          5.Lugar         6.Descripcion\n",164);
        cin>>op;

        if(op==1){
            string cad;
            cout<<"Ingrese el nuevo nombre"<<endl;
            limpiarBuffer();
            getline(cin,cad);
            for(int i=0;i<improvedeventos.size();i++){
                if(improvedeventos[i].getNombre().compare(nombre)==0){
                    improvedeventos[i].setNombre(cad);
                }
            }
        }

        if(op==2){
            int dia;
            cout<<"Ingrese el nuevo dia"<<endl;
            cin>>dia;
            for(int i=0;i<improvedeventos.size();i++){
                if(improvedeventos[i].getNombre().compare(nombre)==0){
                    improvedeventos[i].setDia(dia);
                }
            }
        }

        if(op==3){
            int mes;
            cout<<"Ingrese el nuevo mes"<<endl;
            cin>>mes;
            for(int i=0;i<improvedeventos.size();i++){
                if(improvedeventos[i].getNombre().compare(nombre)==0){
                    improvedeventos[i].setMes(mes);
                }
            }
        }

        if(op==4){
            int anio;
            printf("Ingrese el nuevo a%co\n",164);
            cin>>anio;
            for(int i=0;i<improvedeventos.size();i++){
                if(improvedeventos[i].getNombre().compare(nombre)==0){
                    improvedeventos[i].setAnio(anio);
                }
            }
        }

        if(op==5){
            string cad;
            cout<<"Ingrese el nuevo lugar"<<endl;
            limpiarBuffer();
            getline(cin,cad);
            for(int i=0;i<improvedeventos.size();i++){
                if(improvedeventos[i].getNombre().compare(nombre)==0){
                    improvedeventos[i].setLugar(cad);
                }
            }
        }

        if(op==6){
            string cad;
            cout<<"Ingrese la nueva descripcion"<<endl;
            limpiarBuffer();
            getline(cin,cad);
            for(int i=0;i<improvedeventos.size();i++){
                if(improvedeventos[i].getNombre().compare(nombre)==0){
                    improvedeventos[i].setDescripcion(cad);
                }
            }
        }
        return 2;
    }
    else{
        return 0;
    }
}


int quitar(vector<Evento>&eventos,vector<improvedEvento>&improvedeventos){
    bool vec1,vec2;
    cout<<"Ingrese el nombre del evento que desea eliminar"<<endl;
    limpiarBuffer();
    string nombre;
    getline(cin,nombre);
    map<string,Evento> mapa1;
    map<string,improvedEvento> mapa2;

    for(auto it=eventos.begin();it != eventos.end(); it++){
        Evento aux=*it;
        string cad=aux.getNombre();
        mapa1.insert(make_pair(cad,aux));
    }

    for(auto it=improvedeventos.begin();it != improvedeventos.end(); it++){
        improvedEvento aux=*it;
        string cad=aux.getNombre();
        mapa2.insert(make_pair(cad,aux));
    }

    if(mapa1.find(nombre) != mapa1.end()){
        vec1=true;
    }
    if(mapa2.find(nombre) != mapa2.end()){
        vec2=true;
    }

    if(!vec1 && !vec2){
        cout<<"El evento que desea eliminar no existe"<<endl;
    }

    if(vec1){
        if(eventos.size()>1){
            for(auto it=eventos.begin();it!=eventos.end();++it){
                Evento aux=*it;
                string cad=aux.getNombre();
                if(cad==nombre){
                    eventos.erase(it);
                }
            }
        }else{
            eventos.clear();
        }
        return 1;
    }

    if(vec2){
        if(improvedeventos.size()>1){
            for(auto it=improvedeventos.begin();it!=improvedeventos.end();++it){
                improvedEvento aux=*it;
                string cad=aux.getNombre();
                if(cad==nombre){
                    improvedeventos.erase(it);
                }
            }
        }else{
            improvedeventos.clear();
        }
        return 2;
    }
    else{
        return 0;
    }
}


void *actualizarTxt1(void *args){

    vector<Evento>&eventos=*reinterpret_cast<vector<Evento>*>(args);

    ofstream auxiliar;

    auxiliar.open("Auxiliar.txt",ios::out|ios::app);
    for(auto it=eventos.begin();it!=eventos.end();it++){
        Evento aux=*it;
        Fecha fechaaux=aux.getFecha();
        auxiliar<<aux.getNombre()<<endl<<fechaaux.getDia()<<endl<<fechaaux.getMes()<<endl<<fechaaux.getAnio()<<endl;
    }
    auxiliar.close();
    remove("Registro.txt");
    rename("Auxiliar.txt","Registro.txt");
    pthread_exit(NULL);

}

void *actualizarTxt2(void *args){
    vector<improvedEvento>&improvedeventos=*reinterpret_cast<vector<improvedEvento>*>(args);
    ofstream auxiliar;
    auxiliar.open("Auxiliar.txt",ios::out|ios::app);
    for(auto it=improvedeventos.begin();it!=improvedeventos.end();it++){
        improvedEvento aux=*it;
        Fecha fechaaux=aux.getFecha();
        auxiliar<<aux.getNombre()<<endl<<fechaaux.getDia()<<endl<<fechaaux.getMes()<<endl<<fechaaux.getAnio()<<endl<<aux.getLugar()<<endl<<aux.getDescripcion()<<endl;
    }
    auxiliar.close();
    remove("Registro2.txt");
    rename("Auxiliar.txt","Registro2.txt");
}


void buscar(vector<Evento>&eventos,vector<improvedEvento>&improvedeventos){
    cout<<"Ingrese el nombre del evento que desea busacar"<<endl;
    limpiarBuffer();
    string nombre;getline(cin,nombre);
    map<string,Evento> mapa1;
    map<string,improvedEvento> mapa2;
    
    for(auto it=eventos.begin();it != eventos.end(); it++){
        Evento aux=*it;
        string cad=aux.getNombre();
        mapa1.insert(make_pair(cad,aux));
    }

    for(auto it=improvedeventos.begin();it != improvedeventos.end(); it++){
        improvedEvento aux=*it;
        string cad=aux.getNombre();
        mapa2.insert(make_pair(cad,aux));
    }

    if(mapa1.find(nombre)==mapa1.end() && mapa2.find(nombre)==mapa2.end()){
        cout<<"El evento no existe"<<endl<<endl;
    }

    if(mapa1.find(nombre) != mapa1.end()){
        auto it=mapa1.find(nombre);
        Evento aux=it->second;
        cout<<aux.mostrar()<<endl<<endl;
    }

    if(mapa2.find(nombre) != mapa2.end()){
        auto it=mapa2.find(nombre);
        improvedEvento aux=it->second;
        cout<<aux.mostrar()<<endl<<endl;
    }
}

void cuentaDias(vector<Evento>&eventos,vector<improvedEvento>&improvedeventos){
    cout<<"Ingrese el nombre del evento que desea busacar"<<endl;
    limpiarBuffer();
    string nombre;getline(cin,nombre);
    map<string,Evento> mapa1;
    map<string,improvedEvento> mapa2;
    
    for(auto it=eventos.begin();it != eventos.end(); it++){
        Evento aux=*it;
        string cad=aux.getNombre();
        mapa1.insert(make_pair(cad,aux));
    }

    for(auto it=improvedeventos.begin();it != improvedeventos.end(); it++){
        improvedEvento aux=*it;
        string cad=aux.getNombre();
        mapa2.insert(make_pair(cad,aux));
    }

    if(mapa1.find(nombre)==mapa1.end() && mapa2.find(nombre)==mapa2.end()){
        cout<<"El evento no existe"<<endl<<endl;
    }

    if(mapa1.find(nombre) != mapa1.end()){
        auto it=mapa1.find(nombre);
        Evento aux=it->second;
        Fecha a=aux.getFecha();
        if(todayy<a==false){
            printf("Este evento ya pas%c\n\n",162);
        }else{
            cout<<"Fatan "<<diasRestantes(aux.getFecha())<<" para este evento"<<endl;
        }
    }

    if(mapa2.find(nombre) != mapa2.end()){
        auto it=mapa2.find(nombre);
        improvedEvento aux=it->second;
        Fecha a=aux.getFecha();
        if(todayy<a==false){
            printf("Este evento ya pas%c\n\n",162);
        }else{
            cout<<"Fatan "<<diasRestantes(aux.getFecha())<<" dias para este evento"<<endl;
        }
    }
}

void cuentaDias(){
    cout<<"Ingrese la fecha del evento con el formato DD MM AAAA"<<endl;
    limpiarBuffer();
    string dia;
    string mes;
    string anio;
    cin>>dia;
    cin>>mes;
    cin>>anio;
    try{
        int a=stoi(dia);
        int b=stoi(mes);
        int c=stoi(anio);
        Fecha aux=Fecha(a,b,c);
        if(todayy>aux){
            printf("Esta fecha ya pas%c\n\n",162);
        }else{
            cout<<"Fatan "<<diasRestantes(aux)<<" dias para esta fecha"<<endl;
        }

    }
    catch(exception e){
        cout<<"Por favor ingrese la fecha con el formato especificado"<<endl<<endl;
    }
}

void generarTxt(vector<Evento>&eventos,vector<improvedEvento>&improvedeventos){
    set<Evento> set1;
    set<improvedEvento> set2;
    for(auto it=eventos.begin();it!=eventos.end();it++){
        Evento aux=*it;
        Fecha auxf=aux.getFecha();
        if(auxf.getMes()==meshoy && auxf.getAnio()==aniohoy){
            set1.insert(aux);
        }
    }

    registroEcritura.open("Resumen del mes.txt",ios::out|ios::app);
    for(auto it=set1.begin();it!=set1.end();it++){
        Evento aux=*it;
        Fecha fechaaux=aux.getFecha();
        registroEcritura<<"Evento: "<<aux.getNombre()<<endl<<"Fecha: "<<fechaaux.getDia()<<"/"<<fechaaux.getMes()<<"/"<<fechaaux.getAnio()<<endl<<endl;
    }
    registroEcritura.close();


    for(auto it=improvedeventos.begin();it!=improvedeventos.end();it++){
        improvedEvento aux=*it;
        Fecha auxf=aux.getFecha();
        if(auxf.getMes()==meshoy && auxf.getAnio()==aniohoy){
            set2.insert(aux);
        }
    }
    registroEcritura.open("Resumen del mes.txt",ios::out|ios::app);
    for(auto it=set2.begin();it!=set2.end();it++){
        improvedEvento aux=*it;
        Fecha fechaaux=aux.getFecha();
        registroEcritura<<"Evento: "<<aux.getNombre()<<endl<<"Fecha: "<<fechaaux.getDia()<<"/"<<fechaaux.getMes()<<"/"<<fechaaux.getAnio()<<endl<<"Lugar: "<<aux.getLugar()<<endl<<"Descripcion: "<<aux.getDescripcion()<<endl<<endl;
    }
    registroEcritura.close();
}

void insertarFechasFestivas(vector<Evento>&eventos){
    eventos.push_back(ev1);
    eventos.push_back(ev2);
    eventos.push_back(ev3);
    eventos.push_back(ev4);
    eventos.push_back(ev5);
    eventos.push_back(ev6);
    eventos.push_back(ev7);
    eventos.push_back(ev8);
    eventos.push_back(ev9);
    eventos.push_back(ev10);
    eventos.push_back(ev11);
}