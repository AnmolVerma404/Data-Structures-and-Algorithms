public class nQueens {
    public static void main(String[] args) {
        int n = 8;
        boolean[][] board = new boolean[n][n];
        System.out.println(queens(board, 0));
    }

    public static int queens(boolean[][] board, int row) {
        if (row == board.length) {
            display(board);
            System.out.println();
            return 1;
        }
        int count = 0;
        for (int col = 0; col < board.length; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = true;
                count += queens(board, row + 1);
                board[row][col] = false;
            }
        }
        return count;
    }

    public static boolean isSafe(boolean[][] board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col]) {
                return false;
            }
        }
        int mxl = Math.min(row, col);
        for (int i = 1; i <= mxl; i++) {
            if (board[row - i][col - i]) {
                return false;
            }
        }
        int mxr = Math.min(row, board.length - col - 1);
        for (int i = 1; i <= mxr; i++) {
            if (board[row - i][col + i]) {
                return false;
            }
        }
        return true;
    }

    public static void display(boolean[][] board) {
        for (boolean[] row : board) {
            for (boolean item : row) {
                if (item) {
                    System.out.print("Q ");
                } else {
                    System.out.print("- ");
                }
            }
            System.out.println();
        }
    }
}
