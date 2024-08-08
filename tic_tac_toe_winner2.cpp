#include <iostream>
#include <string>
#include <vector>
using namespace std;

string NoughtsDeterminer(string strArr[], int arrLength) {
  vector<string>row;
  vector<vector<string>>board;
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
  vector<vector<string>>::iterator it;
  vector<string>::iterator jt;
  it = board.begin();
  while(it!=board.end()){
    jt = (*it).begin();
    while(jt!=(*it).end()){
      cout << *jt ;
      ++jt;
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
