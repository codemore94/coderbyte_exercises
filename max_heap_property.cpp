#include <iostream>
#include <string>
using namespace std;

string MaxHeapChecker(int arr[], int arrLength) {
  string word;
  int counter = 0;
  // code goes here
  int root = 0;
  int pulled = 0;
  bool max_property = false;  
  for(int i = 1;i<arrLength and 2*i<arrLength;++i){ //heap-index:from 1,2,3...->0,1,2... minus 1
      root = arr[i-1]; //floor(i/2)-1
      if(arr[(2*i)-1]>root or arr[((2*i)+1)-1]>root){ //1,2
        max_property = false;  //first children: (2*1)-1,(2*1+1)-1
         ++counter; //how many broken max_properties
         if(arr[(2*i)-1]>root){
          pulled = (2*i)-1;
          if(word.empty()){
            word+=to_string(arr[pulled]);
          }
          else{
            word+=",";
            word+=to_string(arr[pulled]);
          }
         }
         if(arr[((2*i)+1)-1]>root){
           pulled = ((2*i)+1)-1;
          if(word.empty()){
            word+=to_string(arr[pulled]);
          }
          else{
            word+=",";
            word+=to_string(arr[pulled]);
          }
         }
         
      
      }
      else{
        //cout<< "index" << 2*i << endl;
       
        max_property = true;

      }
  }
  if(max_property and counter == 0){ //no broken max properties
    return "max";
  }
  else{
    for(int j =0;j<arrLength;++j){
      //word+=to_string(arr[j]);
      //word = to_string(pulled);
    }
    return word;
  }
  

}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MaxHeapChecker(A, arrLength);
  return 0;
    
}
