import java.io.*;
import java.util.*;

public class ConvertingStringsFile {
  
  
  
  
// Method that eliminates the parameter sentence strings with value STOP
  public static String stringResult(String frase) {
  List valid = Arrays.asList("the","be","to","of","and","a","are","am","in","that","have","i","it","for","on","with","he","as","i'm","!",",","it's","you","do","at","this","but","his","is","was",".","by","from","they","we","say","her","she","or","an","will","my","one","all","would","there","their","what","so","up","out","if","about","who","get","which","go","me","when","can","just","him","into","year","your","some","could","them","see","other","than","then","now","look","only","its","over","think","also","ack","after","use","two","how","our","work","first","well","way","even","want","because","any","these","give");
     String element,result="";  
     StringTokenizer st = new StringTokenizer(frase); 
     int numToken=st.countTokens();       
     while (st.hasMoreTokens()) { 
       element=st.nextToken();
       result+=valid.contains(element)?"" : element+" ";
     }
     return result;
  }
  
  public static void main(String[] main) throws IOException  {
  
  
    String result="";
    String fileInput,rigaFile,fileOutput;
    fileInput="data.txt";
    fileOutput="cleaned_data.txt";
    try {			
       BufferedReader flussoLettura = new BufferedReader(new FileReader(fileInput));
       PrintWriter flussoScrittura = new PrintWriter(new BufferedWriter(new FileWriter(fileOutput)));
       do {
     rigaFile = flussoLettura.readLine();
     //rigaFile=(rigaFile!=null)?rigaFile.replaceAll("\\W", " ").replaceAll("\\d"," "):rigaFile;
    rigaFile=(rigaFile!=null)?rigaFile.replaceAll("[^\\w-+]+", " ").replaceAll("\\d"," "):rigaFile;
  // rigaFile=(rigaFile!=null)?rigaFile.replaceAll("(^.$|\\s.\\s|^.\\s|\\s.$)", " ").replaceAll("\\s+", " ").trim():rigaFile;
     rigaFile=(rigaFile!=null)?rigaFile.toLowerCase():rigaFile;
     result=(rigaFile!=null)?stringResult(rigaFile ):"";
     flussoScrittura.println(result); 
       } while(rigaFile!=null);  
       flussoLettura.close(); 
       flussoScrittura.close();
     }	
     catch(FileNotFoundException eccezione) {
     }
     catch(IOException eccezione) {
     }
    
    }
    }
  
     
