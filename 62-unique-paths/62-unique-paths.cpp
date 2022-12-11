class Solution {
    // void dp(vector<vector<int>>& mat, int ways, int i, int j, int m, int n) {
    //     if (!(i < m && j < n))
    //         return;
    //     mat[i][j] += ways;
    //     dp(mat, mat[i][j], i+1, j, m, n);
    //     dp(mat, mat[i][j], i, j+1, m, n);
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat (m, vector<int>(n, 0));
        mat[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i>0) 
                    mat[i][j] += mat[i-1][j];
                if (j>0)
                    mat[i][j] += mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};