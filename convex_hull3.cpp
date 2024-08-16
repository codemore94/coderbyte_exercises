#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
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
  vector<int>sortable_x;
  vector<int>sortable_y;
  
  for(auto ct:coordinates){
    //cout<< "X-coord" << ct.x_coord << endl;
    sortable_x.push_back(ct.x_coord);
//    cout<< "Y-coord" << ct.y_coord << endl;
    sortable_y.push_back(ct.y_coord);
  }

  sort(sortable_x.begin(),sortable_x.end());
  sort(sortable_y.begin(),sortable_y.end());

  for(auto xt:sortable_x){
    //cout<< "X-coord" << xt << endl;
  }
  for(auto yt:sortable_y){
    //cout<< "Y-coord" << yt << endl;
  }

  int x_min = sortable_x.at(0);
  int y_min = sortable_y.at(0);
  int x_max = sortable_x.at(sortable_x.size()-1);
  int y_max = sortable_y.at(sortable_y.size()-1);
      cout<< "minx" << x_min << endl;
      cout<< "miny" << y_min << endl;
      cout<< "maxx" << x_max << endl;
      cout<< "maxy" << y_max << endl;
  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ConvexHullPoints(A, arrLength);
  return 0;
    
}
