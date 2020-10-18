// Write a program of array of object in Java
//package practice;
import java.lang.Object;

public class ArrayOfObjects {
    public static void main(String[] args)
    {
    
       Employee e1 = new Employee();
        Address ad = new Address();
        
        Object obj3[] = {e1,ad};
        System.out.println("Dissimiliar Elements of Array of Objects...");
        for(Object o1 : obj3)
        {
            System.out.println(o1);
        }
        
            
    }  
}

class Employee
{
    String nam = "Jiya";
    String id = "A1234";
    @Override
    public String toString()
    {
        return nam+" : "+id;
    }
}

class Address
{
   String hno = "123 New Delhi";
   public String toString()
   {
      return hno; 
   }
}
