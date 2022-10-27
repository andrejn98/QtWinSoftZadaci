#ifndef DATE_H
#define DATE_H

class Datum {
    public:
        Datum();
        Datum(int , int , int);
        int getDen();
        int getMesec();
        int getGodina();
        void print();
    private:
        int den;
        int mesec; 
        int godina;
};

#endif
