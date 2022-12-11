class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto interval : intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            if (pq.empty() || pq.top() > interval[0]) {
                pq.push(interval[1]);
                ans = max(ans, (int)pq.size());
            }
        }
        return ans;
    }
};