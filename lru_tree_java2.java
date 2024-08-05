import java.util.*; 
import java.io.*;

class Main {

  public static String LRUCache(String[] strArr) {
    // code goes here  
    Deque<String> deque = new LinkedList<String>();
    for(int i = 0;i<strArr.length;++i){
      //System.out.println(strArr[i]);
      if(deque.contains(strArr[i]) == true){
        deque.remove(strArr[i]);
        deque.add(strArr[i]);
      }
      else if(deque.contains(strArr[i]) == false){
        deque.add(strArr[i]);
      }
    }

    for(String elem:deque){
      System.out.println(elem);
    }
    
    return strArr[0];
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    LRUCache(s.nextLine());
//    System.out.print(LRUCache(s.nextLine())); 
  }

}
