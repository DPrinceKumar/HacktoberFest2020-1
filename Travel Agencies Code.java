import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution
{

 public static void main(String[] args)
 {
  //code to read values 
  //code to call required method
  //code to display the result
  Tra[] travel=new Tra[4];
                Scanner sc = new Scanner(System.in);
for(int i=0; i<travel.length;i++){
    int rno = sc.nextInt();
    sc.nextLine();
String aname = sc.nextLine();
String ptype=sc.nextLine();
int price =sc.nextInt();
int r =sc.nextInt();
sc.nextLine();
String loc=sc.nextLine();
sc.nextLine();
travel[i]=new Tra(rno, aname, ptype, price, r, loc);
}
        String location =sc.nextLine();
        String pactype = sc.nextLine();
        int hprice= findAgencyWithHighestPackagePrice(travel, location);
if(hprice>0){
System.out.println(hprice);
return;
}
else{
    System.out.println("No agencies in the given location");
}
 Tra[] newtravel = sortedAgencyDetailsByPckg(travel, pactype);
if(newtravel!= null){
for(Tra s:newtravel)
System.out.println(s.getAname())

}else{
    System.out.println("No such agencies with the given packageType"); 
  
}      
 }

public static int findAgencyWithHighestPackagePrice(Tra[] travel, String location)
  {
   //method logic
   int Count=0;
int highp=0;
int temp=0;
for(int i=0; i<travel.length;i++){
if(travel[i].getLocation().equalsIgnoreCase(location)){
        if(travel[i].getPrice()>temp){
        highp=travel[i].getPrice();
        temp=highp;
        Count++;
}
}
}
if(Count>0){
return highp;
}else{
     return 0;
}

  }
public static Tra[] sortedAgencyDetailsByPckg(Tra[] travel, String pactype)
  {
   //method logic
   Tra[] newt=null;
   Tra temps=null;
int count=0;
        for(Tra s: travel){
        if(s.getPacktype().equalsIgnoreCase(pactype))
        count++;
        }
        if(count>0){
        newt=new Tra[count];
        count=0;

        for(Tra s:travel){
        if(s.getPacktype().equalsIgnoreCase(pactype))
        newt[count++]=s;
        }
        for(int i=0; i<newt.length-1;i++)
            for(int j=i+1; j<newt.length;j++){


            if(newt[i].getRno()<newt[j].getRno()){
            temps=newt[i];
            newt[i]=newt[j];
            newt[j]=temps;
            }
            }
        }
        return newt;
        }

}
class Tra
{
  //code to build the class
  
  private int rno;
    private String aname;
    private String ptype;
    private int price;
    private int r;
    private String loc;
    
    public Tra(int rno, String aname, String ptype, int price, int r, String loc){
    super();
    this.rno=rno;
    this.aname=aname;
    this.ptype=ptype;
    this.price=price;
    this.r=r;
    this.loc=loc;
    }

    public int getRno(){
    return rno;
    }
    public void setRno(int rno){
    this.rno=rno;
    }

    public String getAname(){
    return aname;
    }

    public void setAname(String aname){
    this.aname=aname;
    }

    public String getPacktype(){
    return ptype;
    }

    public void setPacktype(String ptype){
    this.ptype=ptype;
    }
    public int getPrice(){
    return price;
    }

    public void setPrice(int price){
    this.price=price;
    }
    public int getR(){
    return r;
    }
    public void setR(int r){
    this.r=r;
    }

public String getLocation(){
    return loc;
    }

    public void setLocation(String loc){
    this.loc=loc;
    }
    
   
}

                 




