class Solution {
public:
    string longestPalindrome(string s) {
        int r, l;
        int n = s.size();
        int cmax = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
            }
            if (r-l+1-2 > cmax) {
                cmax = r-l+1-2;
                ans = s.substr(l+1, r-l+1-2);
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
            }
            if (r-l+1-2 > cmax) {
                cmax = r-l+1-2;
                ans = s.substr(l+1, r-l+1-2);
            }
        }
        return ans;
    }
};