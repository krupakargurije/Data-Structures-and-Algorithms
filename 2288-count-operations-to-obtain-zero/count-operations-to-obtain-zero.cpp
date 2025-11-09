class Solution {
public:
    int countOperations(int n, int m) {
        if(!n || !m)return 0;
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