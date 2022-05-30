public class mazeSolving {
    public static void main(String[] args) {
        // int[][] matrix = { { 1, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 1, 1, 1 }, { 0, 1, 1, 1 } };
        int[][] matrix = { { 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 1, 1, 1, 1 }, { 0, 0, 1, 1 } };
        maze(matrix, "", 0, 0);
        System.out.println(mazePath(matrix, 0, 0));
    }

    public static void maze(int[][] matrix, String t, int i, int j) {
        if (i == matrix.length - 1 && j == matrix[0].length - 1 && matrix[i][j] == 1) {
            System.out.println(t);
            return;
        }
        if (matrix[i][j] == 0) {
            return;
        }
        if (i + 1 < matrix.length && matrix[i + 1][j] == 1) {
            maze(matrix, t + "D", i + 1, j);
        }
        if (j + 1 < matrix[0].length && matrix[i][j + 1] == 1) {
            maze(matrix, t + "R", i, j + 1);
        }
    }

    public static int mazePath(int[][] matrix, int i, int j) {
        if (i == matrix.length - 1 && j == matrix[0].length - 1 && matrix[i][j] == 1) {
            return 1;
        }
        if (matrix[i][j] == 0) {
            return 0;
        }
        int count = 0;
        if (i + 1 < matrix.length && matrix[i + 1][j] == 1) {
            count += mazePath(matrix, i + 1, j);
        }
        if (j + 1 < matrix[0].length && matrix[i][j + 1] == 1) {
            count += mazePath(matrix, i, j + 1);
        }
        return count;
    }
}
