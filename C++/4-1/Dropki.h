#ifndef DROPKI_H
#define DROPKI_H

class Dropki {
   public:
      Dropki();
      Dropki(int , int);
      void sobiranje(Dropki dropka);
      void odzemanje(Dropki dropka);
      void mnozhenje(Dropki dropka);
      void delenje(Dropki dropka);
      void pechatenjeVoString();
      void pechatenjeVoDouble();
      int getBroitel();
      int getImenitel();
   private:
      int broitel, imenitel;
};

#endif