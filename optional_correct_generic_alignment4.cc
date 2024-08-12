#include <iostream>
#include <string>
#include <vector>
using namespace std;
char cost[3][3];

string OptimalAssignments(string strArr[], int arrLength) {
  vector<int>row;
  vector<vector<int>>matrix;
  int counter_x = 0;
  int y_index = 0;
  int x_index = 0;
  for(int i = 0;i<arrLength;++i){
    int value = 0;
    for(int j = 0;j<strArr[i].size();++j){
      if(strArr[i][j] == '('){
      
      }
      else if(strArr[i][j] == ','){
        matrix.push_back(row);
      }
      else if(strArr[i][j] == ')'){
      
      }
      else if(isdigit(strArr[i][j])){
        row.push_back(strArr[i][j]-'0');
        if(x_index == sizeof(strArr[i])){
          x_index = 0;
          ++y_index;
          cost[y_index][x_index] = strArr[i][j];
        }
        else{
          cost[y_index][x_index] = strArr[i][j];    
          ++x_index;
        }
      }
    }
  }
  int comp = 0;
  int subtractable = 0;
  vector<vector<int>>rows;
  vector<int>sub_row;
  for(int k = 0;k<3;++k){
    for(int l = 0;l<3;++l){
      if(k == 0){
        if(comp<cost[k][l] and comp == 0){
          comp = cost[k][l];
          subtractable = comp; 
          cout<< "Comparable0" << comp-'0'  <<endl;
        }
        cost[k][l]-=subtractable;
        sub_row.push_back(cost[k][l]);
      }
      else if(k == 1){
        if(l == 0){
          if(comp<cost[k][l]){
            //comp = cost[k][l];

            //cout<< "Comparable1" << comp-'0'  <<endl;
          }
          cost[k][l]-=subtractable;
          rows.push_back(sub_row);
          sub_row.clear();
        }
        sub_row.push_back(cost[k][l]);
      }
      else if(k == 2){
        if(l == 0){
          if(comp<cost[k][l]){
           comp = cost[k][l];
           //cout<< "Comparable2" << comp-'0'  <<endl;
          }
          cost[k][l]-=subtractable;
          rows.push_back(sub_row);
          sub_row.clear();
        }
        sub_row.push_back(cost[k][l]);
      }
    }
  }
  rows.push_back(sub_row);  
  vector<int>::iterator at;
  vector<vector<int>>::iterator rt;
  rt = rows.begin();
  while(rt != rows.end()){
    at = (*rt).begin();
    while(at != (*rt).end()){
      if(rt == rows.begin()){
        cout<< "Row element" << *at << endl;
        }
      else{
        cout<< "Row element" << *at-'0' << endl;
        }
      ++at;
    }  
    ++rt;
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
