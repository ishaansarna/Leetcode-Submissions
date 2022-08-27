class Solution {
    vector<int> root;
    vector<int> rank;
    int find(int x) {
        if (x == root.at(x)) 
            return x;
        return root.at(x) = find(root.at(x));
    }
    void unio(int x, int y) {
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
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        root.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i<n; ++i)
            root.at(i) = i;
        for (int i = 0; i<edges.size(); ++i) {
            unio(edges.at(i).at(0), edges.at(i).at(1));
        }
        set<int> roots;
        for (int i = 0; i < n; i++) 
            roots.insert(find(i));
        return roots.size();
    }
};