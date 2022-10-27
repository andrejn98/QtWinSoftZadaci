#include <iostream>
#include <cstring>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

class vraboten{
    protected:
        char *ime ,*prezime;
        int godina_na_vrabotuvanje;
    public:
        vraboten();
        vraboten(char*, char*, int);
        vraboten postavi();
        void prikazi_podatoci();
};

vraboten::vraboten(){}

vraboten::vraboten(char *ime, char *prezime, int godina){
    this->ime = new char[strlen(ime)+1];
    strcpy(this->ime, ime);
    this->prezime = new char[strlen(prezime)+1];
    strcpy(this->prezime, prezime);
    godina_na_vrabotuvanje=godina;
}

vraboten vraboten::postavi(){
    char ime[20], prezime[20]; 
    int godina;
    cout<<"Vnesi ime: " <<endl; cin>>ime;
    cout<<"Vnesi prezime: " <<endl; cin>>prezime;
    cout<<"Vnesi godina na vrabotuvanje: " <<endl; cin>>godina;
    return vraboten(ime, prezime, godina);
}

void vraboten::prikazi_podatoci(){
    cout<< ime <<" "<< prezime<< " godina na vrabotuvanje: "<< godina_na_vrabotuvanje <<endl;
}

class profesor : vraboten{
    private:
        char *oblast;
        int br_predmeti;
        char *zvanje;
    public:
        profesor();
        profesor(char*, char*, int, char*, char*, int);
        profesor postavi();
        void prikazi_podatoci();
};

profesor::profesor(){}

profesor::profesor(char *zvanje, char *oblast, int predmeti, char *ime, char *prezime, int godina) 
: vraboten(ime, prezime, godina){
    this->zvanje = new char[strlen(zvanje)+1];
    strcpy(this->zvanje, zvanje);
    this->oblast = new char[strlen(oblast)+1];
    strcpy(this->oblast, oblast);
    br_predmeti=predmeti;
}

profesor profesor::postavi(){
    char zvanje[20], oblast[20], ime[20], prezime[20]; 
    int br_predmeti, godina;
    cout<<"Vnesi ime: " <<endl; cin>>ime;
    cout<<"Vnesi prezime: " <<endl; cin>>prezime;
    cout<<"Vnesi zvanje: " <<endl; cin>>zvanje;
    cout<<"Vnesi oblast: " <<endl; cin>>oblast;
    cout<<"Vnesi broj na predmeti: " <<endl; cin>>br_predmeti;
    cout<<"Vnesi godina na vrabotuvanje: " <<endl; cin>>godina;
    return profesor(zvanje, oblast, br_predmeti, ime, prezime, godina);
}

void profesor::prikazi_podatoci(){
    cout<< ime <<" "<< prezime << ", godina na vrabotuvanje: " << godina_na_vrabotuvanje;
    cout<<", zvanje: "<< zvanje << ", oblast: " << oblast << ", broj na predmeti: " << br_predmeti << endl;
}

class asistent : vraboten{
    private:
        char *zvanje, *mentor;
        int br_predmeti;
    public:
        asistent();
        asistent(char*, char*, int, char*, char*, int);
        asistent postavi();
        void prikazi_podatoci();
};

asistent::asistent(){}

asistent::asistent(char *zvanje, char *mentor, int predmeti, char *ime, char *prezime, int godina) 
: vraboten(ime, prezime, godina){
    this->zvanje = new char[strlen(zvanje)+1];
    strcpy(this->zvanje, zvanje);
    this->mentor = new char[strlen(mentor)+1];
    strcpy(this->mentor, mentor);
    br_predmeti=predmeti;
}

asistent asistent::postavi(){
    char zvanje[20], mentor[20], ime[20], prezime[20]; 
    int br_predmeti, godina;
    cout<<"Vnesi ime: " <<endl; cin>>ime;
    cout<<"Vnesi prezime: " <<endl; cin>>prezime;
    cout<<"Vnesi zvanje: " <<endl; cin>>zvanje;
    cout<<"Vnesi mentor: " <<endl; cin>>mentor;
    cout<<"Vnesi broj na predmeti: " <<endl; cin>>br_predmeti;
    cout<<"Vnesi godina na vrabotuvanje: " <<endl; cin>>godina;
    return asistent(zvanje, mentor, br_predmeti, ime, prezime, godina);
}

