class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char,int> mp;
            int maxFreq = 0;

            for(int k = i; k < n; k++) {
                mp[s[k]]++;
                maxFreq = max(maxFreq, mp[s[k]]);

                int len = k - i + 1;
                int unique = mp.size();

                if(maxFreq * unique == len) {
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
