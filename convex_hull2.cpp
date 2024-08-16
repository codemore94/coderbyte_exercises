#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

struct Coord{
  int x_coord;
  int y_coord;
};

string ConvexHullPoints(string strArr[], int arrLength) {
  bool x_begins = false;
  Coord coord = {0,0};
  vector<Coord>coordinates;
  // code goes here 
  for(int i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    for(int j = 0;j<strArr[i].size();++j){
      
      if(strArr[i][j] == '('){
        x_begins = true;
        //x coordinate  begins;
      }
      else if(strArr[i][j] == ')'){
        coordinates.push_back(coord);
      }
      else if(strArr[i][j] == ','){
        x_begins = false;
        //y coordinate  begins;
      }
      else if(isdigit(strArr[i][j])){
        if(x_begins){
          coord.x_coord = strArr[i][j]-'0';
        }
        if(!x_begins){
          coord.y_coord = strArr[i][j]-'0';
        }
      }
    } 
  } 

  for(auto xt:coordinates){
    cout<< "X-coord" << xt.x_coord << endl;
    cout<< "Y-coord" << xt.y_coord << endl;
  }

  

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ConvexHullPoints(A, arrLength);
  return 0;
    
}
