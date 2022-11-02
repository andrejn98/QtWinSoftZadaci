#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;
using std::string;
using std::endl;

vector<string> v;

void najdiZborovi(string s){
  size_t pos = 0;
  string token;
  while((pos = s.find(" ")) != string::npos) {
      token = s.substr(0, pos);
      if(token.length()<10)
        v.push_back(token);
      s.erase(0, pos + 1);
  }
  if(s.length()<10)
    v.push_back(s);
}

int main() {

  ofstream zapisiEden("eden.txt");
  zapisiEden<<"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis non nisi et metus consectetur faucibus. Pellentesque dictum enim ante, a auctor dui vehicula in. Nunc rutrum nisl mi, eget malesuada libero dapibus at. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Suspendisse rutrum elit ut neque vulputate dapibus. Aliquam laoreet neque quis ipsum pulvinar consequat. Aenean ornare lorem nec risus placerat semper. Curabitur magna purus, convallis in egestas et, iaculis quis neque. Etiam eu quam nec tellus feugiat ultrices vitae in nulla. Suspendisse mollis viverra elit. Aenean eget malesuada velit, in luctus nulla. Maecenas fringilla venenatis porttitor. Donec ut congue nibh, eget tempor dui. Aliquam sit amet nulla iaculis metus euismod viverra vitae sit amet felis. Vivamus viverra tristique urna, vitae sollicitudin arcu consectetur elementum. Vestibulum non risus sit amet ligula finibus efficitur eu in nibh. Nunc eget dolor at quam egestas ornare nec sed ante. Fusce rhoncus mauris vitae arcu volutpat sodales. Morbi id neque nisi.";
  zapisiEden.close();

  string tekst;
  ifstream citajEden("eden.txt");

  while(getline(citajEden, tekst)){
    najdiZborovi(tekst);
  }
  citajEden.close();

  ofstream zapisiDrug("drug.txt");
  for(string x : v){
    zapisiDrug<<x + " ";
  }
  zapisiDrug.close();
}