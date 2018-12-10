#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
    SpeakerID="-";
    coordinator="-";
}
Seminar::~Seminar(){};

void Seminar::DisplayDate(){
    date->DisplayDate();
}
string Seminar::toString(){
    stringstream s;
    s<< "Name__________________"<<name<<endl;
    s<< "Status________________"<< status<<endl;
    s<< "ID____________________"<<ID<<endl;
    s<< "Speaker ID____________"<<SpeakerID<<endl;
    s<< "Coordinator ID________"<<coordinator<<endl;
    s<< "Maximum seats_________"<<maxSeats<<endl;
    return s.str();
}

string Seminar::toStringList(){
    stringstream s;
    s<<"Name------------------"<<name<<endl;
    s<<"Maximum seats----------"<<maxSeats<<endl;
    s<<"Speaker ID_____________"<<ID<<endl;
    s<<"List of students:"<<endl;
       for(int i=0; i<num_users; i++){
           s<<lirray[i]<<endl;
       };
    return s.str();
}
void Seminar::datasaving( ofstream &write){
   write<<coordinator<<"\n";
   write<<SpeakerID<<"\n";
   write<<maxSeats<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";
   write<<num_users<<"\n";
    for(int i=num_users-1;i>=0;i--){
        write<<lirray[i]<<"\n";
    };


}

Seminar *Seminar::readTxt(ifstream &read){
    string _name, _status,_ID,_SpeakerID,_coordinator;
    int _maxSeats,_num_users,i;
    read>>_coordinator;
    read>>_SpeakerID;
    read>>_maxSeats;
    read>>_ID;
    read>>_status;
    read>>_name;
    read>>_num_users;
    Seminar *s1=new Seminar(_name, _status,_ID,_num_users,_maxSeats,_SpeakerID,_coordinator);
            for(i=0;i<_num_users;i++){
                read>>s1->lirray[i];
            };
    return (s1);
}
void Seminar::ModifyResource(){
    cout<<"Please, enter the new name for the seminar: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new status for the seminar: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the seminar: ";
    cin>>ID;
    cout<<"\n";
    cout<<"Please, enter the new maximum number of seats for the seminar: ";
    cin>>maxSeats;
    cout<<"\n";
    cout<<"Please,enter the new Speaker ID: ";
    cin>>SpeakerID;
    cout<<"\n";
    cout<<"Please,enter the new Coordinator ID: ";
    cin>>coordinator;
    cout<<"\n";

}

void Seminar::searchinlist(string _id){

    int i=num_users-1;
    for(int k=0; k<=i;k++){
        if (lirray[k]==_id){
            cout<<name<<endl;
        }
    }
    if(SpeakerID==_id){
        cout<<name<<endl;
        cout<<ID<<endl;
    }
}

bool Seminar::checking(){
    if(num_users==maxSeats){//Hay que checkear con el numero máximo cry cry cry cry cry.TA READY YA CRACK A VER SI TIRA JODER
        cout<<"There are no free seats"<<endl;
        return false;
    }
    if(num_users<maxSeats){
        return true;
    }
}
