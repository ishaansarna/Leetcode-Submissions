class Solution {
    vector<int> root;
    vector<int> rank;
    int find(int x) {
        if (x == root.at(x)) 
            return x;
        return root.at(x) = find(root.at(x));
    }
    int unio(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        // if (rootx == rooty) 
        //     return -1;
        if (rank[rootx] > rank[rooty])
            root[rooty] = rootx;
        else if (rank[rooty] > rank[rootx])
            root[rootx] = rooty;
        else {
            root[rooty] = rootx;
            rank[rootx] += 1;
        }
        return 1;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        root.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i<n; ++i)
            root.at(i) = i;
        if (n != edges.size()+1)
            return false;
        for (int i = 0; i<edges.size(); ++i) {
            int res = unio(edges.at(i).at(0), edges.at(i).at(1));
            if (res == -1)
                return false;
        }
        int r = find(0);
        for (int x : root) 
            if (find(x) != r) 
                return false;
        return true;
    }
};