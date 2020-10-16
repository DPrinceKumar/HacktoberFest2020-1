/*       
          Name: venkatesh1226
          Program Name : TicTAcToe Automated computer play single player game.                         
*/

/*###########################Program start################################## */
import java.util.*;
public class Main {
	
	static String[][] board=new String[3][3];
	static Scanner sc= new Scanner(System.in);
	static int turn;

	public static void main(String[] args) {
		System.out.println("****WelCome To TicTacToe Game****");
		int row,col;
		fillBoard();
		turn=0;
		System.out.println("Starter is X");
		while((turn<=8)&&turn>=0) {
		System.out.println("\n Its Chance Of "+chance());
			if(chance()=="X") {
		System.out.println("Enter row and column position");
		
		row=sc.nextInt();
		col=sc.nextInt();}
			else {
				
				int[] comMove=computerMove();
				row=comMove[0]+1;
				col=comMove[1]+1;
				
			}
			
		fillBoard(row-1,col-1);
	
		if(isWin(chance())) {
			if(chance()=="X")
			System.out.println("Hey You WOn "+chance());
			else System.out.println("Hey You Lost X");
			return;}
		turn++;
		
				
		}
		System.out.println("Hey Game Is Draw");
	}
	
	static int[] computerMove() {
		int[] move;
		
	
		move=checkRows(board);
		if(move.length==1) {
			move=checkColumns();
		}
		if(move.length==1)
			move=checkDiagnol();
		if(move.length==1)
			move=randomMove();
	
		
		return move;
	}

	
	
	
	static int[] randomMove() {

		int x=1,y=1;
		if(board[x][y]!=" ") {
		y=getY(x);
		while(y==-1) {			
		x=(++x)%3;
			y=getY(x);
		}}
			return new int[] {x,y};
			
	}
	static int getY(int x) {
		
		for(int i=0;i<3;i++)
		{
			if(board[x][i]==" ")
				return i;
		}
		return -1;
	}
	
	static int[] checkDiagnol() {	
		
		if(d1()==true&&d2()==true) {
			
		if(board[1][1]==board[2][2]&&board[1][1]!=" ")
			return new int[] {0,0};
		if(board[1][1]==board[0][0]&&board[1][1]!=" ")
			return new int[] {2,2};
		if(board[0][0]==board[2][2]&&board[0][0]!=" ")
			return new int[] {1,1};
		if(board[0][2]==board[1][1]&&board[1][1]!=" ")
			return new int[] {2,0};
		if(board[0][2]==board[2][0]&&board[2][1]!=" ")
			return new int[] {1,1};
		if(board[1][1]==board[2][0]&&board[1][1]!=" ")
			return new int[] {0,2};
		}
		return new int[] {-1};
	}
	static boolean d1() {
		for(int i=0;i<3;i++)
			if(board[i][i]==" ")
				return true;
		return false;
	}
	static boolean d2() {
		if(board[0][2]==" "||board[1][1]==" "||board[2][0]==" ")
			return true;
		return false;
		
	}
	static int[] checkColumns() {
	
		int[] move=checkRows(transpose());
		if(move.length==2)
		return new int[] {move[1],move[0]};
		return move;
		
	}
	static String[][] transpose() {
		String[][] rev=new String[3][3];
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				rev[j][i]=board[i][j];
				
			}
		}
		return rev;
	}
	
	static int[] checkRows(String[][] a) {
		
		for(int i=0;i<3;i++)
		{if(filled(i,a))
			continue;
			if(a[i][1]==a[i][2]&&a[i][1]!=" ")
				return new int[] {i,0};
			if(a[i][1]==a[i][0]&&a[i][1]!=" ")
				return new int[] {i,2};
			if(a[i][2]==a[i][0]&&a[i][0]!=" ")
				return new int[] {i,1};
			
		}
			return new int[] {-1} ;
		
	}
	static boolean filled(int k,String[][] a) {
		int c=0;
		for(int i=0;i<3;i++)
			if(a[k][i]!=" ")
				c++;
	
		return c==3;
	}
	
	static boolean isWin(String s) {
		if(board[0][0]==s&&board[1][1]==s&&board[2][2]==s)
			return true;
		if(board[0][2]==s&&board[1][1]==s &&board[2][0]==s )
			return true;
		for(int i=0;i<3;i++) {
			if(board[i][0]==s&&board[i][1]==s&&board[i][2]==s)
				return true;
			if(board[0][i]==s&&board[1][i]==s&&board[2][i]==s)
				return true;
		}
		return false;
	}
	
	
	
	static void fillBoard(int row,int col) {
		
	if(board[row][col]==" ")	{
	board[row][col]=chance();
	
	}
	else {
		System.out.println("Enter Appropriate Indexes");
		--turn;
		}
	print();
		
	}
	
	static String chance() {
		return (turn%2==0)?"X":"O";
	}

	static void fillBoard() {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				board[i][j]=" ";
				
			}
		}
		print();
	}
	static void print() {
		System.out.println("\n");
		for(int i=0;i<3;i++) {
			
			for(int j=0;j<3;j++) {
				System.out.print(board[i][j]+"	");
			}
			System.out.println("\n");
		}
		System.out.println("\n");
		
	}

}
/*###########################Program End################################## */
