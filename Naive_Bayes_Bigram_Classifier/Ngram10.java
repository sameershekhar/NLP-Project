import java.util.*;
import java.io.*;
import java.math.*;
public class Ngram10 {






    public static List<String> ngrams(int n, String str) {
        List<String> ngrams = new ArrayList<String>();
        String[] words = str.split(" ");
        for (int i = 1; i < words.length - n + 1; i++)
            ngrams.add(concat(words, i, i+n));
        return ngrams;
    }

    public static String concat(String[] words, int start, int end) {
        StringBuilder sb = new StringBuilder();
        for (int i = start; i < end; i++)
            sb.append((i > start ? " " : "") + words[i]);
        return sb.toString();
    }

    public static void main(String[] args)throws IOException {
    //readFile("yourFile.txt");
    
    //PrintWriter out1 = new PrintWriter("output_pos_uni.txt");
	//PrintWriter out2 = new PrintWriter("output_pos_bigram.txt");
	//PrintWriter out3 = new PrintWriter("output_neg_uni.txt");
   //	PrintWriter out4 = new PrintWriter("output_neg_bigram.txt");
	PrintWriter out5 = new PrintWriter("bigram_result10.txt");
	//PrintWriter out6 = new PrintWriter("bigram_vocab_all_data.txt");
	
    
    Map<String, Integer> map1 = new HashMap<>();
	Map<String, Integer> map2 = new HashMap<>();
	
    Map<String, Integer> map3 = new HashMap<>();
	Map<String, Integer> map4 = new HashMap<>();
	Map<String, Integer> map5 = new HashMap<>();
    BufferedReader br = new BufferedReader(new FileReader("train10.txt"));
	
	
    StringBuilder sb = new StringBuilder();
        String line = br.readLine();
        while ((line = br.readLine()) != null) {
			String[] words1 = line.split(" ");
       		 for (int n = 1; n <= 2; n++) {
            		for (String w : ngrams(n, line))
                		{
                		//System.out.print(ngram);
                		//out.write(ngram);
                		//out.println(ngram);
						       
						        
						 
						 if(words1[0].equals("+"))
						 {
							 if(n==1)
							 {
								 Integer m = map1.get(w);
                                 m = (m == null) ? 1 : ++m;
						         map1.put(w, m);
								  map5.put(w, m);
							 }
							 else
							 {
								 Integer m = map2.get(w);
                                 m = (m == null) ? 1 : ++m;
						         map2.put(w, m);
								  map5.put(w, m);
								 
							 }
						 }
                           
						else 
						{
							if(n==1)
							{
								Integer m = map3.get(w);
                             m = (m == null) ? 1 : ++m;
							 map3.put(w,m);
						  map5.put(w, m);
							}
							else
							{
									Integer m = map4.get(w);
                             m = (m == null) ? 1 : ++m;
							 map4.put(w,m);
					      map5.put(w, m);
								
							}
							
						}
							
                		}
            			//System.out.println();
        			}
        			
			}

		Set keys = map2.keySet();
		double pos=0.0;
		double neg=0.0;
		double total_words=0.0;

	for (Iterator i = keys.iterator(); i.hasNext();) 
   {
       String key = (String) i.next();
       Integer value = (Integer) map2.get(key);
	   if(value>=2)
	   {
		   //out2.println(key + " = " + value);
		   pos=pos+value;
	   }
	   String[] word = key.split(" ");
	   Integer value1=(Integer) map1.get(word[0]);
	    value1=value1-value;
		if(value1>=2)
			map1.put(word[0],value1);
		   
   }
				
				 keys = map1.keySet();
			
	for (Iterator i = keys.iterator(); i.hasNext();) 
   {
       String key = (String) i.next();
       Integer value = (Integer) map1.get(key);
	   if(value>=2)
	   {
		   //out1.println(key + " = " + value);
		   pos=pos+value;
	   }
       //System.out.println(key + " = " + value);
   }		

   
   
	
   
   
   
    keys = map4.keySet();
   for (Iterator i = keys.iterator(); i.hasNext();) 
   {
       String key = (String) i.next();
       Integer value = (Integer) map4.get(key);
	   if(value>=2)
	   {
		   //out4.println(key + " = " + value);
		   neg=neg+value;
	   }
	   
	   String[] word = key.split(" ");
	   Integer value1=(Integer) map3.get(word[0]);
	    value1=value1-value;
		if(value1>=2)
			map3.put(word[0],value1);
       //System.out.println(key + " = " + value);
   }
   
   keys = map3.keySet();
   for (Iterator i = keys.iterator(); i.hasNext();) 
   {
       String key = (String) i.next();
       Integer value = (Integer) map3.get(key);
	   if(value>=2)
	   {
		   //out3.println(key + " = " + value);
		   neg=neg+value;
	   }
       //System.out.println(key + " = " + value);
   }
   
   keys = map5.keySet();
   for (Iterator i = keys.iterator(); i.hasNext();) 
   {
       String key = (String) i.next();
       Integer value = (Integer) map5.get(key);
	   if(value>=2)
	   {
		   //out6.println(key + " = " + value);
		   total_words++;
	   }
       //System.out.println(key + " = " + value);
   }		
   
   BufferedReader br1 = new BufferedReader(new FileReader("test10.txt"));
   String line1 = br1.readLine();
   double count=0;
        while ((line1 = br1.readLine()) != null)
			{
				double result1=0.0;
				double result2=0.0;
				int pre;
			   String[] words2 = line1.split(" ");
			   //System.out.println(words2[0]);
       		   for (int n = 2; n <= 2; n++) 
			   {
            		for (String w : ngrams(n, line1))
					{
						String[] words3 = w.split(" ");
						
							Integer val=(Integer)map2.get(w);
							
							if(val!=null)
							{
								//System.out.print(w);
								//System.out.println(val);
								double x=Math.log((val+1)/(pos+total_words));
								result1=result1+x;
								
							}
							else
							{
								Integer val1=(Integer)map1.get(words3[0]);
								if(val1!=null)
								{
									double x=Math.log((val1+1)/(pos+total_words));
									result1=result1+x;
								}
									
								else
								{
									double x=Math.log((0+1)/(pos+total_words));
									result1=result1+x;
									
								}
								//System.out.print(words3[0]);
								//System.out.println(val1);
								
							}
							
							
							
						
					
							Integer val2=(Integer)map4.get(w);
							
							if(val2!=null)
							{
								//System.out.print(w);
								//System.out.println(val);
								double x=Math.log((val2+1)/(neg+total_words));
								result2=result2+x;
							}
							else
							{
								
								Integer val1=(Integer)map3.get(words3[0]);
								if(val1!=null)
								{
									
							         double x=Math.log((val1+1)/(neg+total_words));
									result2=result2+x;
								}
								else
								{
									double x=Math.log((0+1)/(neg+total_words));
									result2=result2+x;
								}
									
								//System.out.print(words3[0]);
								//System.out.println(val1);
								
							}
							
							
						}
						
						
						
			   }
			   if(result1>result2)
			   {
				   pre=1;
				  // System.out.print(words2[0]);
				  // System.out.println(result1+" "+result2);
				   
			   }
						else
						{
							pre=0;
						//
						}
						
  						
						
				if(words2[0].equals("+")&&pre==1)
				{
					 out5.println("1");
					 count++;
				}
                else if((words2[0].equals("-")&&pre==0))	
				{
					out5.println("1");
					count++;
				}
				else
					out5.println("0");
					
  
   
			}
			out5.println("Correct Prediction"+count);
			out5.println("Accuracy"+(count/60)*100);
   
   
   
			
			/*out1.close();
			out2.close();
			out3.close();
			out4.close();*/
			out5.close();
			//out6.close();
    		}
    		
}
