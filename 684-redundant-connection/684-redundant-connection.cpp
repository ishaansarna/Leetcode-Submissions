class Solution {
    int find(int x, vector<int>& root) {
        if (x == root[x])
            return x;
        return root[x] = find(root[x], root);
    }
    void union_ (int u, int v, vector<int>& root, vector<int>& rank) {
        int rootu = find(u, root);
        int rootv = find(v, root);
        if (rootu == rootv) return;
        if (rank[rootu] > rank[rootv])
            root[rootv] = root[rootu];
        else if (rank[rootu] < rank[rootv])
            root[rootu] = root[rootv];
        else {
            rank[rootv]++;
            root[rootu] = root[rootv];
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root (n, 0);
        for (int i = 0; i < n; i++)
            root[i] = i;
        vector<int> rank (n, 1);
        for (auto edge : edges) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            if (find(u, root) == find(v, root))
                return edge;
            union_(u, v, root, rank);
        }
        return vector<int> ();
    }
};