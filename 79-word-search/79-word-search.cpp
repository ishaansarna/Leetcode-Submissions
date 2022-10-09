class Solution {
    bool bt(vector<vector<char>>& board, string word, 
            vector<vector<bool>>& visited, int& cnt, int i, int j) {
        if (!(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()))
            return false;
        if (!visited[i][j] && board[i][j] == word[cnt]) {
            if (cnt == word.length()-1)
                return true;
            visited[i][j] = true;
            cnt++;
            if (bt(board, word, visited, cnt, i-1, j))
                return true;
            if (bt(board, word, visited, cnt, i+1, j))
                return true;
            if (bt(board, word, visited, cnt, i, j-1))
                return true;
            if (bt(board, word, visited, cnt, i, j+1))
                return true;
            visited[i][j] = false;
            cnt--;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                int cnt = 0;
                if (bt(board, word, visited, cnt, i, j))
                    return true;
            }
        return false;
    }
};