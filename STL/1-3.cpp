template<typename R, typename P>

P implicit_cast(const R& p) {

  return p;

}

// Problemot e vo toa shto prviot tip na toj nachin ne e specificiran odnosno
// toj e tipot shto treba da se vrati odkako ke se izvrshi funkcijata,
// taka kompajlerot nema da znae shto treba da se vrati

int main() {

  int i = 1;

  float x = implicit_cast<float>(i);

  int j = implicit_cast<int>(x);

 

} //kraj na main