class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependents (n, vector<int> ());
        vector<int> indeg (n, 0);
        int done = 0;
        for (auto v : prerequisites) {
            dependents.at(v.at(1)).push_back(v.at(0));
            indeg.at(v.at(0))++;
        }
        stack<int> zerodeg;
        for (int i = 0; i < n; i++) 
            if (indeg.at(i) == 0)
                zerodeg.push(i);
        while (!zerodeg.empty()) {
            int i = zerodeg.top();
            zerodeg.pop();
            done++;
            for (auto j : dependents.at(i)) {
                indeg.at(j)--;
                if (indeg.at(j) == 0)
                    zerodeg.push(j);
            }
        }
        return done == n;
    }
};