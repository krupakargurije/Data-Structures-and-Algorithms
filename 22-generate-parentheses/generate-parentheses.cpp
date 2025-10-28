class Solution {
public:
    vector<string> ans;
    void solve(string str,int open,int close){
        if(open == 0 && close == 0){
            ans.push_back(str);
            return;
        }
        
        if(open > 0){
            solve(str + '(',open - 1,close);
        }

        if(close > open){
            solve(str + ')',open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("",n,n);
        return ans;
    }
};