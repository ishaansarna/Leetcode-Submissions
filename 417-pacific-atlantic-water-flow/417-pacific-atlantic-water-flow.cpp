class Solution {
    void recursion (const vector<vector<int>>& heights, vector<vector<int>>& reachable,
                   int m, int n, int i, int j, int curr_height) {
        if (i >= m || j >= n || i < 0 || j < 0) 
            return;
        if (heights[i][j] < curr_height || reachable[i][j])
            return;
        reachable[i][j] = 1;
        recursion (heights, reachable, m, n, i-1, j, heights[i][j]);
        recursion (heights, reachable, m, n, i+1, j, heights[i][j]);
        recursion (heights, reachable, m, n, i, j-1, heights[i][j]);
        recursion (heights, reachable, m, n, i, j+1, heights[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); int n = heights[0].size();
        vector<vector<int>> pacific (m, vector<int> (n, 0));
        vector<vector<int>> atlantic (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            recursion (heights, pacific, m, n, i, 0, 0);
            recursion (heights, atlantic, m, n, i, n-1, 0);
        }
        for (int j = 0; j < n; j++) {
            recursion (heights, pacific, m, n, 0, j, 0);
            recursion (heights, atlantic, m, n, m-1, j, 0);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (atlantic[i][j] && pacific[i][j])
                    ans.push_back(vector<int> {i, j});
        return ans;
    }
};