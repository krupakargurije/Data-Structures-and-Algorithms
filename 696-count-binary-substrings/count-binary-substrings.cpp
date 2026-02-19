class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int ans = 0;
        int curr = 1 , prev = 0;
        
        for(int i = 1;i<n;i++){
            if(s[i] == s[i - 1])curr++;
            else{
                ans += min(curr,prev);
                prev = curr;
                curr = 1;
            }
        }
        ans += min(curr,prev);
        return ans;
    }
};