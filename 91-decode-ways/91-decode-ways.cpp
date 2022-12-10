class Solution {
    map<int, int> dp;
    int help(string s, int i) {
        int ans = 0;
        if (dp.find(i) != dp.end())
            return dp[i];
        if (s[i] == '0')
            return 0;
        if (s[i] > '0' && s[i] <= '9') {
            ans += help(s, i+1);
            if (i < s.size()-1 && (s[i] == '1' || 
                                   (s[i] == '2' && s[i+1] < '7'))) {
                ans += help(s, i+2);
            }
        }
        dp[i] = ans;
        return ans;
    }
public:
    int numDecodings(string s) {
        dp.clear();
        dp[s.size()] = 1;
        int ans = help(s, 0);
        return ans;
    }
};