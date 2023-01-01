class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target%2 == 1) return false;
        target /= 2;
        set<int> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); i++) {
            vector<int> v;
            for (int sum : sums){
                if (sum + nums[i] == target)
                    return true;
                if (sum + nums[i] <= target) 
                    v.push_back(sum + nums[i]);
            }
            for (int j : v)
                sums.insert(j);
        }
        return false;
    }
};