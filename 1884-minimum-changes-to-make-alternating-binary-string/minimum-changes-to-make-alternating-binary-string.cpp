class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int zero = 0,one = 0;

        for(int i = 0;i<n;i++){
            if(s[i] == (i % 2 == 0 ? '0' : '1'))zero++;
            if(s[i] == (i % 2 == 0 ? '1' : '0'))one++;
        }
        return min(zero , one);
    }
};