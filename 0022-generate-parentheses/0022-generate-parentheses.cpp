class Solution {
public:
    vector<string> ans;
    void helper(string str,int open,int close){
        if(open == 0 && close == 0){
            ans.push_back(str);
            return;
        }
        
        if(open > 0){
            helper(str + '(',open - 1,close);
        }

        if(close > open){
            helper(str + ')',open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        helper("",n,n);
        return ans;
    }
};