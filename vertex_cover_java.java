import java.util.*; 
import java.io.*;

class Main {

  public static String VertexCovering(String[] strArr) {
    TreeMap<String,String>all_edges = new TreeMap<>();
    TreeMap<String,String>missing_from_vertex_cover = new TreeMap<>();
    ArrayList<String>vertex_cover = new ArrayList<String>();
  
    boolean left_par = false;
    boolean right_par = false;
    boolean is_dot = false;
    boolean is_line = false;
    boolean is_edge = false;
  
    String first_edge;
    String second_edge;
    String first_vertex;
    String second_vertex;
    
    ArrayList<String>all_vertices = new ArrayList<String>();
    for(int i = 0;i<strArr.length;++i){
      System.out.println(strArr[i]);
      if(i == 1){
        for(int j = 0;j<strArr[i].length();++j){
          if(strArr[i][j] == "("){
            left_par = true;
        }
        else if(strArr[i][j] == ")"){
          right_par = true;
        }
        else if(strArr[i][j] == ","){
is_dot = true;
        }
        else if(strArr[i][j] == "-"){
          is_line = true;
        }
        else{
          is_edge = true;
//          System.out.prinln(strArr[i][j]);
          if(is_line){
            second_edge = strArr[i][j];
            is_line = false;
            all_edges.put(first_edge,second_edge);
          }
          else if(left_par && not(is_line)){
            first_edge = strArr[i][j];
          }
        }
      }
    }
    if(i == 2){
      for(int j = 0;j<strArr[i].length();++j){
        if(strArr[i][j] == "("){
          left_par = true;
        }
        else if(strArr[i][j] == ")"){
          right_par = true;
        }
        else if(strArr[i][j] == ","){
          is_dot = true;
      }
        else if(strArr[i][j] == "-"){
          is_line = true;
        }
        else{
          is_edge = true;
          System.out.prinln(strArr[i][j]);
          if(is_dot){
            second_vertex = strArr[i][j];
            is_dot = false;
            vertex_cover.put(first_vertex,second_vertex);
          }
          else if(left_par && not(is_line)){
            first_vertex = strArr[i][j];
          }
        }
      }
    }
  } 
  //for(auto edges:all_edges){
    //if(find(vertex_cover.begin(),vertex_cover.end(),edges.first) == vertex_cover.end() && find(vertex_cover.begin(),vertex_cover.end(),edges.first) == vertex_cover.end()){
      //missing_from_vertex_cover.insert(make_pair(first_edge,second_edge));
      //cout<<"First vertex of edge" <<edges.first << endl;
      //cout<<"Second vertex of edge"<< edges.second << endl;
    //}
    //cout<<"First vertex of edge" <<edges.first << endl;
    //cout<<"Second vertex of edge"<< edges.second << endl;
  //}

//for(auto missing:missing_from_vertex_cover){
    //cout<<"First vertex of edge" << missing.first << endl;
    //cout<<"Second vertex of edge"<< missing.second << endl;
  //}

    return strArr[0];
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(VertexCovering(s.nextLine())); 
  }

}
