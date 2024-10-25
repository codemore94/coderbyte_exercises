#include <iostream>
#include <string>
using namespace std;

enum direction{LEFT,RIGHT};
enum up_or_down{DOWN,UP};
enum repeat{N_rep,S_rep};

string AlphabetRunEncryption(string str) {
  direction dir = RIGHT;
  up_or_down up_down = DOWN;
  repeat rep= N_rep;
  // code goes here
  for(int i=0;i<str.size();++i){
    if(i<str.size()-1){
      if(str.at(i)<str.at(i+1)){
        up_down = UP;
      }
      else if(str.at(i)>str.at(i+1)){
        up_down = DOWN;
      } 
    }
    if(str.at(i) == 'R'){
      cout<< str.at(i) << endl;
      dir = RIGHT;
    }
    else if(str.at(i) == 'L'){
      cout<< str.at(i) << endl;
      dir = LEFT;
    }
    else if(str.at(i) == 'S'){
      cout<< str.at(i) << endl;
      rep = S_rep;
    }
    else if(str.at(i) == 'N'){
      cout<< str.at(i) << endl;
      rep = N_rep;
    }
  }  
  char begin_ch = '!';
  char end_ch = '!';
  bool found_flag = false;
  if(rep == S_rep or up_down == UP){
      for(int ascii = 97;ascii<=122;++ascii){
        if((char)ascii == str.at(0)){
          //cout<<"Firstbeg" <<(char)ascii  << endl;
          if(ascii >97){
            begin_ch = (char)(ascii-1);
          }
          //found_flag = true;
        }
        //if(str.at(str.size()-1) == (char)ascii){
          //cout<<"end" <<(char)ascii  << endl;
          //cout<<"end" << str.at(str.size()-1)  << endl;
          if((char)ascii == str.at(str.size()-2)){
            end_ch = (char)(ascii+1);
          }
          
        //}
      }
    
}/*
else if(rep == S_rep or up_down == DOWN){
      int ind =0;
      for(int ascii = 97;ascii<=122;++ascii){
        if((char)ascii == str.at(ind) && !found_flag){
          cout<<"Firstbeg" <<(char)ascii  << endl;
          begin_ch = (char)(ascii-1);
          found_flag = true;
        }
        if(str.at(str.size()-1) == (char)ascii){
          cout<<"end" <<(char)ascii  << endl;
          end_ch = (char)(ascii+1);
        }
      }
    
}*/
cout<<"beg_ch" << begin_ch << endl;
cout<<"end_ch" << end_ch << endl;

string beg_str = string(1,begin_ch);
string end_str = string(1,end_ch);

str = beg_str+end_str;

  return str;

}

int main(void) { 
   
  // keep this function call here
  cout << AlphabetRunEncryption(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
