class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string startWith1 = "";
        string startWith0 = "";

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                startWith1 += '1';
                startWith0 += '0';
            } else {
                startWith1 += '0';
                startWith0 += '1';
            }
        }

        int one = 0, zero = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != startWith1[i]) one++;
            if(s[i] != startWith0[i]) zero++;
        }

        return min(one, zero);
    }
};