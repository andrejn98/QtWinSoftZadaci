#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Znak{
    private:
        char znak;
        bool pogoden;
    public:
        Znak(){}
        Znak(char znak, bool pogoden){
            this->znak = znak;
            this->pogoden = pogoden;
        }
        char getZnak(){return znak;}
        void setPogoden(){this->pogoden=true;}
        bool getPogoden(){return pogoden;}
};

int main() {
    vector<char> zbor = {'b', 'e', 's', 'i', 'l', 'k', 'a'};
    
    vector<Znak> znak;
    for(auto x : zbor){
        znak.push_back({x, 0});
    }
    
    char bukva;
    bool pogoden=false;

    for(int brojac=zbor.size()+1; brojac>=0; --brojac){
        pogoden = std::all_of(znak.begin(), znak.end(), [](Znak z) { return z.getPogoden(); });

        if(brojac==0 && !pogoden){
            break;
        }

        if(!pogoden){
            cout<<"Vnesete znak za pogoduvanje (imate uste "<<brojac<<" pogoduvanje/a):"<<endl;
            for(auto &x : znak){
                if(x.getPogoden())
                    cout<<x.getZnak();
                else
                    cout<<"-";
            }
            cout<<endl; cin>>bukva;
            for(auto &x : znak){
                if(x.getZnak()==bukva)
                    x.setPogoden();
            }
        }else{
            cout<<"Go pogodivte ";
            break;
        }
    }

    cout<<"baraniot zbor: ";
    for(auto x : znak){
        cout<<x.getZnak();
    }
    return 0;
}