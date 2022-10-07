class Solution {
    int dist(int X, int Y) {
        long long x = X;
        long long y = Y;
        cout << x << " " << y << " " << sqrt(pow(x, 2) + pow(y, 2)) << endl;
        return (sqrt(pow(x, 2) + pow(y, 2)));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> a, vector<int> b) {
            return sqrt(pow(a[0], 2) + pow(a[1], 2)) > sqrt(pow(b[0], 2) + pow(b[1], 2));
        };
        multiset<vector<int>, decltype(cmp)> s(cmp);
        for (auto p : points) {
            s.insert(p);
            if (s.size() > k)
                s.erase(s.begin());
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};