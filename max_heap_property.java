import java.util.*; 
import java.io.*;

class Main {
  public static String MaxHeapChecker(int[] arr) {
    String word = "";
    boolean max_property = false;
    int root = arr[0];  
    for(int i = 0;i<arr.length;++i){
      root = arr[i-1];
      if(arr[(2*i)-1]<root && arr[((2*i)+1)-1]<root){ 
        max_property = true;  
      }
      else{
        max_property = false;
      }
      if(max_property){
        return "max";
      }
      else{
        for(int j = 0;j<arr.length;++j){
        //word+=to_string(arr[j]);
        }
      }
      return word;
    }  
    // code goes here  
    return word;
  }

  public static int[] parseInput(String input){
    String[] stringArr = input.split(","); // Assuming input is comma-separated
    int[] intArr = new int[stringArr.length];
    for (int i = 0; i < stringArr.length; i++) {
      intArr[i] = Integer.parseInt(stringArr[i].trim());
      }
    return intArr;
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    //System.out.print(MaxHeapChecker(s.nextLine()))
    String input =s.nextLine();
    int [] arr = parseInput(input); 
    MaxHeapChecker(arr);
  }

}
