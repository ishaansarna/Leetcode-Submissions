class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1), s(n, 1);
        p.at(0) = nums.at(0); s.at(n-1) = nums.at(n-1);
        vector<int> ans(n);
        
        for (int i = 1; i < n; i++) 
            p.at(i) *= nums.at(i)*p.at(i-1);
        for (int i = n-2; i >= 0; i--) 
            s.at(i) *= nums.at(i)*s.at(i+1);

        for (int i = 0; i < n; i++) 
            ans.at(i) = (i-1 >= 0 ? p.at(i-1) : 1)*(i+1 < n ? s.at(i+1) : 1);
        
        return ans;
    }
};