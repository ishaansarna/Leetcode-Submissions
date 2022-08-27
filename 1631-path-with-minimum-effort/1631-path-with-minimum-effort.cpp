class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int nrows = heights.size();
        int ncols = heights.at(0).size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> dp(nrows, vector<int> (ncols, INT_MAX));
        vector<vector<int>> visited(nrows, vector<int> (ncols, 0));
        dp.at(0).at(0) = 0;
        int i=0, j=0, e=0;
        st.insert(make_pair(0, make_pair(0, 0)));
        while (!st.empty()) {
            auto p = *st.begin();
            st.erase(st.begin());
            i = p.second.first;
            j = p.second.second;
            e = p.first;
            if (visited.at(i).at(j) == 1)
                continue;
            visited.at(i).at(j) = 1;
            if (i == nrows-1 && j == ncols-1)
                return e;
            if (j > 0) {
                int effort = abs(heights.at(i).at(j) - heights.at(i).at(j-1));
                effort = max(dp.at(i).at(j), effort);
                if (effort < dp.at(i).at(j-1)) {
                    dp.at(i).at(j-1) = effort;
                    st.insert(make_pair(effort, make_pair(i, j-1)));
                }
            }
            if (j < ncols-1) {
                int effort = abs(heights.at(i).at(j) - heights.at(i).at(j+1));
                effort = max(dp.at(i).at(j), effort);
                if (effort < dp.at(i).at(j+1)) {
                    dp.at(i).at(j+1) = effort;
                    st.insert(make_pair(effort, make_pair(i, j+1)));
                }
            }
            if (i > 0) {
                int effort = abs(heights.at(i).at(j) - heights.at(i-1).at(j));
                effort = max(dp.at(i).at(j), effort);
                if (effort < dp.at(i-1).at(j)) {
                    dp.at(i-1).at(j) = effort;
                    st.insert(make_pair(effort, make_pair(i-1, j)));
                }
            }
            if (i < nrows-1) {
                int effort = abs(heights.at(i).at(j) - heights.at(i+1).at(j));
                effort = max(dp.at(i).at(j), effort);
                if (effort < dp.at(i+1).at(j)) {
                    dp.at(i+1).at(j) = effort;
                    st.insert(make_pair(effort, make_pair(i+1, j)));
                }
            }
        }
        return dp.at(nrows-1).at(ncols-1);
    }
};