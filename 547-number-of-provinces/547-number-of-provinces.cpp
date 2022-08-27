class Solution {
    vector<int> root;
    vector<int> rank;
    void unio (int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        if (rank[rootx] > rank[rooty])
            root[rooty] = rootx;
        else if (rank[rootx] < rank[rooty])
            root[rootx] = rooty;
        else {
            root[rootx] = rooty;
            rank[rooty] += 1;
        }
    }
    int find(int x) {
        if (x == root.at(x))
            return x;
        return root.at(x) = find(root.at(x));
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        root.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) 
            root[i] = i;
        for (int i = 0; i<n; i++) 
            for (int j = 0; j < n; j++) 
                if (isConnected.at(i).at(j) == 1)
                    unio(i, j);
        set<int> roots;
        for (int i = 0; i < n; i++) 
            roots.insert(find(i));
        return roots.size();
    }
};