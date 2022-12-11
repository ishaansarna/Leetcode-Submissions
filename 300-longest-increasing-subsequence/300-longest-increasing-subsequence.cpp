class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        vector<int> dp (nums.size(), 1);
        int ans = 0;
        for (int i = nums.size()-2; i >= 0; i--) {
            int dpi = dp[i];
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i]<nums[j])
                    dp[i] = max(dpi+dp[j], dp[i]);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};