class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& nums, int i) {
        ans.push_back(curr);
        for (int j = i+1; j < nums.size(); j++) {
            curr.push_back(nums.at(j));
            backtrack(nums, j);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, -1);
        return ans;
    }
};