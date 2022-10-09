class Solution {
    void backtrack(vector<int>& candidates, int target, vector<int>& curr, 
                   vector<vector<int>>& ans, int index, int& sum) {
        if (sum == target) {
            // vector<int> c (curr);
            // sort(c.begin(), c.end());
            ans.push_back(curr);
            return;
        }
        if (index >= candidates.size()) 
            return;
        int prev = -1;
        for (int i = index; i < candidates.size(); i++) {
            if (prev != candidates.at(i) && sum + candidates.at(i) <= target) {
                sum += candidates.at(i);
                curr.push_back(candidates.at(i));
                backtrack(candidates, target, curr, ans, i+1, sum);
                curr.pop_back();
                sum -= candidates.at(i);
                prev = candidates.at(i);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr; 
        vector<vector<int>> ans;
        int index = 0;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, curr, ans, index, sum);
        return ans;
    }
};