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
  vector<bool>booleans;
  map<char,struct Boolean>propositions;
  map<int,char>connectives;
  
  map<int,map<char,struct Boolean>>logics;
  
void evaluate(map<int,map<char,struct Boolean>>& log,map<int,char>&con){
  map<int,map<char,struct Boolean>>::iterator it;
  map<char,struct Boolean>::iterator jt;
  it=logics.begin();
  while(it!=logics.end()){
    jt = it->second.begin();
    //cout<< "Key" << it->first << endl;
    while(jt!=it->second.end()){
      std::tuple<bool,bool> tuple = std::tie(jt->second.False,jt->second.True);
      //cout<< "False" << jt->second.False << endl;
      //cout<< "True" << jt->second.True << endl;
      //cout<< "value" << jt->first << endl;
      ++jt;
    }  
    ++it;
  }

  map<int,char>::iterator kt;
  kt = connectives.begin();
  while(kt!=connectives.end()){
    cout<< "location " << kt->first << endl;
    cout<< "connective " << kt->second << endl;
    ++kt;
  }
}


string SimpleSAT(string str) {
  int counter = 0;
  Boolean boolean_values;
  
  for(int i=0;i<str.size();++i){
    if(str.at(i) == '('){

    }
    else if(str.at(i) == ')'){

    }
    else if(str.at(i) == '&'){
      //cout<< str.at(i) << endl;   
      connectives.insert(make_pair(counter,str.at(i)));
//      propositions.insert(make_pair(str.at(i),std::pair<bool,bool>{true,false})));
      //propositions.insert(make_pair(str.at(i),make_pair(true,false)));
    
      ++counter;
    }
    else if(str.at(i) == '|'){
      //cout<< str.at(i) << endl;   
      connectives.insert(make_pair(counter,str.at(i)));
//    connectives.insert(make_pair(str.at(i),boolean_values));
//      propositions.insert(make_pair(str.at(i),std::pair<bool,bool>{true,false})));
      //propositions.insert(make_pair(str.at(i),make_pair(true,false)));
    
      ++counter;
    }
    else if(str.at(i) == '~'){
      //cout<< str.at(i) << endl;   
      connectives.insert(make_pair(counter,str.at(i)));
//    connectives.insert(make_pair(str.at(i),boolean_values));
//      propositions.insert(make_pair(str.at(i),std::pair<bool,bool>{true,false})));
      //propositions.insert(make_pair(str.at(i),make_pair(true,false)));
    
    //logics.insert(make_pair(counter,connectives));
      ++counter;
    }
    else if(isalpha(str.at(i))){
      cout<< str.at(i) << endl;   
      propositions.insert(make_pair(str.at(i),boolean_values));
//      propositions.insert(make_pair(str.at(i),std::pair<bool,bool>{true,false})));
      //propositions.insert(make_pair(str.at(i),make_pair(true,false)));
    
      logics.insert(make_pair(counter,propositions));
      ++counter;
    }
  }

  map<char,Boolean>::iterator it;
  it = propositions.begin();
  while(it!=propositions.end()){
    //cout<< "Char" << it->first << endl;
    //cout<< "values" << it->second.False << endl;
    ++it;
  }

  evaluate(logics,connectives);



  return str;

}

int main(void) { 
   
  // keep this function call here
  cout << SimpleSAT(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
