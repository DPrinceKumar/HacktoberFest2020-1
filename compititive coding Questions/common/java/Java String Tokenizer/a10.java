package new_java;
import java.util.*;
public class a10 {

	public static void main(String[] args)
	{
		String s="hi,itun|as hero";
		StringTokenizer st=new StringTokenizer(s,", |");
		while(st.hasMoreTokens())
		{
			System.out.println("token:"+st.nextToken());
		}
	}

}
