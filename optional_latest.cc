#include <iostream>
#include <string>
#include <vector>
using namespace std;
char cost[3][3];

string OptimalAssignments(string strArr[], int arrLength) {
  vector<int>row;
  vector<vector<int>>matrix;
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
        matrix.push_back(row);
      }
      else if(strArr[i][j] == ')'){
      
      }
      else if(isdigit(strArr[i][j])){
        row.push_back(strArr[i][j]-'0');
        if(x_index == 3){
          //cout<< "Zeroing x" << y_index  <<endl;
          x_index = 0;
          cout<< "x" << x_index << "y" << y_index <<endl;
          cout<< "i" << i << "j" << j <<endl;
          ++y_index;
          cost[y_index][x_index] = strArr[i][j];
        }
        else{
          cout<< "i" << i << "j" << j <<endl;
          cost[y_index][x_index] = strArr[i][j];
          
          ++x_index;
        }
        

        //cout<< "Index i" << i << "Index j" << j  <<endl;
        //cost[y_index][x_index] = strArr[i][j];
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
  int smallest = 0;
  
  vector<vector<int>>::iterator it;
  vector<int>::iterator jt;
  it = matrix.begin();
  while(it != matrix.end()){
    jt = (*it).begin();
    while(jt != (*it).end()){
       //cout<< "Matrix element" << *jt << endl;
      //if(jt != (*it).begin()){
        //smallest = *jt;
      //}
      
      if(smallest<*jt){
        smallest = *jt;
//        cout<< "Matrix element" << smallest << endl;
  }
//      else{  
  //    }
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
