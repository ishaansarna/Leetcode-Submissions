class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2);
        vector<vector<pair<int, int>>> fs(n);
        for (int i = 0; i < k+2; ++i) 
            for (int j = 0; j < n; ++j)
                dp.at(i).push_back(INT_MAX);
        dp.at(0).at(src) = 0;
        for (auto v : flights) {
            fs.at(v.at(0)).push_back(make_pair(v.at(1), v.at(2)));
        }
        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < n; j++) {
                if (dp.at(i).at(j) == INT_MAX)
                    continue;
                if (dp.at(i).at(j) < dp.at(i+1).at(j))
                    dp.at(i+1).at(j) = dp.at(i).at(j);
                for (auto p : fs.at(j)) {
                    if (dp.at(i+1).at(p.first) > dp.at(i).at(j) + p.second)
                        dp.at(i+1).at(p.first) = dp.at(i).at(j) + p.second;
                }
            }
        }
        if (dp.at(k+1).at(dst) != INT_MAX)
            return dp.at(k+1).at(dst);
        return -1;
    }
};