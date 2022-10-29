class Solution {
public:
    int countSubstrings(string s) {
        int r, l;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
                ans++;
            }
        }
        for (int i = 0; i < n-1; i++) {
            int l = i;
            int r = i+1;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    }

};