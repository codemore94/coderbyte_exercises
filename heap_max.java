import java.util.*; 
import java.io.*;

class Main {

  public static boolean check_children(int next_index){
    
    return check_children();
  }

  public static String MaxHeapChecker(int[] arr) {
    String word = "";
    boolean max_property = false;
    int root = arr[0];  
    for(int i = 0;i<arr.length;++i){
      root = arr[i-1];
      if(arr[(2*i)-1]<root and arr[((2*i)+1)-1]<root){ 
        max_property = true;  
      }
      else{
        max_property = false;
      }
      if(max_property){
        return "max";
      }
      else{
        for(int i = 0;i<arr.length;++i){
        //word+=to_string(arr[j]);
      }
      return word;
    }  
  }
    

    
    // code goes here  
    return arr[0];
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(MaxHeapChecker(s.nextLine())); 
  }

}
