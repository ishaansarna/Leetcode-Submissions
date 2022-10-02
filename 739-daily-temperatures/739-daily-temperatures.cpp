class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans (n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures.at(i) > st.top().first) {
                auto p = st.top();
                ans.at(p.second) = i - p.second;
                st.pop();
            }
            st.push(make_pair(temperatures.at(i), i));
        }
        return ans;
    }
};