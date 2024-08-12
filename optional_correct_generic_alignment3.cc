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
        if(x_index == sizeof(strArr[i])){
          //cout<< "Zeroing x" << y_index  <<endl;
          x_index = 0;
          //cerr<< "x" << x_index << "y" << y_index <<endl;
          //cerr<< "ia " << i << "ja " << j <<endl;
          ++y_index;
          cost[y_index][x_index] = strArr[i][j];
        }
        else{
          //cerr<< "ib " << i << "jb " << j <<endl;
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
  int comp = 0;
  vector<vector<int>>rows;
  vector<int>sub_row;
  for(int k = 0;k<3;++k){
    for(int l = 0;l<3;++l){
      //cout<< "Now caught2" << cost[k][l]  <<endl;
      if(k == 0){
        if(comp<cost[k][l]){
          comp = cost[k][l];
          cout<< "Comparable0" << comp-'0'  <<endl;
        }
        sub_row.push_back(cost[k][l]);
      }
      else if(k == 1){
        if(l == 0){
          if(comp<cost[k][l]){
            comp = cost[k][l];
            cout<< "Comparable1" << comp-'0'  <<endl;
          }
          rows.push_back(sub_row);
          sub_row.clear();
        }
        sub_row.push_back(cost[k][l]);
      }
      else if(k == 2){
        if(l == 0){
          if(comp<cost[k][l]){
           comp = cost[k][l];
           cout<< "Comparable2" << comp-'0'  <<endl;
          }
          rows.push_back(sub_row);
          sub_row.clear();
        }
        sub_row.push_back(cost[k][l]);
      }
    }
  }
  rows.push_back(sub_row);  
  vector<int>::iterator at;
  //int smallest = 0;
  //while(at != sub_row.end()){
    //  cout<< "Matrix element" << *at << endl;
      //++at;
  //}
  vector<vector<int>>::iterator rt;
  rt = rows.begin();
  while(rt != rows.end()){
    at = (*rt).begin();
    while(at != (*rt).end()){
      cout<< "Row element" << *at-'0' << endl;
      ++at;
    }  
    ++rt;
  }
//  vector<vector<int>>::iterator it;
  //vector<int>::iterator jt;
  //it = matrix.begin();
  //while(it != matrix.end()){
    //jt = (*it).begin();
    //while(jt != (*it).end()){
       //cout<< "Matrix element" << *jt << endl;
      //if(jt != (*it).begin()){
        //smallest = *jt;
      //}
      
      //if(smallest<*jt){
        //smallest = *jt;
//        cout<< "Matrix element" << smallest << endl;
  //}
//      else{  
  //    }
     // ++jt;
    //}  
    //++it;
  //}

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << OptimalAssignments(A, arrLength);
  return 0;
    
}
