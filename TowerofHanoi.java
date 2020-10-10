import java.util.*;
public class TowerofHanoi {
	public static void TOH(int n, char SRC, char DEST, char MIDD) {
		if(n == 0)
			return ;
		// PLACE N-1 PLATES FROM SOURCE TO MIDDLE
		TOH(n-1,SRC,MIDD,DEST);
		//PLACE Nth PLATE FROM SOURCE TO DESTINATION
		System.out.println("PLacing  "+ n + " from "+ SRC +" to "+ DEST);
		//PLACE N-1 PLATE FROM  MIDDLE TO DESTINATION
		TOH(n-1,MIDD,DEST,SRC);
	
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
				TOH(4	,'A','C','B');// FROM A TO C WITH THE HELP OF B
				
	}

}
