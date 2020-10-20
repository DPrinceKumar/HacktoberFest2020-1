import java.util.Scanner;

public class Main {
    static int[][] board = new int[9][9];
    static int[][] matrix = new int[3][3];
    static int[] row = new int[9];
    static int[] col = new int[9];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                put(i, j, scanner.nextInt());
        scanner.close();
        solve(0, 0);
    }

    static void display() {
        System.out.println();
        for (int[] row : board) {
            for (int ele : row)
                System.out.print(ele + " ");
            System.out.println();
        }
        System.out.println();
    }

    static void solve(int i, int j) {
        if (i == 9) {
            display();
            return;
        }
        int ni;
        int nj;
        if (j == 8) {
            ni = i + 1;
            nj = 0;
        } else {
            ni = i;
            nj = j + 1;
        }
        if (board[i][j] != 0)
            solve(ni, nj);
        else
            for (int o = 1; o <= 9; o++)
                if (possible(i, j, o)) {
                    put(i, j, o);
                    solve(ni, nj);
                    remove(i, j, o);
                }
    }

    static boolean possible(int i, int j, int o) {
        return !bit(row[i], o) && !bit(col[j], o) && !bit(matrix[i / 3][j / 3], o);
    }

    static void put(int i, int j, int o) {
        board[i][j] = o;
        row[i] = set(row[i], o);
        col[j] = set(col[j], o);
        matrix[i / 3][j / 3] = set(matrix[i / 3][j / 3], o);
    }

    static void remove(int i, int j, int o) {
        board[i][j] = 0;
        row[i] = unset(row[i], o);
        col[j] = unset(col[j], o);
        matrix[i / 3][j / 3] = unset(matrix[i / 3][j / 3], o);
    }

    static boolean bit(int num, int bit) {
        return (num & (1 << bit)) > 0;
    }

    static int set(int num, int bit) {
        return (num | (1 << bit));
    }

    static int unset(int num, int bit) {
        return (num & ~(1 << bit));
    }
}