class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k = k-1;
        set<pair<int, int>> st;
        st.insert(make_pair(0, k));
        vector<vector<pair<int, int>>> children(n); 
        for (vector<int> v : times)
            children.at(v.at(0)-1).push_back(make_pair(v.at(2), v.at(1)-1));
        vector<int> visited(n, 0);
        vector<int> dist(n, INT_MAX);
        dist.at(k) = 0;
        while (!st.empty()) {
            pair<int, int> p = *st.begin();
            st.erase(st.begin());
            int node = p.second;
            int d = p.first;
            if (visited.at(node) == 1) 
                continue;
            visited.at(node) = 1;
            for (pair<int, int> c : children.at(node)) {
                int newd = d+c.first;
                if (newd < dist.at(c.second)) 
                    dist.at(c.second) = newd;
                st.insert(make_pair(newd, c.second));
            }
        }
        if (count(visited.begin(), visited.end(), 0))
            return -1;
        return *max_element(dist.begin(), dist.end());
    }
};