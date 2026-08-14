class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int left = 0 , right = 0;
        vector<int>mp(26 , 0);
        int ans = 0;

        while(right < n){
            mp[s[right] - 'a']++;

            while(mp[s[right] - 'a'] > 2){
                mp[s[left] - 'a']--;
                left++;
            }
            ans = max(ans , right - left + 1);
            right++;
        }
        return ans;
    }
};