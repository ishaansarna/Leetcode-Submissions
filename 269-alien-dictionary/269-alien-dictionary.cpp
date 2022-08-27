class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        string ans;
        vector<int> indeg(26, -1);
        vector<set<int>> adj(26);
        vector<int> pres(26, 0);
        
        if (n == 1){
            for (char c : words.at(0)) {
                if (pres.at(c-'a') == 0)
                    ans.push_back(c);
                pres.at(c-'a')++;
            }
            return ans;
        }
        
        for (int i = 0; i < n-1; ++i) {
            int minsize = min(words.at(i).size(), words.at(i+1).size());
            int maxsize = max(words.at(i).size(), words.at(i+1).size());
            int k = words.at(i).size() > words.at(i+1).size() ? i : i+1;
            int j, flag = 1;
            for (j = 0; j < minsize; ++j) {
                char c1 = words.at(i).at(j);
                char c2 = words.at(i+1).at(j);
                if (pres.at(c1-'a') == 0) 
                    indeg.at(c1-'a') = 0;
                if (pres.at(c2-'a') == 0) 
                    indeg.at(c2-'a') = 0;
                pres.at(c1-'a') = pres.at(c2-'a') = 1;
                if (c1 != c2 && flag) {
                    if (adj.at(c1-'a').find(c2-'a') == adj.at(c1-'a').end()) {
                        indeg.at(c2-'a')++;
                        adj.at(c1-'a').insert(c2-'a');
                    }
                    flag = 0;
                }
            }
            if (flag == 1 && k == i) 
                return string("");
            for (j = 0; j < maxsize; ++j) {
                char c1 = words.at(k).at(j);
                if (pres.at(c1-'a') == 0) 
                    indeg.at(c1-'a') = 0;
                pres.at(c1-'a') = 1;
            }
        }
        int zero = 0;
        int nc = count(pres.begin(), pres.end(), 1);
        while (ans.size() < nc) {
            vector<int>::iterator it = std::find(indeg.begin(), indeg.end(), zero);
            int x = it-indeg.begin();
            if (it == indeg.end()) 
                return string("");
            for (int c : adj.at(x)) {
                indeg.at(c)--;
            }
            ans.push_back(x+'a');
            indeg.at(x) = -2;
        }
        return ans;
    }
};