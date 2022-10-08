class Solution {
    int sum, target;
    vector<int> cands;
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates) {
        sum = accumulate(cands.begin(), cands.end(), 0);
        if (sum == target) {
            // sort(cands.begin(), cands.end());
            ans.push_back(cands);
        }
        for (int c : candidates) {
            sum = accumulate(cands.begin(), cands.end(), 0);
            // if (cands.size() == 0 && c == 3)
            //     cout << "hi\n";
            // if (c == 3)
            //     cout << "yo";
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
        for (int i = 0; i<ans.size(); i++)
            sort(ans[i].begin(), ans[i].end());
        set<vector<int>> res;
        for (auto i : ans)
            res.insert(i);
        return vector<vector<int>> (res.begin(), res.end());
    }
};