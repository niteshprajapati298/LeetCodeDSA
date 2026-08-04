class Solution {
public:
    void solve(string& s, vector<vector<string>>&ans,vector<string>path , int index ) {
        if(s.size() == index) {
            ans.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s,index,i)){
               path.push_back(s.substr(index,i-index+1));
               solve(s,ans,path,i+1);
               path.pop_back();
            }
        }
    }
    bool isPalindrome(string s , int index , int i){
            while(index <=i){
                if(s[index]!=s[i]) return false;
                index++;
                i--;
            };
            return true;
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string>path;
        int index = 0;
        int n = s.size();
        solve(s,ans,path,index);
        return ans;
    }
};