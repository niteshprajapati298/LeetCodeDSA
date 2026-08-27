class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if(count < 0) return false;

            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }
        }
        return count == 0 ? true : false;
    }
    void solve(int &n, string& s, vector<string>& ans) {
        if (s.length() == n * 2) {
            if (isValid(s)) {
                ans.push_back(s);
                return;
            }
            else return;
        }
        s.push_back('(');
        solve(n,s, ans);
        s.pop_back();
        s.push_back(')');
        solve(n,s , ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(n, s, ans);
        return ans;
    }
};