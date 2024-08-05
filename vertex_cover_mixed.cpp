#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <string.h>

using namespace std;

string VertexCovering(string strArr[], int arrLength) {
  
  // code goes here 

  vector<string>vertices;
  vector<string>vertex_cover;
  map<string,string>graph_elem;
  for(int i = 0;i<arrLength;++i){
    cout<< strArr[i] << endl;
    if(i == 0){
      string cleaned;
      for(int j = 0;j<strArr[i].size();++j){
        if(strArr[i][j] == '('){
          ;  
        }
        else if(strArr[i][j] == ','){
          ;
        }
        else if(strArr[i][j] == ')'){
          ;
        }
        else{
          cleaned+=strArr[i][j];
        }

      }
      vertices.push_back(cleaned);
    }
    if(i == 1){
      //cout<< "graph" << endl;
      string first_node;
      string second_node;
      bool left_par = false; //expression starts 
      bool expr_line = false; //if off, first char; if on, second 
      bool right_par = false; //expression ends
      for(int j = 0;j<strArr[i].size();++j){
        if(strArr[i][j] == '('){
          left_par = true;  
        }
        else if(isalpha(strArr[i][j]) and not(expr_line)){
          first_node+=strArr[i][j];
        }
        else if(isalpha(strArr[i][j]) and expr_line){
          second_node+=strArr[i][j];
          expr_line = false;
        }
        else if(strArr[i][j] == ','){
          ;
        }
        else if(strArr[i][j] == ')'){
          cout << first_node << "first" << endl;
          cout << second_node << "second" << endl;

          graph_elem.insert(make_pair(first_node,second_node));
          first_node = "";
          second_node = ""; 
          left_par = false;
          right_par = true;
        }
        else if(strArr[i][j] == '-'){
          expr_line = true;
        }
      
        else if(left_par == true and expr_line == false){
          //first_node+=strArr[i][j];
        }
        else if(left_par == true and expr_line == true){
          
          //second_node+=strArr[i][j];
        }
        else if(right_par == true or strArr[i][j] == ')'){
        graph_elem.insert(make_pair(first_node,second_node));
          first_node = "";
          second_node = "";
          //cleaned+=strArr[i][j];
        }

      }
      //graph.push_back(cleaned);
    }
    
    if(i == 2){
      //cout<< "cover" << endl;
      string cleaned;
      for(int j = 0;j<strArr[i].size();++j){
        if(strArr[i][j] == '('){
          ;  
        }
        else if(strArr[i][j] == ','){
          ;
        }
        else if(strArr[i][j] == ')'){
          ;
        }
        else{
          cleaned+=strArr[i][j];
        }

      }
      vertex_cover.push_back(cleaned);
    }
    
  }

  for(auto vt:vertices){
    cout<< "All vertices" << vt << endl;
  }
  for(auto vc:vertex_cover){
      cout<< "All vertex_cover " << vc << endl;
  }
  if(graph_elem.empty()){
  cout<<"emtpy "  <<endl;
  }
  for(auto g:graph_elem){
    cout<< "graph par" << g.first <<"child " << g.second <<endl;
    int i = 0;
    while(i<g.first.size()){
      //string key;
      //string key (g.first.at(i));
       char key_c = g.first.at(i);
       char* key_p = &key_c;

       char* key_g = (char*)malloc(2*sizeof(char));
       strcat(key_g,key_p);
       strcat(key_g+1,"\0");
       string key(key_g);
       cout<<"Transformed key" <<key << endl;
       //       string key = strivng(1, g_first.at(i));
      if(find(vertex_cover.begin(),vertex_cover.end(),key) != vertex_cover.end()){
      cout<< "FOUNDIN1 VERTEX SET" << endl;    
      }
      i++;
    }
    while(i<g.first.size()){   
 //     string key = g.second.at(i);
 //string key (g.second.at(i));
   string key;
         //     string key = string(1, g_first.at(i));
      //if(vertex_cover.begin(),vertex_cover.end(),key!= vertex_cover.end()){
        //cout<< "FOUNDIN2 VERTEX SET" << endl;
        //}
        ++i;
      }
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
