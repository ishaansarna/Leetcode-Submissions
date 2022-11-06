class Solution {
    bool is_valid(vector<int>& v, vector<int>& target) {
        for (int i = 0; i < 3; i++) 
            if (v[i] > target[i])
                return false;
        return true;
    }
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> valid_triplets;
        vector<int> res (3, 0);
        for (auto i : triplets) 
            if (is_valid(i, target))
                valid_triplets.push_back(i);
        for (auto v : valid_triplets) 
            for (int i = 0; i < 3; i++) 
                if (v[i] == target[i])
                    res[i] = 1;
        for (int i = 0; i < 3; i++) 
            if (res[i] == 0)
                return false;
        return true;
    }
};