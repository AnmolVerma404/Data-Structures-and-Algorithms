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

    static int findMaxSum(int [][]mat)
{
    if (R < 3 || C < 3)
        return -1;
 
    // Here loop runs (R-2)*(C-2)
    // times considering different
    // top left cells of hour glasses.
    int max_sum = Integer.MIN_VALUE;
    for (int i = 0; i < R - 2; i++)
    {
        for (int j = 0; j < C - 2; j++)
        {
            // Considering mat[i][j] as top
            // left cell of hour glass.
            int sum = (mat[i][j] + mat[i][j + 1] +
                       mat[i][j + 2]) + (mat[i + 1][j + 1]) +
                       (mat[i + 2][j] + mat[i + 2][j + 1] +
                       mat[i + 2][j + 2]);
 
            // If previous sum is less then
            // current sum then update
            // new sum in max_sum
            max_sum = Math.max(max_sum, sum);
        }
    }
    return max_sum;
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
