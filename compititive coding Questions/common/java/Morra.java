import java.util.Scanner;
public class Morra{
    public static String nome1="",nome2="",oggetton1="",oggetton2="";
    public static char risposta='s';
    public static boolean entrato=false;
    public static void main(String[] args) {
       Scanner tastiera = new Scanner(System.in); 
       System.out.println("Inserisci nome primo giocatore: ");
       nome1=tastiera.next();
       System.out.println("Inserisci nome secondo giocatore: ");
       nome2=tastiera.next();
       do{
           if(risposta=='s'){
            System.out.println("Tocca a "+nome1+": ");
       oggetton1=tastiera.next();
       System.out.println("Tocca a "+nome2+": ");
       oggetton2=tastiera.next();
       if(oggetton1.equals("carta") && oggetton2.equals("pietra")){
           System.out.println("Congratulazioni "+nome1);
           entrato=true;
       }
       if(oggetton1.equals("carta") && oggetton2.equals("forbice")){
        System.out.println("Congratulazioni "+nome2);
        entrato=true;
        }
        if(oggetton1.equals("carta") && oggetton2.equals("carta")){
            System.out.println("Pareggio ");
            entrato=true;
        }
        if(oggetton1.equals("forbice") && oggetton2.equals("pietra")){
            System.out.println("Congratulazioni "+nome2);
            entrato=true;
        }
        if(oggetton1.equals("forbice") && oggetton2.equals("forbice")){
         System.out.println("Pareggio ");
         entrato=true;
         }
         if(oggetton1.equals("forbice") && oggetton2.equals("carta")){
             System.out.println("Congratulazioni "+nome1);
             entrato=true;
         }
         if(oggetton1.equals("pietra") && oggetton2.equals("pietra")){
            System.out.println("Pareggio");
            entrato=true;
        }
        if(oggetton1.equals("pietra") && oggetton2.equals("forbice")){
         System.out.println("Congratulazioni "+nome1);
         entrato=true;
         }
         if(oggetton1.equals("pietra") && oggetton2.equals("carta")){
             System.out.println("Congratulazioni "+nome2);
             entrato=true;
         }
         
         if(!entrato){
            System.out.println("Hai sbagliato la sintassi: Scegli tra | pietra | carta | forbice");
         }

         System.out.println("Vuoi giocare ancora? s/n ");
         risposta=tastiera.next().charAt(0); //rispostaValida = risposta.equalsIgnoreCase("si") || risposta.equalsIgnoreCase("no");
           }else{
               System.exit(0);
           }
       
        }while(true);
         

    }
}