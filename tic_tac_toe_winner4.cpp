#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string NoughtsDeterminer(string strArr[], int arrLength) {
  vector<string>row;
  vector<vector<string>>board;
  int counter = 0;
  stringstream return_stream;
  string ret_str;
  bool all_other_equal = true;
  vector<vector<string>>::iterator it;
  vector<string>::iterator jt;

  // code goes here  
  int i = 0;
  for(i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    if(strArr[i] == "<>"){
      //cout<< "is <>" << endl;
      board.push_back(row);
      row.clear();
      //board.push_back(strArr[i]);

    }
    else if(strArr[i] == "-"){
      //cout<< "is -" << endl;
      row.push_back(strArr[i]);
    }
    else if(strArr[i] == "X"){
      //cout<< "is x" << endl;
      row.push_back(strArr[i]);
    }
    else if(strArr[i] == "O"){
      //cout<< "is o" << endl;
      row.push_back(strArr[i]);
    }
  }
  if(i == arrLength){
      board.push_back(row);
      row.clear();
  }
    it = board.begin();
  while(it!=board.end()){
    jt = (*it).begin();
    while(jt!=(*it).end()){
      ++counter;
      if(jt!=prev((*it).end(),1)){
        if(*jt == "X" and *(jt+1) == "X"){
          cout <<"All elem " <<*jt ;
        //all_other_equal = not(all_other_equal);
        //are all other chars similar in the row
        //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
        //}
        }
        else{
          all_other_equal = false;
        }
      }
      else if(jt!=prev((*it).end(),1)){
        if(*jt == "O" and *(jt+1) == "O"){
          cout <<"All elem " <<*jt ;
        //all_other_equal = not(all_other_equal);
        //are all other chars similar in the row
        //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
        //}
        }
        else{
          all_other_equal = false;
        }
      }
      ++jt;
    }
    if(all_other_equal){
          return_stream << counter;
          return_stream >> ret_str;
          return ret_str;  
        }


    ++it;
  }

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << NoughtsDeterminer(A, arrLength);
  return 0;
    
}
