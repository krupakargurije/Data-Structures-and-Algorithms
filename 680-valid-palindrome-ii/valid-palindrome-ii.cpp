class Solution {
    bool helper(string &s,int i ,int j){
        while(i <= j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            if(s[i] != s[j]){
                return helper(s, i+1, j) || 
                       helper(s, i, j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};