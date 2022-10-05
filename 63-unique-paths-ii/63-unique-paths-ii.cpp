class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nc = obstacleGrid[0].size();
        int nr = obstacleGrid.size();
        vector<vector<long long>> dp(nr, vector<long long> (nc, 0));
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) 
                    dp[i][j] = 1;
                else if (obstacleGrid[i][j] == 1) 
                    dp[i][j] = 0;
                else {
                    if (j > 0) 
                        dp[i][j] += dp[i][j-1];
                    if (i > 0)
                        dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[nr-1][nc-1];
    }
};