#include "Utilities.h"

int main(){
    
    pthread_t hilo;
    vector<Evento>eventos;
    vector<improvedEvento>improvedeventos;
    obtenerRegistro(eventos);
    obtenerRegistro(improvedeventos);
    pthread_t hilo3;
    if(!archivo_existe("Registro.txt")){
        insertarFechasFestivas(eventos);
    }
    pthread_create(&hilo,NULL,&actualizarTxt1,static_cast<void*>(&eventos));
    pthread_mutex_init(&lock,NULL);

    int opcion=0;
    do{
        menu();
        cin>>opcion;
        switch (opcion)
        {
            case 1:
                cout<<"Desea que su evento tenga lugar y descripcion?"<<endl<<"1.Si         2.No"<<endl;
                int res;cin>>res;
                if(res==1){
                    int op;
                    cout<<"Desea que su evento se repita?"<<endl<<"1.Si      2.No"<<endl;
                    cin>>op;
                    switch(op)
                    {
                        case 1:
                            printf("1.Cada semana            2.Cada mes          3.Cada a%co         4.Personalizado(en dias)\n",164);
                            int op2;
                            cin>>op2;
                            if(op2==1){
                                improvedEvento aux=crearImprovedEvento(improvedeventos);
                                repetirEvento(aux,1,improvedeventos,0);
                            }
                            if(op2==2){
                                improvedEvento aux=crearImprovedEvento(improvedeventos);
                                repetirEvento(aux,2,improvedeventos,0);
                            }
                            if(op2==3){
                                improvedEvento aux=crearImprovedEvento(improvedeventos);
                                repetirEvento(aux,3,improvedeventos,0);
                            }
                            if(op2==4){
                                int x;
                                cout<<"Cada cuantos dias desea que se repita?"<<endl;
                                cin>>x;
                                improvedEvento aux=crearImprovedEvento(improvedeventos);
                                repetirEvento(aux,4,improvedeventos,x);
                            }
                            break;
                        
                        case 2:
                            capturaImprovedEvento(improvedeventos);
                            break;
                    }
                }
                else{
                    int op;
                    cout<<"Dese que su evento se repita?"<<endl<<"1.Si         2.No"<<endl;
                    cin>>op;
                    switch(op)
                    {
                        case 1:
                            printf("1.Cada semana            2.Cada mes          3.Cada a%co         4.Personalizado(en dias)\n",164);
                            int op2;
                            cin>>op2;
                            if(op2==1){
                                Evento aux=crearEvento(eventos);
                                repetirEvento(aux,1,eventos,0);
                            }
                            if(op2==2){
                                Evento aux=crearEvento(eventos);
                                repetirEvento(aux,2,eventos,0);
                            }
                            if(op2==3){
                                Evento aux=crearEvento(eventos);
                                repetirEvento(aux,3,eventos,0);
                            }
                            if(op2==4){
                                int x;
                                cout<<"Cada cuantos dias dese que se repita?"<<endl;
                                cin>>x;
                                Evento aux=crearEvento(eventos);
                                repetirEvento(aux,4,eventos,x);
                            }
                            break;
                        
                        case 2:
                            capturaEvento(eventos);
                            break;
                    }
                }
                break;

            case 2:
            {
                int y=modificarEvento(eventos,improvedeventos);
                pthread_t hilo;
                pthread_t hilo2;
                pthread_create(&hilo,NULL,&actualizarTxt1,static_cast<void*>(&eventos));
                pthread_create(&hilo2,NULL,&actualizarTxt2,static_cast<void*>(&improvedeventos));
                break;
            }

            case 3:
            {
                quitar(eventos,improvedeventos);
                pthread_t hilo;
                pthread_t hilo2;
                pthread_create(&hilo,NULL,&actualizarTxt1,static_cast<void*>(&eventos));
                pthread_create(&hilo2,NULL,&actualizarTxt2,static_cast<void*>(&improvedeventos));
                break;
            }
            
            case 4:
                buscar(eventos,improvedeventos);
                break;

            case 5:
                int op;
                cout<<"1.Dias restantes con un evento           2.Dias restantes con una fecha nueva"<<endl;
                cin>>op;
                if(op==1){
                    cuentaDias(eventos,improvedeventos);
                }
                if(op==2){
                    cuentaDias();
                }
                break;

            case 6:
                generarTxt(eventos,improvedeventos);
                break;

            case 7:
                break;
            
            default:
                cout<<"Opcion no valida."<<endl<<endl;
        }
    }while(opcion!=7);

    return 0;
}