class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> psum;
        psum.push_back(0);
        for (int i = 0; i<nums.size(); i++) {
            psum.push_back(psum.at(i) + nums.at(i));
        }
        int l = 0;
        int r = 1;
        int ans = INT_MAX;
        
        while (l < psum.size() && r < psum.size()) {
            if (psum.at(r) - psum.at(l) >= target) {
                ans = min(ans, r-l);
                l++;
            }
            else {
                r++;
            }
        }
        
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};