#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string WeightedPath(string strArr[], int arrLength) {
  int heap_val = 0;
  char number_of_vertices = 0;
  vector<char>nodes;
  bool pipe_on = false;
  char prev_ch;
  char tmp_ch;
  string prev_str;
  string tmp_str;
  map<int,char>prio_map;
  for(int i =0;i<arrLength;++i){
    if(strArr[i].size() == 1){
      //cout << strArr[i] << endl;
      if(isalpha(strArr[i][0])){
        nodes.push_back(strArr[i][0]);
      }
      else if(isdigit(strArr[i][0])){
        number_of_vertices = strArr[i][0];
      }
    }
    else{
      for(int j =0;j<strArr[i].size();++j){
        cout << strArr[i][j] << endl;
        if(strArr[i][j] == '|'){
          pipe_on = true;
        }
        if(isdigit(strArr[i][j])){
          if(pipe_on){
            prev_ch = strArr[i][j];
            prev_str = string(prev_ch,1);
            pipe_on = false;
          }
          else{
            tmp_ch = strArr[i][j];
            tmp_str = string(tmp_ch,1);
            prev_str = tmp_str+prev_str;
          }
        }
        else if(isalpha(strArr[i][j])){
          char from_vertex = strArr[i][j];
        }
        //stringstream prev_stream;
        //prev_stream << prev_str;
        //cout<< "debug prev_str" << prev_str << endl;
        //prev_stream >> heap_val;
      }
    }
  }

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << WeightedPath(A, arrLength);
  return 0;
    
}
