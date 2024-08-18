#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <vector>

using namespace std;

string WeightedPath(string strArr[], int arrLength) {
  vector<char>nodes;
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
        if(isdigit(strArr[i][j])){
          prio.push(strArr[i][j]-'0');
        }
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
