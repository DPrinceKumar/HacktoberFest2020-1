package hacktoberfest;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Hacktoberfest {
    public static void main(String[] args) 
    {
       char[] i = new char[50];
       
       try
       {
           File file = new File("Hacktoberfest2020.txt"); 
           FileWriter fw = new FileWriter(file);
           fw.write("Happy Hactoberfest2020!!!!");
           fw.flush();
           fw.close();
           FileReader fr = new FileReader(file);
           int size =fr.read(i);
           System.out.println("Size of the content:"+size);
           for(char c:i)
           {
               System.out.print(c);
           }
           fr.close();
       }
       catch(IOException e)
       {
           
       }
    }
    
}