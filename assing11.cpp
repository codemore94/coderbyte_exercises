#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <iterator>
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
  bool expression;
  bool next_expression;
  map<int,map<char,struct Boolean>>::iterator it;
  map<char,struct Boolean>::iterator jt;
  it=logics.begin();
  while(it!=logics.end()){
    jt = it->second.begin();
    //cout<< "Key" << it->first << endl;
    while(jt!=it->second.end()){
      std::tuple<bool,bool> tie_values = std::tie(jt->second.False,jt->second.True);
      //cout<< "False" << jt->second.False << endl;
      //cout<< "True" << jt->second.True << endl;
      cout<< "tuple"  << endl;
      
      ++jt;
    }  
    ++it;
  }

  map<int,char>::iterator kt;
  kt = connectives.begin();
  while(kt!=connectives.end()){
    cout<< "location " << kt->first << endl;
    cout<< "connective " << kt->second << endl;
    map<int,map<char,struct Boolean>>::iterator log_it=logics.find((kt->first)-1);
    expression = log_it->second.False;
    //log_it = std::advance(log_it,1);
    //next_expression = log_it->second.False;
    if(kt->second == '&'){
      expression = expression && next_expression; 
    }
    else if(kt->second == '|'){}
    else if(kt->second == '~'){}
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
      connectives.insert(make_pair(counter,str.at(i)));
      ++counter;
    }
    else if(str.at(i) == '|'){
      connectives.insert(make_pair(counter,str.at(i)));
      ++counter;
    }
    else if(str.at(i) == '~'){
      connectives.insert(make_pair(counter,str.at(i)));
      ++counter;
    }
    else if(isalpha(str.at(i))){
      cout<< str.at(i) << endl;   
      propositions.insert(make_pair(str.at(i),boolean_values));
      logics.insert(make_pair(counter,propositions));
      ++counter;
    }
  }

  map<char,Boolean>::iterator it;
  it = propositions.begin();
  while(it!=propositions.end()){
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
