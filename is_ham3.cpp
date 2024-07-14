#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string HamiltonianPath(string strArr[], int arrLength) {
  
  // code goes here  
  vector<char>vertices;
  map<char,char>edges;
  map<char,char>edges2;  
  char latest_char ='?';

  bool is_char = false;
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
          //block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          is_line = false;
          is_char = false;
        }
        else if(strArr[i][j] == '('){
          in_dot = false;
          block_begins = true;
          block_ends = false;
          left_par = true;
          right_par = false;
          is_line = false;
          is_char = false;
        }
        else if(strArr[i][j] == ')'){
          in_dot = false;
          block_begins = false;
          block_ends = true;
          left_par = false;
          right_par = true;
          is_line = false;
          is_char = false;
        }

        else{
//          cout<< strArr[i][j] << endl;
          in_dot = false;
          //block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          is_char = true;
          //latest_char = strArr[i][j];
          //vertices.push_back(strArr[i][j]);
          //edges.insert(make_pair(latest_char,strArr[i][j]));
                 }
        ++j;
      }
    }
    else if(i == 1){
      int j = 0;
      while(j<strArr[i].size()){
        //cout<< strArr[i][j] << endl;
        //latest_char = strArr[i][j];
        //cout<< "In i" << i<< " " <<" in j" << j << " " << latest_char << endl;
      if((not(isalpha(strArr[i][j])))){
          cout<< "Not alpha" << endl;
        if(strArr[i][j] == ','){
          in_dot = true;
          block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          is_char = false;
        }
        else if(strArr[i][j] == '('){
          in_dot = false;
          block_begins = true;
          block_ends = false;
          left_par = true;
          right_par = false;
          is_char = false;
        }
        else if(strArr[i][j] == ')'){
          in_dot = false;
          block_begins = false;
          block_ends = true;
          left_par = false;
          right_par = true;
          is_char = false;
        }
        else if(strArr[i][j] == '-'){
          in_dot = false;
          block_begins = false;
          block_ends = false;;
          left_par = false;
          right_par = false;
          is_line = true;
          is_char = false;
          
          //vertices.insert(make_pair(strArr[i][j],latest_char));
        }
      }
        else if(isalpha(strArr[i][j])){
          cout<< "Alpha" << endl;
          //cout<< strArr[i][j] << endl;
          in_dot = false;
          block_begins = false;
          block_ends = false;
          left_par = false;
          right_par = false;
          is_char = true;
          //if(latest_char == '?'){
            //latest_char = strArr[i][j];
          //}
          //latest_char = strArr[i][j];
          //if(edges2.find(latest_char) == edges2.end()){
            edges2.insert(make_pair(strArr[i][j],strArr[i][j]));
            vertices.push_back(strArr[i][j]); 
          //}
          //vertices.push_back(strArr[i][j]);
        }
        ++j;
      }
    }
  }

  
  for (auto vt:vertices){
    cout<< "VT"<< vt << endl;
  }
  /*for (auto mt:edges2){
    cout<<"Herefirst" <<" "<<mt.first << endl;
    cout<<"Theresec" <<" "<<mt.second << endl;
  }*/
  
  for (auto mt2:edges2){
    cout<<"m! second "<<edges2.size() <<mt2.first << endl;
    //cout<<"m!sec " <<" "<<mt2.second << endl;
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
