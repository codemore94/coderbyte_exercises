#include <iostream>
#include <string>
using namespace std;
char cost[3][3];

string OptimalAssignments(string strArr[], int arrLength) {
  
  // code goes here  
  int counter_x = 0;
  int y_index = 0;
  int x_index = 0;
  for(int i = 0;i<arrLength;++i){
    int value = 0;
    for(int j = 0;j<strArr[i].size();++j){
      if(strArr[i][j] == '('){
      
      }
      else if(strArr[i][j] == ','){
        //cout<< "Now pushed" << old_value  <<endl;
        //matrix.push_back(row);
      }
      else if(strArr[i][j] == ')'){
      
      }
      else if(isdigit(strArr[i][j])){
        //row.push_back(strArr[i][j]-'0');
        if(counter_x%3 == 0){
          ++y_index;
        }
        else{
          ++x_index;
        }
        cost[y_index][x_index] = strArr[i][j];
        ++counter_x;
        //old_value = strArr[i][j]-'0';
        //cout<< "Now caught1" << cost[i][j]  <<endl;
      }
    }
  }

  for(int k = 0;k<3;++k){
    for(int l = 0;l<3;++l){
      cout<< "Now caught2" << cost[k][l]  <<endl;
    }
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
