package new_java;
import java.util.*;
public class a11 {

	public static void main(String[] args)
	{
		StringTokenizer st = new StringTokenizer("Hello, World|of|Java", ", |", true);
		while (st.hasMoreElements( ))
			System.out.println("Token: " + st.nextElement( ));

	}

}
