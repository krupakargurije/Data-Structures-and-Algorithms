class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int ans = 0;
        int left = 0,right = 0;

        while(right < s.length()){
            if(st.find(s[right]) == st.end()){
                ans = max(ans , right - left +1);
                st.insert(s[right++]);
            }
            else{
                st.erase(s[left++]);
            }
        }
        return ans;
    }
};
