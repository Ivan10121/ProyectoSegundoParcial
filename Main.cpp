#include "MyLib.h"

int main(){

    vector<Evento> eventos;
    obtenerRegistro(eventos);
    for(auto it=eventos.begin();it!=eventos.end();it++){
        Evento aux=*it;
        cout<<aux.mostrar()<<endl;
    }
    cout<<eventos.size()<<endl;





    

   




    

    
    /*int opcion=0;
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
                                repetirEvento(aux,1,improvedeventos);
                            }
                            if(op2==2){

                            }
                            if(op2==3){

                            }
                            if(op2==4){

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

                            }
                            if(op2==2){

                            }
                            if(op2==3){

                            }
                            if(op2==4){

                            }
                            break;
                        
                        case 2:
                            capturaEvento(eventos);
                            break;
                    }
                }
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                for(auto it=eventos.begin();it != eventos.end(); it++){
                    Evento aux=*it;
                    cout<<aux.mostrar()<<endl;
                }
                for(auto it=improvedeventos.begin();it != improvedeventos.end(); it++){
                    improvedEvento aux=*it;
                    cout<<aux.mostrar()<<endl;
                }
                break;

            case 9:
                break;
            
            default:
                cout<<"Opcion no valida."<<endl<<endl;
        }
    }while(opcion!=9);*/

    return 0;
}