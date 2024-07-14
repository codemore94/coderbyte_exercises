#include <iostream>
#include <string>
#include <vector>
using namespace std;

string HamiltonianPath(string strArr[], int arrLength) {
  
  // code goes here  
  vector<char>vertices;
  
  bool in_dot = false;
  bool block_begins = false;
  bool block_ends = false;
  bool left_par = false;
  bool right_par = false;
  bool is_line = false;
  
  for(int i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    if(i == 0){
      int j = 0;
      while(j<strArr[i].size()){
        //cout<< strArr[i][j] << endl;
        if(strArr[i][j] == ','){
          in_dot = true;
          block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          is_line = false;
        }
        else if(strArr[i][j] == '('){
          in_dot = false;
          block_begins = true;
          block_ends = false;
          left_par = true;
          right_par = false;
          is_line = false;
        }
        else if(strArr[i][j] == ')'){
          in_dot = false;
          block_begins = false;
          block_ends = true;
          left_par = false;
          right_par = true;
          is_line = false;
        }

        else{
//          cout<< strArr[i][j] << endl;
          in_dot = false;
          block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          vertices.push_back(strArr[i][j]);
        }
        ++j;
      }
    }
    else if(i == 1){
      int j = 0;
      while(j<strArr[i].size()){
        //cout<< strArr[i][j] << endl;
        if(strArr[i][j] == ','){
          in_dot = true;
          block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
        }
        else if(strArr[i][j] == '('){
          in_dot = false;
          block_begins = true;
          block_ends = false;
          left_par = true;
          right_par = false;
        }
        else if(strArr[i][j] == ')'){
          in_dot = false;
          block_begins = false;
          block_ends = true;
          left_par = false;
          right_par = true;
        }
        else if(strArr[i][j] == '-'){
          in_dot = false;
          block_begins = false;
          block_ends = false;;
          left_par = false;
          right_par = false;
          is_line = true;
        }

        else{
          cout<< strArr[i][j] << endl;
          in_dot = false;
          block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          vertices.push_back(strArr[i][j]);
        }
        ++j;
      }
    }
  }

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << HamiltonianPath(A, arrLength);
  return 0;
    
}
