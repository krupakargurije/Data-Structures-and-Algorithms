class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int start = 0 , len = INT_MAX;
        int left = 0 , right = 0;

        int numOfOnes = 0;
        while(right < n){
            if(s[right] == '1')numOfOnes++;

            while(numOfOnes > k){
                if(s[left] == '1')numOfOnes--;
                left++;
            }
            while (numOfOnes == k && s[left] == '0') {
                left++;
            }
            
            int currLen = right - left + 1;
            if (numOfOnes == k) {
                if (currLen < len ||
                    (currLen == len &&
                     s.compare(left, currLen, s, start, len) < 0)) {
                    start = left;
                    len = currLen;
                }
            }
            right++;
        }
        return len == INT_MAX ? "" : s.substr(start , len);
    }
};