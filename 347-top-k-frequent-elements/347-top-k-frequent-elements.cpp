class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        set<pair<int, int>> s;
        vector<int> ans;
        for (int num : nums) {
            m[num]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) 
            s.insert(make_pair((*it).second, (*it).first));
        
        int i = 0;
        for (auto it = s.rbegin(); it != s.rend() && i < k; it++, i++)
            ans.push_back(it->second);
        return ans;
    }
};