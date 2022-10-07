class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [this](vector<int> a, vector<int> b) {
            return sqrt(pow(a[0], 2) + pow(a[1], 2)) < sqrt(pow(b[0], 2) + pow(b[1], 2));
        };
        multiset<vector<int>, decltype(cmp)> s(cmp);
        for (auto p : points) {
            s.insert(p);
        }
        int i = 0;
        vector<vector<int>> ans;
        for (auto it = s.begin(); i < k; it++, i++) {
            ans.push_back(*it);
        }
        // for (auto x : s)
        //     cout << x[0] << " " << x[1] << "\t";
        return ans;
    }
};