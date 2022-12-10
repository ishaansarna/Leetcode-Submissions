class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        if (intervals.empty() || newInterval[0] > intervals.back()[1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        while (i < intervals.size()) {
            // if (newInterval[1] < intervals[i][0]) {
            //     intervals.insert(intervals.begin()+i, newInterval);
            //     return intervals;
            // }
            if ((newInterval[0] >= intervals[i][0] 
                 && newInterval[0] <= intervals[i][1]) || 
                (newInterval[1] >= intervals[i][0] 
                 && newInterval[0] <= intervals[i][1])) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
                if (i == intervals.size()) 
                    ans.push_back(newInterval);
            }
            else if ((ans.empty() || 
                     newInterval[0] > ans.back()[1]) && 
                     (i < intervals.size() 
                    && newInterval[1] < intervals[i][0])) {
                ans.push_back(newInterval);
            }
            else {
                ans.push_back(intervals[i]);
                i++;
            }
        }
        
        return ans;
    }
};