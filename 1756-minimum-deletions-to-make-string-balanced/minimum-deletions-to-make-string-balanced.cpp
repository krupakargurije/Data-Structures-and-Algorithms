class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int bc = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == 'b')bc++;
            else{
                ans = min(ans+1,bc);
            }
        }
        return ans;
    }
};