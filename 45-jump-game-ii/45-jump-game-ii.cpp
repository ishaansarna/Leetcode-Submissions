class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> v (n, INT_MAX);
        v[0] = 0;
        for (int i = 0; i < n; i++) {
            int j = 1;
            while (i+j < n && j <= nums[i]) {
                v[i+j] = min(v[i+j], v[i] + 1);
                j++;
            }
        }
        return v[n-1];
    }
};