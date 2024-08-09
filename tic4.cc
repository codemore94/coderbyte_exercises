#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string>columnwise1;
  vector<string>columnwise2;
  vector<string>columnwise3;
  
void NoughtsDeterminer(string strArr[], int arrLength) {
  vector<string>row;
  vector<vector<string>>board;
  int counter = 0;
  stringstream return_stream;
  string ret_str;
  bool all_other_equal = true;
  vector<vector<string>>::iterator it;
  vector<string>::iterator jt;

  // code goes here  
  int i = 0;
  for(i = 0;i<arrLength;++i){
    //cout<< strArr[i] << endl;
    if(strArr[i] == "<>"){
      //cout<< "is <>" << endl;
      board.push_back(row);
      row.clear();
      //board.push_back(strArr[i]);

    }
    else if(strArr[i] == "-"){
      //cout<< "is -" << endl;
      row.push_back(strArr[i]);
    }
    else if(strArr[i] == "X"){
      //cout<< "is x" << endl;
      row.push_back(strArr[i]);
    }
    else if(strArr[i] == "O"){
      //cout<< "is o" << endl;
      row.push_back(strArr[i]);
    }
  }
  if(i == arrLength){
      board.push_back(row);
      row.clear();
  }
  it = board.begin();
  while(it!=board.end()){
    jt = (*it).begin();
    while(jt!=(*it).end()){
      ++counter;
      if(jt!=prev((*it).end(),1)){
        if(*jt == "X" and *(jt+1) == "X"){
          //cout <<"All elem " <<*jt ;
        //all_other_equal = not(all_other_equal);
        //are all other chars similar in the row
        //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
        //}
        }
        else{
          all_other_equal = false;
        }
      }
      else if(jt!=prev((*it).end(),1)){
        if(*jt == "O" and *(jt+1) == "O"){
          //cout <<"All elem " <<*jt ;
        //all_other_equal = not(all_other_equal);
        //are all other chars similar in the row
        //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
        //}
        }
        else{
          all_other_equal = false;
        }
      }
      ++jt;
    }
    if(all_other_equal){
          return_stream << counter;
          return_stream >> ret_str;
          //return ret_str;  
        }
    else{
      counter = -1;
      return_stream << counter;
      return_stream >> ret_str;
      //return ret_str;
    }

    ++it;
  }
  vector<vector<string>>row_wise;
  vector<string>col_tmp;
  
  
  vector<vector<string>>::iterator kt;
  vector<string>::iterator mt;
  kt=board.begin();
  while(kt!=board.end()){
    mt = (*kt).begin();
    while(mt!=(*kt).end()){
//      cout<< "Rowwise" << *mt << endl;
      if(mt == (*kt).begin()){
      //col_tmp.push_back(*mt);
        columnwise1.push_back(*mt);
      }
      else if(mt == (*kt).begin()+1){
        columnwise2.push_back(*mt);
      }
      else if(mt == (*kt).begin()+2){
        columnwise3.push_back(*mt);
      }
      ++mt;
    }
    row_wise.push_back(col_tmp);
    col_tmp.clear();
    ++kt;
  }
  vector<string>::iterator co1;
  co1 = columnwise1.begin();
  while(co1!=columnwise1.end()){
    cout<< "col1wise" << *co1 << endl;
    if(co1!=prev(columnwise1.end(),1)){
        if(*co1 == "X" and *(co1+1) == "X"){
          //cout <<"All elem " <<*jt ;
          //all_other_equal = not(all_other_equal);
          //are all other chars similar in the row
          //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
          //}
        }
    }
    //else{
          //all_other_equal = false;
        //}
    else if(jt!=prev(columnwise1.end(),1)){
        if(*jt == "O" and *(jt+1) == "O"){
          //cout <<"All elem " <<*jt ;
          //all_other_equal = not(all_other_equal);
          //are all other chars similar in the row
          //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
          //}
        }
        //else{
          //all_other_equal = false;
        //}
      }
  
    ++co1;
  }

  vector<string>::iterator co2;
  co2 = columnwise2.begin();
  while(co2!=columnwise2.end()){
    cout<< "col2wise" << *co2 << endl;
    if(co2!=prev(columnwise2.end(),1)){
        if(*co2 == "X" and *(co2+1) == "X"){
          //cout <<"All elem " <<*jt ;
        //all_other_equal = not(all_other_equal);
        //are all other chars similar in the row
        //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
        //}
        }
    }
    //else{
          //all_other_equal = false;
        //}
    else if(co2!=prev(columnwise2.end(),1)){
      if(*co2 == "O" and *(co2+1) == "O"){
            //cout <<"All elem " <<*jt ;
            //all_other_equal = not(all_other_equal);
            //are all other chars similar in the row
            //if(all_other_equal){
            //return_stream << index;
            //ret_str << return_stream;
            //return ret_str;  
            //}
      }
        //else{
          //all_other_equal = false;
        //}
    }
    //++co2;
  
    ++co2;
  }
vector<string>::iterator co3;
  co3 = columnwise3.begin();
  while(co3!=columnwise3.end()){
    cout<< "col3wise" << *co3 << endl;
    if(co3!=prev(columnwise3.end(),1)){
        if(*co3 == "X" and *(co3+1) == "X"){
          //cout <<"All elem " <<*jt ;
        //all_other_equal = not(all_other_equal);
        //are all other chars similar in the row
        //if(all_other_equal){
          //return_stream << index;
          //ret_str << return_stream;
          //return ret_str;  
        //}
        }
    }
    //else{
      //    all_other_equal = false;
        //}
        else if(jt!=prev(columnwise3.end(),1)){
          if(*jt == "O" and *(jt+1) == "O"){
            //cout <<"All elem " <<*jt ;
            //all_other_equal = not(all_other_equal);
            //are all other chars similar in the row
            //if(all_other_equal){
            //return_stream << index;
            //ret_str << return_stream;
            //return ret_str;  
            //}
          }
          //else{
            //all_other_equal = false;
          //}
        }
    //++jt;
  
    ++co3;
}
    //if(all_other_equal){
          //return_stream << counter;
          //return_stream >> ret_str;
          //return ret_str;  
        //}
    //else{
      //counter = -1;
      //return_stream << counter;
      //return_stream >> ret_str;
      //return ret_str;
    //}

  vector<vector<string>>::iterator rot;
  rot = row_wise.begin();
  vector<string>::iterator rt;
  while(rot!=row_wise.end()){
    rt = (*rot).begin();
    while(rt!=(*rot).end()){
    //  cout<< "ROT" << *rt << endl;
      ++rt;
    }
    ++rot;
  }

  //return strArr[0];

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  //cout << NoughtsDeterminer(A, arrLength);
  NoughtsDeterminer(A, arrLength);
  return 0;
    
}
