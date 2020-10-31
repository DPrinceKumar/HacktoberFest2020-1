import java.util.Scanner;
public class p4{
     public static void main(String[] args) {
        Area a = new Circle();
        a.area();
        }
}

class Area{
    Scanner sc = new Scanner(System.in);
    int r;
    Area(){
        r = 0;
    }
    
    void area(){
        System.out.println("Enter the radius:");
        r = sc.nextInt();
    }
} 

class Circle extends Area{
    double area;
    Circle(){
        area = 0;
    }
    void area(){
        super.area();
        area = r*r*3.14;
        System.out.println("Area of circle is "+ area );
    }

}