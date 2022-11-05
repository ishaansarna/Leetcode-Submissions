class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, l = 0, r = 0;
        int n = nums.size();
        while (r < n-1) {
            int last = r+1;
            for (int i = l; i <= r; i++) {
                last = max(last, i + nums[i]);
            }
            l = r+1;
            r = last;
            ans++;
        }
        return ans;
    }
};