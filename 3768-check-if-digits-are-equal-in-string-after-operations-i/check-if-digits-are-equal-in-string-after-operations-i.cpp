class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string t = "";
            for (int i = 0; i < s.length()-1; i++) {
                t += (((s[i] - '0') + (s[i+1] - '0')) % 10) + '0';
            }
            s = t;
        }
        return s[0] == s[1];
    }
};