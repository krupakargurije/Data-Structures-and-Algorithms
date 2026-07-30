class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int i = 1;
        int ans = 0;

        while(n > 0){
            int temp = (n > 8) ? 8 : n;
            n -= temp;
            ans += temp * i;
            i++;
        }
        return ans;
    }
};