class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != 'O')
            return;
        board[i][j] = 'S';
        dfs(board, visited, i+1, j, m, n);
        dfs(board, visited, i-1, j, m, n);
        dfs(board, visited, i, j+1, m, n);
        dfs(board, visited, i, j-1, m, n);
    }
public:
    void solve(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();
        if (m == 1 || n == 1)
            return;
        vector<vector<int>> visited (m, vector<int> (n, 0));
        for (int i = 0; i < m; i+=m-1) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    dfs(board, visited, i, j, m, n);
            }
        }
        for (int i = 0; i < n; i+=n-1) {
            for (int j = 0; j < m; j++) {
                if (board[j][i] == 'O')
                    dfs(board, visited, j, i, m, n);
            }
        }
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        return;
    }
};