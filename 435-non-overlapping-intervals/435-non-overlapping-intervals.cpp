class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return 0;
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int prevEnd = intervals[0][1];
        for (auto it = intervals.begin()+1; it != intervals.end(); it++) {
            if ((*it)[0] >= prevEnd) {
                prevEnd = (*it)[1];
            }
            else {
                prevEnd = (*it)[1] < prevEnd ? (*it)[1] : prevEnd;
                ans++;
            }
        }
        return ans;
    }
};