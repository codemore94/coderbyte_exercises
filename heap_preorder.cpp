#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
};
class HeapTree{
  public:
    HeapTree();
    void add_element(int val,int ind);
    void print_tree();
  private:
    Node* root;
};

HeapTree::HeapTree(){}
void HeapTree::add_element(int val,int ind){
  if(root == nullptr){
    root = new Node();
    root->left = nullptr;
    root->right = nullptr;
  }
  else{
    if(ind%2 == 1){
      Node* node = new Node();
      root->left = node;
    }
    else{
      Node* node = new Node();
      root->right = node;
    }
  }
}

void HeapTree::print_tree(){}

string PreorderTraversal(string strArr[], int arrLength) {
  HeapTree heaptree;
  // code goes here  
  int elem = 0;
  int index = 0;
  string elem_str;
  for(int i =0;i<arrLength;++i){
    elem_str = strArr[i];
    index = i;
    if(elem_str != "#"){
      stringstream strm(elem_str);
      strm >> elem;
      heaptree.add_element(elem,index);
    }
    else{
      elem = -1;
      heaptree.add_element(elem,index);
    }
  }

  return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << PreorderTraversal(A, arrLength);
  return 0;
    
}
