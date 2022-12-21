class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= n; i++) 
            ans ^= i;
        for (int i : nums)
            ans ^= i;
        return ans;
    }
};