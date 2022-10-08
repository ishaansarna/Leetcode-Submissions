class Solution {
    int sum, target;
    vector<int> cands;
    set<vector<int>> ans;
    void backtrack(vector<int>& candidates) {
        sum = accumulate(cands.begin(), cands.end(), 0);
        if (sum == target) {
            vector<int> x (cands);
            sort(x.begin(), x.end());
            ans.insert(x);
        }
        for (int c : candidates) {
            sum = accumulate(cands.begin(), cands.end(), 0);
            if (c + sum <= target) {
                cands.push_back(c);
                backtrack(candidates);
                cands.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        this->target = target;
        backtrack(candidates);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};