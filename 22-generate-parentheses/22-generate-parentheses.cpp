class Solution {
    string s;
    vector<string> ans;
    int n;
    void recurse(int open, int closed) {
        if ((open == closed) && (open == n))
            ans.push_back(s);
        if (open < n) {
            s.push_back('(');
            recurse(open+1, closed);
            s.pop_back();
        }
        if (closed < open) {
            s.push_back(')');
            recurse(open, closed+1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        recurse(0, 0);
        return ans;
    }
};