void asistent::prikazi_podatoci(){
    cout<< ime <<" "<< prezime << ", godina na vrabotuvanje: " << godina_na_vrabotuvanje;
    cout<<", zvanje: "<< zvanje << ", mentor: " << mentor << ", broj na predmeti: " << br_predmeti << endl;
}

class demonstrator : vraboten{
    private:
        int rabotno_vreme_od, rabotno_vreme_do;
    public:
        demonstrator();
        demonstrator(int, int, char*, char*, int);
        demonstrator postavi();
        void prikazi_podatoci();
};

demonstrator::demonstrator(){}

demonstrator::demonstrator(int rab_vreme_od, int rab_vreme_do, char *ime, char *prezime, int godina) 
: vraboten(ime, prezime, godina){
    rabotno_vreme_od=rab_vreme_od;
    rabotno_vreme_do=rab_vreme_do;
}

demonstrator demonstrator::postavi(){
    char ime[20], prezime[20];
    int rabotno_vreme_od, rabotno_vreme_do, godina;
    cout<<"Vnesi ime: " <<endl; cin>>ime;
    cout<<"Vnesi prezime: " <<endl; cin>>prezime;
    cout<<"Vnesi godina na vrabotuvanje: " <<endl; cin>>godina;
    cout<<"Vnesi rabotno vreme od(1-24): " <<endl; cin>>rabotno_vreme_od;
    cout<<"Vnesi rabotno vreme do(1-24): " <<endl; cin>>rabotno_vreme_do;
    return demonstrator(rabotno_vreme_od, rabotno_vreme_do, ime, prezime, godina);
}

void demonstrator::prikazi_podatoci(){
    cout<< ime <<" "<< prezime << ", godina na vrabotuvanje: " << godina_na_vrabotuvanje;
    cout<<", rabotno vreme: "<< rabotno_vreme_od << "-" << rabotno_vreme_do <<endl;
}

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Vnesuvanje nov vraboten.\n"
        "2 Prikaz na lista.\n"
        "3 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}

int instructions1()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Profesor.\n"
        "2 Asistent.\n"
        "3 Demonstrator.\n"
        "4 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}

int main(){
    
    int choice;
    list<profesor> profesori;
    list<asistent> asistenti;
    list<demonstrator> demonstratori;
    
    while((choice = instructions()) != 3) { 
        vraboten v;
        profesor p;
        asistent a;
        demonstrator d;
        double ima = false;
        int choice1;
        char zvanje[20], oblast[20], ime[20], prezime[20]; 
        int br_predmeti, godina;
        
        switch(choice){ 
            
            case 1:
                while((choice1 = instructions1()) != 4){
                    switch (choice1)
                    {
                    case 1:
                        p = p.postavi();
                        profesori.push_front(p);
                        break;
                    case 2:
                        a = a.postavi();
                        asistenti.push_front(a);
                        break;
                    case 3:
                        d = d.postavi();
                        demonstratori.push_front(d);
                        break;
                    default:
                        cout<<"Greshen izbor\n";
                        break;
                    }
                }
                break;
            case 2:
                for(auto i=profesori.begin(); i!=profesori.end(); ++i){
                    ima = true;
                    i->prikazi_podatoci();
                }
                for(auto i=asistenti.begin(); i!=asistenti.end(); ++i){
                    ima = true;
                    i->prikazi_podatoci();
                }
                for(auto i=demonstratori.begin(); i!=demonstratori.end(); ++i){
                    ima = true;
                    i->prikazi_podatoci();
                }
                if(!ima){
                    cout<<"Nema vneseno vraboteni!"<<endl;
                }
                break;
            default:
                cout<<"Greshen izbor\n";
                break;
        }
    }

    return 0;
}