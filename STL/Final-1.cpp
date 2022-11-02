#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T> class Pole {        
    public:
        T array[5];
        int size;
        Pole(){}
        Pole(T v1, T v2, T v3, T v4, T v5){ 
            array[0] = v1;
            array[1] = v2;
            array[2] = v3;
            array[3] = v4;
            array[4] = v5;
        };
        void print(){
            for(int i=0;i<5;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
};

template <typename T> T max(Pole<T> *t){
	T temp_max = t->array[0];
	for (int i = 0; i < 5; i++)
	{
		if (temp_max < t->array[i])
		{
			temp_max = t->array[i];
		}
	}
    return temp_max;
}


int main()
{
    Pole<int> pInt(4, 6, 2, 8, 1);
    Pole<char> pChar('j', 'e', 'z', 'b', 'g');
    Pole<string> pString("fqcwe", "qiwue", "biquw", "hriue", "asvui");
    
    pInt.print();
    pChar.print();
    pString.print();

    cout<<endl<<"Najgolem int: "<<max(&pInt)<<endl;
    cout<<"Najgolem char: "<<max(&pChar)<<endl;
    cout<<"Najgolem string: "<<max(&pString)<<endl;

    return 0;
}