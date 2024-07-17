#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string VertexCovering(string strArr[], int arrLength) {
  
  // code goes here

  multimap<char,char>all_edges;
  multimap<char,char>missing_from_vertex_cover;
  
  vector<char>vertex_cover;

  bool left_par = false;
  bool right_par = false;
  bool is_dot = false;
  bool is_line = false;
  bool is_edge = false;
   
  char first_edge;
  char second_edge;
  char first_vertex;
  char second_vertex;

  vector<char>all_vertices;
  for(int i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    if(i == 1){
      for(int j = 0;j<strArr[i].size();++j){
        if(strArr[i][j] == '('){
          left_par = true;
        }
        else if(strArr[i][j] == ')'){
          right_par = true;
        }
        else if(strArr[i][j] == ','){
          is_dot = true;
        }
        else if(strArr[i][j] == '-'){
          is_line = true;
        }
        else{
          is_edge = true;
          cout<< strArr[i][j] << endl;
          if(is_line){
            second_edge = strArr[i][j];
            is_line = false;
            all_edges.insert(make_pair(first_edge,second_edge));
          }
          else if(left_par && not(is_line)){
            first_edge = strArr[i][j];
          }
        }
      }
    }
    if(i == 2){
      for(int j = 0;j<strArr[i].size();++j){
        if(strArr[i][j] == '('){
          left_par = true;
        }
        else if(strArr[i][j] == ')'){
          right_par = true;
        }
        else if(strArr[i][j] == ','){
          is_dot = true;
      }
        else if(strArr[i][j] == '-'){
          is_line = true;
        }
        else{
          is_edge = true;
          cout<< strArr[i][j] << endl;
          if(is_dot){
            second_vertex = strArr[i][j];
            is_dot = false;
            vertex_cover.insert(make_pair(first_vertex,second_vertex));
          }
          else if(left_par && not(is_line)){
            first_vertex = strArr[i][j];
          }
        }
      }
    }
  } 
  for(auto edges:all_edges){
    if(find(vertex_cover.begin(),vertex_cover.end(),edges.first) == vertex_cover.end() && find(vertex_cover.begin(),vertex_cover.end(),edges.first) == vertex_cover.end()){
      missing_from_vertex_cover.insert(make_pair(first_edge,second_edge));
      //cout<<"First vertex of edge" <<edges.first << endl;
      //cout<<"Second vertex of edge"<< edges.second << endl;
    }
    //cout<<"First vertex of edge" <<edges.first << endl;
    //cout<<"Second vertex of edge"<< edges.second << endl;
  }

for(auto missing:missing_from_vertex_cover){
    cout<<"First vertex of edge" << missing.first << endl;
    cout<<"Second vertex of edge"<< missing.second << endl;
  }

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << VertexCovering(A, arrLength);
  return 0;
    
}
