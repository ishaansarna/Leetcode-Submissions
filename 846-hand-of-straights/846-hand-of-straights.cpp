class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupsize) {
        int n = hand.size();
        if (remainder(n, groupsize) != 0)
            return false;
        if (groupsize == 1)
            return true;
        int ngrps = n / groupsize;
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int, int> m;
        for (int i : hand) {
            pq.push(i);
            if (m.find(i) == m.end())
                m[i] = 1;
            else
                m[i]++;
        }
        for (int i = 0; i < ngrps; i++) {
            int x;
            while (m[pq.top()] == 0) {
                pq.pop();
            }
            x = pq.top();
            pq.pop();
            m[x]--;
            for (int j = 1; j < groupsize; j++) {
                if (m.find(x+j) == m.end() || m[x+j] < 1)
                    return false;
                else
                    m[x+j]--;
            }
        }
        return true;
    }
};