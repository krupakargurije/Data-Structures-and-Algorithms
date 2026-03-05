class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int one = 0, zero = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == (i % 2 == 0 ? '1' : '0')) one++;
            if(s[i] == (i % 2 == 0 ? '0' : '1')) zero++;
        }
        return min(one, zero);
    }
};