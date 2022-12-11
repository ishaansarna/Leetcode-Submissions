class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        // int res = *max_element(nums.begin(), nums.end());
        int res = INT_MIN;
        int cmax = 1;
        int cmin = 1;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                cmax = 1;
                cmin = 1;
            }
            int tmp = cmax;
            cmax = max(nums[i], max(cmax*nums[i], cmin*nums[i]));
            cmin = min(nums[i], min(tmp*nums[i], cmin*nums[i]));
            res = max(res, cmax);
        }        
        return res;
    }
};