#include <iostream>
#include <string>
using namespace std;

enum direction{LEFT,RIGHT};

string AlphabetRunEncryption(string str) {
  direction dir = RIGHT;
  // code goes here
  for(int i=0;i<str.size();++i){
    if(i<str.size()-1){
      if(str.at(i)<str.at(i+1)){
 
      } 
    }
    if(str.at(i) == 'R'){
      cout<< str.at(i) << endl;
      dir = RIGHT;
    }
    else if(str.at(i) == 'L'){
      cout<< str.at(i) << endl;
      dir = LEFT;
    }
    else if(str.at(i) == 'S'){
      cout<< str.at(i) << endl;
    }
    else if(str.at(i) == 'N'){
      cout<< str.at(i) << endl;
    }

  }  
  return str;

}

int main(void) { 
   
  // keep this function call here
  cout << AlphabetRunEncryption(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
