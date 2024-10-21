#include <iostream>
#include <string>
using namespace std;

template<typename T>
T AlphabetRunEncryption(T str) {
  
  // code goes here
    
  return str;

}

int main(void) { 
   
  // keep this function call here
  auto a=AlphabetRunEncryption(0);
  auto b=AlphabetRunEncryption(nullptr);
  auto c=AlphabetRunEncryption(1.3);
  cout<< a << endl;
  cout<< b << endl;
  cout<< c << endl;
  // cout << AlphabetRunEncryption(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
