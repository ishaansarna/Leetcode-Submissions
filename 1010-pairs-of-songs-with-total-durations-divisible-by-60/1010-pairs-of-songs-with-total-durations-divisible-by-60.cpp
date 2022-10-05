class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rems(60, 0);
        long long ans = 0;
        for (auto t : time) {
            rems[t%60]++;
        }
        for (auto t : time) {
            t = t%60;
            if (t != 30 && t != 0) {
                ans += rems[60-t];
            }
            else {
                ans += rems[t]-1;
            }
        }
        return ans/2;
    }
};