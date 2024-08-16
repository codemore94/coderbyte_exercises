#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ConvexHullPoints(string strArr[], int arrLength) {
  
  // code goes here 
  for(int i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    for(int j = 0;j<strArr[i].size();++j){
      
      if(strArr[i][j] == '('){

      }
      else if(strArr[i][j] == ')'){

      }
      else if(strArr[i][j] == ','){

      }
      else if(isdigit(strArr[i][j])){
        cout<< strArr[i][j] << endl;
      }
    } 
  } 
  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ConvexHullPoints(A, arrLength);
  return 0;
    
}
