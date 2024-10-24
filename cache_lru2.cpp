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
    if(queue.size() == 4){
      queue.pop_front();
    }
    deque<string>::iterator it = find(queue.begin(),queue.end(),strArr[i]);
    if(it != queue.end()){ //element is already in cache
      queue.erase(it); 
      queue.push_back(strArr[i]);
    }
    else{
      queue.push_back(strArr[i]);
    }
  }
  string cache;
  for(deque<string>::iterator qt = queue.begin();qt!=queue.end();++qt){
    cout<< *qt << endl;
    if(qt == queue.begin()){
      cache+=*qt;  
    }
    else if(qt != queue.begin() and not(qt == prev(queue.end()))){
      cache = "-"+cache;
      cache+=*qt;
    }
    //cache+=*qt;
  }

  return cache;
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  //LRUCache(A, arrLength);
  cout << LRUCache(A, arrLength);
  return 0;
    
}
