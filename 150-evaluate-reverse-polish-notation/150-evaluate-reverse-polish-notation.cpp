class Solution {
    bool isop(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for (auto token : tokens) {
            if (!isop(token))
                s.push((long long)stoi(token));
            else {
                auto a = s.top();
                s.pop();
                auto b = s.top();
                s.pop();
                if (token == "+") 
                    s.push(a+b);
                else if (token == "-") 
                    s.push(b-a);
                else if (token == "*") 
                    s.push(a*b);
                else
                    s.push(b/a);
            }
        }
        return s.top();
    }
};