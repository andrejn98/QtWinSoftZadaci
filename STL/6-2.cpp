#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

class Proces{
   public:
      int id, prioritet;
      Proces(){};
      Proces(int id, int prioritet){this->id=id; this->prioritet=prioritet;};
};

bool operator<(const Proces& p1, const Proces& p2) // mora da se definira operator< za da moze sporedba na >2 elementi
{
   return p1.prioritet < p2.prioritet;
}

int main(){
   std::priority_queue<Proces> procesi;

   int id, prioritet,broj;
   cout<<"Vnesete broj na procesi: "; cin>>broj;
   while(broj!=0){
      cout<<"Vnesete id na proces i prioritet: "; cin>>id; cin>>prioritet;
      procesi.push(Proces(id, prioritet));
      --broj;
   }

   while(!procesi.empty()){
      Proces p = procesi.top();
      cout<<"Id: "<<p.id<<", prioritet: "<<p.prioritet<<endl;
      procesi.pop();
   }

   return 0;
}