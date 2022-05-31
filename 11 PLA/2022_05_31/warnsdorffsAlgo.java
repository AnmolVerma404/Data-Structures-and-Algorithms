import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Map;

public class warnsdorffsAlgo {
    public static void main(String[] args) {
        int n = 8;
        int[][] board = new int[8][8];
        nKnights(board);
    }

    public static void nKnights(int[][] board) {
        // ArrayList<Map.Entry<Integer, Integer>> pq = { { 1, 2 }, { 1, -2 }, { 2, 1 }, { 2, -1 }, { -1, 2 }, { -1, -2 },
        //         { -2, 1 }, { -2, -1 } };
        int[] x = { 1, 1, 2, 2, -1, -1, -2, -2 };
        int[] y = { 2, -2, 1, -1, 2, -2, 1, -1 };
        int r = 0, c = 0;
        int n = board.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = -1;
            }
        }
        int i = 0;
        board[0][0] = 0;
        int count = 0;
        while (count!=n*n) {
            for (int p = 0; p < x.length; p++) {
                int k = x[p], v = y[p];
                if (r + k < n && c + v < n && board[r + k][c + v] == -1) {
                    board[r + k][c + v] = i++;
                    r = r+k;
                    c = c + v;
                    count++;
                    System.out.println(1);
                    break;
                }
            }
        }
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                System.out.print(board[a][b] + " ");
            }
            System.out.println();
        }
    }
}
