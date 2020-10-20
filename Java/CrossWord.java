import java.io.*;
import java.util.*;

public class Main {
    static char[][] arr = new char[10][10];
    static String[] words;
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        for (int i = 0; i < 10; i++)
        	for (int j = 0; j < 10; j++)
            	arr[i][j] = scn.nextChar();
        int n = scn.nextInt();
        words = new String[n];
        for (int i = 0; i < n; i++)
            words[i] = scn.next();
        solution(0);
    }
    static void solution(int vidx) {
        if (vidx == words.length()) {
            print();
            return;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (canPlaceHorizontally(i, j, words[vidx])) {
                    placeHorizontally(i, j, words[vidx]);
                    solution(vidx + 1);
                    removeHorizontally(i, j, words[vidx]);
                }
                if (canPlaceVertically(i, j, words[vidx])) {
                    placeVertically(i, j, words[vidx]);
                    solution(vidx + 1);
                    removeVertically(i, j, words[vidx]);
                }
            }
        }

    }
    static boolean canPlaceHorizontally(int i, int j, String word) {
        int n = word.length();
        if (i < 0 || j < 0 || i == 10 || j == 10 || j + n - 1 >= 10)
            return false;
        if (j - 1 >= 0 && arr[i][j - 1] != '+')
            return false;
        if (j + n < 10 && arr[i][j + n] != '+')
            return false;
        for (int c = 0; c < n; c++)
            if (!(arr[i][j + c] == '-' || arr[i][j + c] == word.charAt(c)))
                return false;
        return true;
    }
    static void placeHorizontally(int i, int j, String word) {
        int n = word.length();
        for (int c = 0; c < n; c++)
            arr[i][j + c] = word.charAt(c);
    }
    static void removeHorizontally(int i, int j, String word) {
        int n = word.length();
        for (int c = 0; c < n; c++)
            if ((i - 1 < 0 || arr[i - 1][j + c] == '+') && (i + 1 >= 10 || arr[i + 1][j + c] == '+'))
                arr[i][j + c] = '-';
    }
    static boolean canPlaceVertically(int i, int j, String word) {
        int n = word.length();
        if (i < 0 || j < 0 || i == 10 || j == 10 || i + n - 1 >= 10)
            return false;
        if (i - 1 >= 0 && arr[i - 1][j] != '+')
            return false;
        if (i + n < 10 && arr[i + n][j] != '+')
            return false;
        for (int c = 0; c < n; c++)
            if (!(arr[i + c][j] == '-' || arr[i + c][j] == word.charAt(c)))
                return false;
        return true;
    }
    static void placeVertically(int i, int j, String word) {
        int n = word.length();
        for (int c = 0; c < n; c++)
            arr[i + c][j] = word.charAt(c);
    }
    static void removeVertically(int i, int j, String word) {
        int n = word.length();
        for (int c = 0; c < n; c++)
            if ((j - 1 < 0 || arr[i + c][j - 1] == '+') && (j + 1 >= 10 || arr[i + c][j + 1] == '+'))
                arr[i + c][j] = '-';
    }
    static void print() {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++)
                System.out.print(arr[i][j]);
            System.out.println();
        }
		System.out.println();
    }
}
