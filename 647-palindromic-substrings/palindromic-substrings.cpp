class Solution {
    private:
    int helper(string s , int left , int right){
        int n = s.length();
        int count = 0;

        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();

        int ans= 0;
        for(int i = 0;i<n;i++){

            ans += helper(s , i , i);
            ans += helper(s , i , i+1);
        }
        return ans;
    }
};