#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Elem_coord{
  int x;
  int y;
};

vector<Elem_coord>Elem_coords;

string ConnectFourWinner(string strArr[], int arrLength) {
  string whose_turn;
  string game_positions;
  vector<string>game_board;
  Elem_coord elem_coord={0,0};
  // code goes here  
  for(int i=0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    if(i==0){
      whose_turn = strArr[i];
      cout<< whose_turn << endl;
    }
    else if(i>0){
      for(int j=0;j<strArr[i].size();++j){
      if(strArr[i][j] == 'R'){
        cout<< "whose turn" << "at place" <<j << "and" <<i << endl; 
        elem_coord = {i,j};
        Elem_coords.push_back(elem_coord);
      }
    }
      game_positions = strArr[i];
      game_board.push_back(game_positions);
      //cout<< game_positions << endl;
    }
  }
/*
  for(auto gt:game_board){
    for(int j=0;j<gt.size();++j){
      if(gt.at(j) == 'R'){
        cout<< "whose turn" << "at place" <<j << "and" <<gt << endl; 
      }
      else{}
    }
    cout<< "board is " <<gt << endl;
  }*/
  for(auto et:Elem_coords){
    cout<< "x" << et.x << "y"  << et.y << endl;
  }
  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ConnectFourWinner(A, arrLength);
  return 0;
    
}
