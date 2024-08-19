#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;

string WeightedPath(string strArr[], int arrLength) {
  int heap_val = 0;
  vector<char>nodes;
  bool pipe_on = false;
  char prev_ch;
  char tmp_ch;
  string prev_str;
  string tmp_str;
  priority_queue<int>prio; //possible heap-based priority for Dijkstra
  // code goes here  
  for(int i =0;i<arrLength;++i){
    if(strArr[i].size() == 1){
      //cout << strArr[i] << endl;
      if(isalpha(strArr[i][0])){
        nodes.push_back(strArr[i][0]);
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
            cout<< "debug0 prev_str" << prev_ch << endl;
            prev_str = string(prev_ch,1);
            cout<< "debug1 prev_str" << prev_str << endl;
            pipe_on = false;
          }
          else{
            tmp_ch = strArr[i][j];
            cout<< "debug4 prev_str" << tmp_ch << endl;
            tmp_str = string(tmp_ch,1);
            cout<< "debug5 prev_str" << tmp_str << endl;
            prev_str = tmp_str+prev_str;
          }
        }
        stringstream prev_stream;
        prev_stream << prev_str;
        cout<< "debug2 prev_str" << prev_str << endl;
        prev_stream >> heap_val;

        prio.push(-heap_val);
      }
    }
  }

  for(auto nt:nodes){
    cout<<"nodes " << nt << endl;
  }
  while(!prio.empty()){
    auto val = prio.top();
    prio.pop();
    cout<< "val" << val << endl;
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
