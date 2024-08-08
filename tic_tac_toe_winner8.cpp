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
          //cout <<"All elem " <<*jt ;
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
          //cout <<"All elem " <<*jt ;
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
          //return ret_str;  
        }
    else{
      counter = -1;
      return_stream << counter;
      return_stream >> ret_str;
      //return ret_str;
    }

    ++it;
  }
  vector<string>columnwise1;
  vector<string>columnwise2;
  vector<string>columnwise3;
  vector<vector<string>>::iterator kt;
  vector<string>::iterator mt;
  kt=board.begin();
  while(kt!=board.end()){
    mt = (*kt).begin();
    while(mt!=(*kt).end()){
      cout<< "Rowwise" << *mt << endl;
      if(mt == (*kt).begin()){
        columnwise1.push_back(*mt);
      }
      else if(mt == (*kt).begin()+1){
        columnwise2.push_back(*mt);
      }
      else if(mt == (*kt).begin()+2){
        columnwise3.push_back(*mt);
      }
      ++mt;
    }
    ++kt;
  }
  for(auto co1:columnwise1){
    cout<< "col1wise" << co1 << endl;
  }
  for(auto co2:columnwise2){
    cout<< "col2wise" << co2 << endl;
  }
  for(auto co3:columnwise3){
    cout<< "col3wise" << co3 << endl;
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
