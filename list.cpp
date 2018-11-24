#include "list.h"


List::List()
{
    actual= NULL;
};
void List::selectresource(Resource *res){
    actual = new Nodo(res, actual);
};
string List::toString(){
    stringstream s;
    Nodo *get=actual;
    Resource *res;
    while (get!= NULL){
        res= get->Getresource();
        s<<res->toString()<<endl;
        get= get->Getnext();
    }
    return s.str();
};
List::~List(){
    Nodo *get=actual;
    Nodo *aux;
    while (get!=NULL){
        aux=get->Getnext();
        delete get;
        get=aux;
    }
    actual=NULL;
};
void List::keepresource(){
    Nodo *get=actual, *aux =actual;
    int position_sem=((num_cour+num_fdp)+2);
    Resource *res;
    ofstream write("Resources.txt", ios::out);
    write<<num_cour<<endl;
    write<<num_fdp<<endl;
    write<<num_sem<<endl;
    for(int i=0;i<position_sem;i++){
        get= get->Getnext();
}
    for(int j=0;j<(num_sem+1);j++){
        res= get->Getresource();
        res->datasaving(write);
        get=get->Getnext();
    }
    get=aux;
    for(int k=0;k<(num_cour+1);k++){
        get= get->Getnext();
}
    for(int l=0;l<(num_fdp+1);l++){
        res= get->Getresource();
        res->datasaving(write);
        get=get->Getnext();
    }
    get=aux;
    for(int h=0;h<(num_cour+1);h++){
        res= get->Getresource();
        res->datasaving(write);
        get=get->Getnext();
    }
    write.close();
};
void List::chargeresource(){
    ifstream read("Resources.txt", ios::in);
    Course cour_aux,cour;
    FDP fdp_aux,fdp;
    Seminar sem_aux,sem;
    Resource *res;
    read>>num_cour;
    read>>num_fdp;
    read>>num_sem;
    res=&sem;
    res=sem_aux.readTxt(read);
        for (int k=0;k<num_sem;k++)
        {
                selectresource(res);
                res=sem_aux.readTxt(read);
            }
        selectresource(res);
    res=&fdp;
    res=fdp_aux.readTxt(read);
        for (int j=0;j<num_fdp;j++)
        {
                    selectresource(res);
                    res=fdp_aux.readTxt(read);
                }
        selectresource(res);

    res=&cour;
    res=cour_aux.readTxt(read);
    for (int i=0;i<num_cour;i++){
                    selectresource(res);
                    res=cour_aux.readTxt(read);
               }
        selectresource(res);

    read.close();
}
Resource *List::ResourcesOnList(string _ID){
    Resource *aux;
    Nodo *get=actual;
    while (get!=NULL){
        aux=get->Getresource();
        if(aux->GetID()==_ID){
            return aux;
        }
        get=get->Getnext();
    }
    return NULL;
}
Resource *List::DeleteResource(string _ID){
    Nodo *get=actual;
    Nodo *aux=NULL;
    bool found=false;
    Resource *res;
    while(get!=NULL && !found){
        res=get->Getresource();
        if(res->GetID()==_ID){
            found=true;
            DeleteNodores(aux,get);
            return res;
        }
        aux=get;
        get=get->Getnext();
    }
    return NULL;
}
void List::DeleteNodores(Nodo *aux,Nodo *get){
    if (aux==NULL){//If the resource to delete is at the first node.
        actual=get->Getnext();
    }else{
        aux->setnext(get->Getnext());
    }
    delete get;
}
void List::InsertNodeSelPosition(Resource *res,int position){
    Nodo *get=actual;
    for(int i=0;i<position;i++){
        get=get->Getnext();
    }
     get->setnext(new Nodo(res,get->Getnext()));
}
