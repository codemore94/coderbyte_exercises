#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

struct Boolean{
  bool True=true;
  bool False=false;
};

string SimpleSAT(string str) {
  vector<bool>booleans;
  map<char,struct Boolean>propositions;
  Boolean boolean_values;
  
  for(int i=0;i<str.size();++i){
    if(str.at(i) == '('){

    }
    else if(str.at(i) == '&'){
      
    }
    else if(str.at(i) == '|'){
      
    }
    else if(str.at(i) == '~'){
      
    }
    else if(isalpha(str.at(i))){
      cout<< str.at(i) << endl;   
      propositions.insert(make_pair(str.at(i),boolean_values));
//      propositions.insert(make_pair(str.at(i),std::pair<bool,bool>{true,false})));
      //propositions.insert(make_pair(str.at(i),make_pair(true,false)));
    }
  }

  map<char,Boolean>::iterator it;
  it = propositions.begin();
  while(it!=propositions.end()){
    cout<< "Char" << it->first << endl;
    cout<< "values" << it->second.False << endl;
    ++it;
  }
  return str;

}

int main(void) { 
   
  // keep this function call here
  cout << SimpleSAT(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
