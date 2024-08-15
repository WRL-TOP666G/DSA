class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int res = 0;

        for(int i=0; i<m-2; i++)
            for(int j=0; j<n-2; j++)
                if(isValid(i, j, grid))
                    res++;

        return res;
    }

    private boolean isValid(int i, int j, int[][] grid){
        int[] unique_number = new int[10];
        for(int ii=0; ii<3; ii++)
            for(int jj=0; jj<3; jj++){
                int num = grid[i+ii][j+jj];
                if(num>9 || num<1) return false;
                unique_number[num]++;
                if(unique_number[num] > 1) return false;
            }

        int sum = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        for(int ii=0; ii<3; ii++)
            if(sum != grid[i+ii][j] + grid[i+ii][j+1] + grid[i+ii][j+2])
                return false;

        for(int jj=0; jj<3; jj++)
            if(sum != grid[i][j+jj] + grid[i+1][j+jj] + grid[i+2][j+jj])
                return false;
        
        if(sum != grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]) return false;
        if(sum != grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2]) return false;

        return true;
    }
}

// TC: O(m * n)
// SC: O(1)
