class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int expected = (n*(n+1))/2;
        return expected-sum;
    }
};