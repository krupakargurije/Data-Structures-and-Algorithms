class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())return "";

        int n = s.length();
        unordered_map<char , int>target;
        unordered_map<char , int>window;

        for(char c : t)target[c]++;

        int start = 0;
        int formed = 0;
        int targetLen = target.size();
        int minLen = INT_MAX;

        //ADOBEC
        // target[i] = window[i] formed++;
        int left = 0 , right = 0;

        while(right < n){
            char c = s[right];
            window[c]++;

            if(target.count(c) && target[c] == window[c])
                formed++;
            
            while(left <= right && formed == targetLen){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if(target.count(leftChar) && target[leftChar] > window[leftChar]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start , minLen);
    }
};