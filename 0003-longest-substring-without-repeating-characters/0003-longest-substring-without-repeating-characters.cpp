class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int>mp(128 , -1);
        int ans = 0;
        int left = 0;

        for(int right = 0;right<n;right++){
            if(mp[s[right]] >= left){
                left = mp[s[right]] + 1;
            }

            mp[s[right]] = right;
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};