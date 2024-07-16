#include <iostream>
#include <string>
#include <vector>
using namespace std;

string VertexCovering(string strArr[], int arrLength) {
  
  // code goes here  
  bool left_par = false;
  bool right_par = false;
  bool is_dot = false;
  bool is_line = false;
  bool is_edge = false;
   
  char first_edge;
  char second_edge;

  vector<char>all_vertices;
  for(int i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    if(i == 1){
      for(int j = 0;j<strArr[i].size();++j){
        //if(strArr[i][j]){
//          cout<< strArr[i][j] << endl;
          if(strArr[i][j] == '('){
            left_par = true;
          }
          else if(strArr[i][j] == ')'){
            right_par = true;
          }
          else if(strArr[i][j] == ','){
            is_dot = true;
          }
          else if(strArr[i][j] == '-'){
            is_line = true;
          }
          else{
            is_edge = true;
            cout<< strArr[i][j] << endl;
            if(is_line){
              second_edge = strArr[i][j];
            }
            else if(left_par && not(is_line)){
              first_edge = strArr[i][j];
            }
          }
        }
      }
    //}
  }
  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << VertexCovering(A, arrLength);
  return 0;
    
}
