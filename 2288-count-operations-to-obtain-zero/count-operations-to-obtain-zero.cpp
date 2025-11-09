class Solution {
public:
    int countOperations(int n, int m) {
        if(n == 0 || m == 0)return 0;
        int ans = 0;
        while(n || m){
            if(n == m)return ans + 1;
            else if(n > m){
                n -= m;
                ans++;
            }
            else{
                m -= n;
                ans++;
            }
        }
        return ans;
    }
};