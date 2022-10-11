class Solution {
    int nc, nr;
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int ans = 0;
        visited[i][j] = 1;
        ans = 1;
        if (j-1 >= 0 && grid[i][j-1] == 1 && visited[i][j-1] == 0) {
            ans += dfs(grid, visited, i, j-1);
        }
        if (i-1 >= 0 && grid[i-1][j] == 1 && visited[i-1][j] == 0) {
            ans += dfs(grid, visited, i-1, j);
        }
        if (j+1 < nc && grid[i][j+1] == 1 && visited[i][j+1] == 0) {
            ans += dfs(grid, visited, i, j+1);
        }
        if (i+1 < nr && grid[i+1][j] == 1 && visited[i+1][j] == 0) {
            ans += dfs(grid, visited, i+1, j);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        nc = grid[0].size();
        nr = grid.size();
        int ans = 0;
        vector<vector<int>> visited(nr, vector<int> (nc, 0));
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
        }
        return ans;
    }
};