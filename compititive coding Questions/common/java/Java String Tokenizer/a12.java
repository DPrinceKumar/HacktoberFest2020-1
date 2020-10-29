package new_java;

import java.util.StringTokenizer;

public class a12 {

	public static void main(String[] args) 
	{
		String p=",";
		int count=0;
		String s="hi,itun,|as,hero";
		StringTokenizer st=new StringTokenizer(s,",",true);
		while(st.hasMoreTokens())
		{
			if(st.nextToken()==",")
				count++;
			System.out.println("token:"+st.nextToken());
			System.out.println("count:"+count);
			
		}
	}

}
