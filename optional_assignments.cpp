#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

string OptimalAssignments(string strArr[], int arrLength) {
  int old_value = 0;
  vector<int>row;
  vector<vector<int>>matrix;
  // code goes here  
  for(int i = 0;i<arrLength;++i){
    int value = 0;
    for(int j = 0;j<strArr[i].size();++j){
      if(strArr[i][j] == '('){
      }
      else if(strArr[i][j] == ','){
        //cout<< "Now pushed" << old_value  <<endl;
        matrix.push_back(row);
      }
      else if(strArr[i][j] == ')'){
      }
      else if(isdigit(strArr[i][j])){
        row.push_back(strArr[i][j]-'0');
        //old_value = strArr[i][j]-'0';
        //cout<< "Now caught" << old_value  <<endl;
      }
    }
  }
  vector<vector<int>>::iterator it;
  vector<int>::iterator jt;
  it = matrix.begin();
  jt = row.begin();
  while(it != matrix.end()){
    while(jt != (*it).end()){
      cout<< "Matrix element" << *jt << endl; 
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
  cout << OptimalAssignments(A, arrLength);
  return 0;
    
}
