class Solution {
    void backtrack(set<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int index) {
        ans.insert(curr);
        if (index >= nums.size())
            return;
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums.at(i));
            backtrack(ans, nums, curr, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(ans, nums, curr, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};