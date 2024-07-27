import java.util.*; 
import java.io.*;
import java.util.TreeMap;
class Main {

  public static String LRUCache(String[] strArr) {
    // code goes here
    Integer counter = 1;  
    TreeMap<String,Integer> cache = new TreeMap<>();
    for(int i =0;i<strArr.length;++i){
      if(cache.containsKey(strArr[i])){
        Integer current = cache.get(strArr[i]);
        ++current;
        cache.put(strArr[i],current);
      }
      else{
        cache.put(strArr[i],counter);
      }
      
    }

    for (String key : cache.keySet()) {
      System.out.println("Key: " + key + ", Value: " + cache.get(key));
    }

    return strArr[0];
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(LRUCache(s.nextLine())); 
  }

}
