import java.util.*;

    class Dijkstra{
	public static void main(String args[]){
	    TreeMap<Character,Character> nodemap = new TreeMap<>();
	    //System.out.println("Give nodes with weights in form (node,weight)");
	    Scanner request = new Scanner(System.in);
	    String answer = request.nextLine();
	    String[] list = answer.split(",");
	    Character key = 0;
	    Character value = 0;
	    for(int i= 0;i<list.length;i++){
		//System.out.println(list[i]);
		for(int j= 0;j<list[i].length();j++){
		    if(Character.isLetter(list[i].charAt(j))){
			//System.out.println(list[i].charAt(j));
			key = list[i].charAt(j);
		    } 
		    else if(Character.isDigit(list[i].charAt(j))){
			//System.out.println(list[i].charAt(j));
			value = list[i].charAt(j);
		    } 
		}
		

	    }
	    nodemap.put(key,value);
	    for(Character k:nodemap.keySet()){
		System.out.println("Key" + k);
		System.out.println("Value" + nodemap.get(k));
	    }

	    
	}
    }
