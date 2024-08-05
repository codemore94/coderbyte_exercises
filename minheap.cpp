#include <iostream>
#include <string>
#include <map>
using namespace std;

struct value{
  int mv;
  int jmp;
};

//vector<int,value>activation_record;


int ArrayMinJumps(int arr[], int arrLength) {
  multimap<int,value>valuemap;
  // code goes here  
  int move = 0;
  int jump = 0;
  for(int i = 0;i<arrLength;++i){
    cout<< arr[i] <<endl;
    move = arr[i]; //current value of max possible move
    ++jump; //update jump counter
    value tmp = {move,jump}; 
    valuemap.insert(make_pair(i,tmp));
  }


  for(int i = 0;i<arrLength;++i){
    auto key = i;
    auto values = valuemap.equal_range(key);
    if(values.first == values.second){
      cout<< "No values" << endl;
    }
    else{
      for(auto val = values.first;val!=values.second;++val){
        cout<< val->first << "Index" << endl;
        
    }
    }
  }

  return arr[0];

}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayMinJumps(A, arrLength);
  return 0;
    
}
