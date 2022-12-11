class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto len_s = s.size();
        vector<bool> dp (len_s+1, false);
        dp.back() = true;
        for (int i = len_s-1; i>=0; i--) {
            for (string word : wordDict) {
                if (!dp[i] && i+word.size() <= len_s && s.substr(i, word.size()) == word) {
                    dp[i] = dp[i + word.size()];
                }
            }
        }
        return dp[0];
    }
};