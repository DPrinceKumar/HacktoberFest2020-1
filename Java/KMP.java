package Strings;

import java.util.Scanner;

public class KMP {

	static int[] prefixtable(String s) {
		int arr[] = new int[s.length()];
		int j = 0;
		arr[0] = 0;
		for (int i = 1; i < s.length(); i++) {

			j = arr[i - 1];

			while (j > 0 && s.charAt(i) != s.charAt(j))

				j = arr[j - 1];

			if (s.charAt(i) == s.charAt(j))
				++j;

			arr[i] = j;

		}

		return arr;

	}

	static void func(String t, String p) {
		int y[] = prefixtable(p);
		int j = 0, count = 0, i = 0;
		while (i < t.length()) {
			if (t.charAt(i) == p.charAt(j)) {
				i++;
				j++;

				if (j == p.length()) {

					j =y[j-1];
					count++;

				}

			} else {

				if (j == 0)
					i++;
				else
					j = y[j-1];

			}

		}
		System.out.println(count);

	}	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String ss = in.nextLine();
		String s = in.nextLine();

		func(ss, s);

	}

}
