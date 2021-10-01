package com.company;
//import java.util.Scanner;
class library{
    String[] books;
    int no_of_books;
    int opt;
//    Scanner sc = new Scanner(System.in);
    library(){
        this.books = new String[100];
        this.no_of_books=0;
    }
    public void addBook(String book) {
//        System.out.println("Enter the Name of the Book you Want to add ");
//        String book = sc.nextLine();
        this.books[no_of_books]=book;
        no_of_books++;
        System.out.println(book+" has been added");
    }
    public void availableBook(){
        System.out.println("Available Books Are :- ");
        for (String book:books) {
            if (book == null) {
                continue;
            }
            System.out.println("* "+book);
        }
    }
    public void issueBook(String ib){
//        System.out.println("Enter the Name of book You want to Issue :- ");
//        String ib = sc.nextLine();
        for (int i =0; i<this.books.length;i++){
            if (this.books[i].equals(ib)){
                System.out.println("Book have been issued ");
                this.books[i]=null;
                return;
            }
            else {
                System.out.println("Sorry, The Book you are requesting we Don't Have ");
            }
        }
    }
    public void ReturnBook(String rb){
//        System.out.println("Enter the name of the book you want to return :- ");
//        String rb = sc.nextLine();
        this.books[no_of_books]=rb;
        no_of_books++;
        System.out.println(rb+" has been Returned");
    }
}
public class Exercise4_Soln {
    public static void main(String[] args)  {
            library centralLibrary = new library();
        centralLibrary.addBook("c++");
        centralLibrary.addBook("Java");
        centralLibrary.addBook("c");
        centralLibrary.addBook("php");
        centralLibrary.addBook("sql");
        centralLibrary.availableBook();
        centralLibrary.issueBook("c++");
        centralLibrary.availableBook();
        centralLibrary.ReturnBook("c++");
        centralLibrary.availableBook();
    }
}
