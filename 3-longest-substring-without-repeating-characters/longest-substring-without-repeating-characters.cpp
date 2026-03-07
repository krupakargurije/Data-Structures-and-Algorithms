class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0 || n == 1)return n;

        unordered_map<char , int>mp;
        int ans = 0;

        for(int i = 0 ,j = 0;i < n && j < n;i++){
            if(mp[s[i]] < 1){
                mp[s[i]]++;
                int len = i - j + 1;
                ans = max(ans , len);
            }
            else{
                mp[s[j++]]--;
                i--;
            }
        }
        return ans;
    }
};  