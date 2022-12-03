class Solution {
public:
    string minWindow(string s, string t) {
        int min_size = INT_MAX;
        string ans = "";
        pair<int, int> ans_indices {-1,-1};
        int l = 0;
        int r = 0;
        map<char, int> m;
        set<char> t_chars;
        set<char> rem;
        // multi_set<char> extra;
        for (char c : t) {
            if (m.find(c) == m.end())
                m[c] = 0;
            m[c]++;
            t_chars.insert(c);
            rem.insert(c);
        }
        if (t_chars.find(s[0]) != t_chars.end()) {
            m[s[0]]--;
            if (m[s[0]] == 0)
                rem.erase(s[0]);
        }
        while (l<s.size() && r < s.size()) {
            if (rem.empty()) {
                if (r-l+1 < min_size) {
                    ans_indices = make_pair(l,r);
                    min_size = r-l+1;
                }
                if (t_chars.find(s[l]) != t_chars.end()) {
                    m[s[l]]++;
                    if (m[s[l]]>0)
                        rem.insert(s[l]);
                }
                l++;
            }
            else {
                r++;
                if (r < s.size() && t_chars.find(s[r]) != t_chars.end()) {
                    m[s[r]]--;
                    if (m[s[r]] == 0)
                        rem.erase(s[r]);
                }
            }
        }
        if (ans_indices.first == -1)
            return "";
        return s.substr(ans_indices.first, ans_indices.second - ans_indices.first + 1);
    }
};