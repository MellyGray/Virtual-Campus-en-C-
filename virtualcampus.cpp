#include "virtualcampus.h"

VirtualCampus::VirtualCampus()
{
 list=new ListUsers;
}

VirtualCampus::~VirtualCampus()
{

}
int VirtualCampus::start(){
    User *aux;
    list->ChargeUsers();
    string _IDCode,_password;
    int op=1;//Gets the number typed by the user
    char c;
    do{
        cout<<"\033[2J\033[1;1H";
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=1&&op!=0){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        };
        cout<<"--------WELCOME TO VIRTUAL CAMPUS!---------"<<endl;
        cout<<"You have to be registered to enter."<<endl;
        cout<<"1) CONTINUE"<<endl;
        cout<<"0) EXIT"<<endl;
        cin>>op;
        if(op==1){
        cout<<"ID:";
        cin>>_IDCode;
        cout<<"\n";
        cout<<"Password:";
        cin>>_password;
        cout<<"\n";
        aux=list->Logging(_IDCode,_password);//Checks if the user is on the list
        if(aux!=NULL){
           aux->UserMenu();
           cout << "Press enter to continue ..."<<endl;
           cin.get();
        }else{
            cout<<"Wrong password or ID!"<<endl;
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            op=2;
        }

       }
    }while(op!=0);
    return op;
}
