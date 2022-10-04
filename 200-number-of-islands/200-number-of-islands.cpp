class Solution {
    int nc, nr;
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        if (visited[i][j] == 1)
            return;
        visited[i][j] = 1;
        if (j-1 >= 0 && grid[i][j-1] == '1') {
            dfs(grid, visited, i, j-1);
        }
        if (i-1 >= 0 && grid[i-1][j] == '1') {
            dfs(grid, visited, i-1, j);
        }
        if (j+1 < nc && grid[i][j+1] == '1') {
            dfs(grid, visited, i, j+1);
        }
        if (i+1 < nr && grid[i+1][j] == '1') {
            dfs(grid, visited, i+1, j);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        nc = grid[0].size();
        nr = grid.size();
        int ans = 0;
        vector<vector<int>> visited(nr, vector<int> (nc, 0));
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    ans++;
                    dfs(grid, visited, i, j);
                }
                // if (grid[i][j] == '1') {
                // }
                // visited[i][j] = 1;
                
            }
        }
        return ans;
    }
};