class Solution {
public:
    // bool isValid(string s) {
    //     int count = 0;
    //     for (int i = 0; i < s.length(); i++) {
    //         if (count < 0)
    //             return false;

    //         if (s[i] == '(') {
    //             count++;
    //         } else if (s[i] == ')') {
    //             count--;
    //         }
    //     }
    //     return count == 0 ? true : false;
    // }
    void solve(int& n, string& s, vector<string>& ans, int &close, int& open) {
        if (s.length() == n * 2) {
                ans.push_back(s);
                return;
        }

        if (open < n) {
            s.push_back('(');
            open = open + 1;
            solve(n, s, ans, close, open);
            open = open - 1;
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            close = close + 1;
            solve(n, s, ans, close, open);
            close = close-1;
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int close = 0 , open = 0;
        solve(n, s, ans , close, open);
        return ans;
    }
};