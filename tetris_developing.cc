#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;


bool if_filled(){
  return false;
}

int board[10][12];

enum ROTATE{UP,DOWN,RIGHT,LEFT};

string TetrisMove(string strArr[], int arrLength) {
  enum ROTATE rot;
  stringstream change_to_number;
  int num = 0;
  // code goes here  
  for(int i=0;i<arrLength;++i){
    for(int j=0;j<strArr[i].size();++j){
      if(isalpha(strArr[i].at(j)) && isupper(strArr[i].at(j))){
        if(strArr[i].at(j) == 'I'){
          int lenI = 4;
          if(rot==UP){
            int local_col_heigth = 4;
            int local_row_width = 1;
          }
          else if(rot==DOWN){
            int local_col_heigth = 4;
            int local_row_width = 1;
          }
          else if(rot==RIGHT){
            int local_col_heigth = 1;
            int local_row_width = 4;
          }
          else if(rot==LEFT){
            int local_col_heigth = 1;
            int local_row_width = 4;
          }
         // board[][];
          break;
        }
        else if(strArr[i].at(j) == 'J'){
          break;
        }
        else if(strArr[i].at(j) == 'L'){
          break;
        }
        else if(strArr[i].at(j) == 'O'){
          break;
        }
        else if(strArr[i].at(j) == 'S'){
          break;
        }
        else if(strArr[i].at(j) == 'T'){
          break;
        }
        else if(strArr[i].at(j) == 'Z'){
          break;
        }
      }
      else if(isdigit(strArr[i].at(j))){
        change_to_number << strArr[i].at(j);
        change_to_number >> num;
        for(int row=num-1;row>=0;--row){
          cerr << "num" << num << endl;
          board[i-1][num-row] = 1;
        }
      }
    }
  }

  for(int j=0;j<10;++j){
    for(int i=0;i<12;++i){
      cout<< "elem " << board[i][j] << endl;
    }
  }

  return strArr[0];
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << TetrisMove(A, arrLength);
  return 0;
    
}
