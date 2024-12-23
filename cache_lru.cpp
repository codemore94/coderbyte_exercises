#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

string LRUCache(string strArr[], int arrLength) {
  // code goes here
  deque<string>queue;
  for(int i = 0;i<arrLength;++i){
    if(queue.size() == 5){
      queue.pop_front();
    }
    if(queue.find(queue.begin(),queue.end(),strArr[i]) != queue.end()){ //element is already in cache
      deque<string>::iterator it = queue.find(queue.begin(),queue.end(),strArr[i]);
      queue.erase(it); 
      queue.push_back(strArr[i]);
    }
    else{
      queue.push_back(strArr[i]);
    }
  }
  return strArr[0];
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << LRUCache(A, arrLength);
  return 0;
    
}
