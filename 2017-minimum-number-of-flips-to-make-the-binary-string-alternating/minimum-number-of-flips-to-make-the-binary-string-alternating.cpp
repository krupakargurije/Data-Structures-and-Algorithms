class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int diff = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != (i & 1)) diff++;
        }
        
        int res = min(diff, n - diff);
        if (res == 0 || (n & 1) == 0) return res;
        
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != (i & 1)) diff--;
            else diff++;
            
            int cur = min(diff, n - diff);
            if (cur < res) {
                res = cur;
                if (res == 0) return 0;
            }
        }
        
        return res;
    }
};