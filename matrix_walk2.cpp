#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<<deque<int>> goto_previous_location(deque<<deque<int>>& history){
  int previous_location =history.pop_back();
  return previous_location;
}

string walk_through_matrix(vector<string>& m){
    deque<<deque<int>> step_history;
    deque<int> step_deck; 
    int init_row = 0;
    int init_col = 0;
    step_deck.push_back(row);
    deque.push_back(step_deck);
    
    string return_value;
    string direction;
    bool found_one = false;
    vector<string>::iterator mt;
    mt = m.begin();
    while(mt!=m.end()){
      cout<< *mt << endl;
      for(int i = 0;i<(*mt).size();++i){
      //cout<< strArr[i] << endl;
        if((*mt).at(i) == '1'){
          found_one = true;
        }
        else{
          found_one = false;
          auto prev_loc = goto_previous_location(step_history);
        }
        if(found_one == true){
          if(direction == "right" and i<(*mt).size()){ //next 1 from right
            if((*mt).at(i+1) == '1'){
              found_one = true; //keep founding true
            }
            else{
              //need to check other 3 options: d,u,l
              //goto next if
            }  
          }
        }  
      }
    ++mt;
  }
  return return_value;
}


string MatrixPath(string strArr[], int arrLength) {
  vector<string>matrix;
  string direction;
  bool found_one = false;
  for(int i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    matrix.push_back(strArr[i]);  
  }
 string return_value =  walk_through_matrix(matrix);
          //else if(direction = "down"){
          //++mt; //update to next iteration;problem how to do in auto:-loop
          //if(mt.at(i) == '1'){
           //found_one = true; //keep founding true
          //}
          //else{
            //goto next if
          //}
        //}
        //if(direction = "up"){
          //--mt;
          //if(mt.at(i) == '1'){
           //found_one = true; //keep founding true
          //}
          //else{
            //goto next if
          //}
        //}
        //if(direction = "left"){
          //if(mt.at(i+1) == '1'){
           //found_one = true;
          //}
          //else{
            //exit
          //}
        //}
      //}
      //else if(found_one == false){
        //exit
      //}
       
  
  return return_value;

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  //cout << MatrixPath(A, arrLength);
  MatrixPath(A, arrLength);
  return 0;
    
}
