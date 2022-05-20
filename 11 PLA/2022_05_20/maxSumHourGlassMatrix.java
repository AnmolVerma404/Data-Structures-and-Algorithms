public class maxSumHourGlassMatrix {
    public static void main(String[] args) {
        int[][] matrix = { { 1, 1, 1, 0, 0 },
                { 0, 1, 0, 0, 0 },
                { 1, 1, 1, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
        };
        int r = matrix.length;
        int c = matrix[0].length;
        maxSum(matrix);
    }

    public static void bruteForce(int[][] m){
        if()
    }

    public static void maxSum(int[][] m) {
        int row = m.length;
        int col = m[0].length;
        int[][] c = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 }, { 2, 0 }, { 2, 1 }, { 2, 2 } };
        int mx = 0;
        int i = 0, j = 0;
        while (true) {
            int currSum = 0;
            for (int k = 0; k < c.length; k++) {
                if (c[k][0] < row || c[k][1] < col) {
                    currSum += m[i + c[k][0]][j + c[k][1]];
                    mx = Math.max(mx, currSum);
                } else {
                    break;
                }
            }
            if (i >= row) {
                
            } 
            if(j>=col){

            }
        }
    }
}
