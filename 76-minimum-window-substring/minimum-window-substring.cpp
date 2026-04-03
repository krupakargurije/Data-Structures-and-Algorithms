class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n < m) return "";
        if(s == t) return s;

        unordered_map<char , int> mp;
        unordered_map<char , int> req;

        for(char &c : t) req[c]++;

        int left = 0;
        int required = req.size();
        int formed = 0;
        int start = 0 , minLen = INT_MAX;

        for(int right = 0; right < n; right++) {
            char c = s[right];  // ✅ FIX
            mp[c]++;

            if(req.count(c) && mp[c] == req[c]) formed++;

            while(formed == required) {
                int len = right - left + 1;

                if(len < minLen) {
                    minLen = len;
                    start = left;
                }

                char ch = s[left];  // ✅ FIX
                mp[ch]--;           // ✅ FIX

                if(req.count(ch) && mp[ch] < req[ch]) {
                    formed--;
                }

                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start , minLen);
    }
};