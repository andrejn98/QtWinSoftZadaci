#ifndef COVEK_H
#define COVEK_H

using std::string;

class Covek {
    public:
        Covek();
        Covek(string, string ,string, int);
        string getIme();
        string getPrezime();
        string getAdresa();
        int getTelefon();
        void print();
    private:
        string ime;
        string prezime; 
        string adresa;
        int telefon;
};

#endif
