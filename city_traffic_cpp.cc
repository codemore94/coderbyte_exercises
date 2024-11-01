#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string CityTraffic(string strArr[], int arrLength) {
  bool neighbours_on = false;
  map<char,vector<char>> neighmap;
  vector<char>neighbours;
  char node=0;
  // code goes here  
  for(int i=0;i<arrLength;++i){
    for(int j=0;j<strArr[i].size();++j){
      if(!neighbours_on && isdigit(strArr[i].at(j))){
        node = strArr[i].at(j);
      }
      if(strArr[i].at(j) == ':'){
        neighbours_on = true;
      }
      if(strArr[i].at(j) == ']'){
        neighbours_on = false;
        neighmap.insert(make_pair(node,neighbours));
      }
      if(neighbours_on && isdigit(strArr[i].at(j))){
        neighbours.push_back(strArr[i].at(j));
      }
    }  
  }

  for(auto nt:neighbours){
    cout<< "nt " << nt << endl;
  }
  for(auto ni:neighmap){
    cout<< "ni key" << ni.first << endl;
    for(auto vi:ni.second){
      cout<< "ni val" << vi << endl;
    }
  }

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << CityTraffic(A, arrLength);
  return 0;
    
}
