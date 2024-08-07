#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

string OptimalAssignments(string strArr[], int arrLength) {
  vector<int>row;
  vector<vector<int>>matrix;
  // code goes here  
  for(int i = 0;i<arrLength;++i){
    int value = 0;
    //cout<< strArr[i] << endl;
    for(int j = 0;j<strArr[i].size();++j){
      if(strArr[i][j] == '('){

      }
      else if(strArr[i][j] == ','){
      
      }
      else if(strArr[i][j] == ')'){
      
      }
      else if(isdigit(strArr[i][j])){
        //stringstream str_stream(strArr[i][j]);
        //str_stream >> value;
        //value=stoi(strArr[i][j],10); 

        cout<< "Char" << strArr[i][j]-'0' << endl;
        row.push_back(strArr[i][j]-'0');
      }
      
    }
    matrix.push_back(row);

  }

  vector<vector<int>>::iterator it;
  vector<int>::iterator jt;
  it = matrix.begin();
  while(it!=matrix.end()){
    jt = (*it).begin();
    while(jt!=(*it).end()){
      cout<< "Elem of matrix" << *jt << endl;
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
