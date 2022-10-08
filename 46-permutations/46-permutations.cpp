class Solution {
    void permute(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, map<int, int>& m) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == 0) {
                m[nums[i]] = 1;
                curr.push_back(nums[i]);
                permute(ans, nums, curr, m);
                curr.pop_back();
                m[nums[i]] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, int> m;
        for (int i : nums)
            m[i] = 0;
        vector<vector<int>> ans;
        vector<int> curr;
        permute(ans, nums, curr, m);
        return ans;
    }
};