class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)return 1;
        vector<long long>dp(n,0);
        dp[0] = 1;
        long long ans = 1LL;
        
        for(int i = 1;i<n;i++){
            if(arr[i] == arr[i-1]-1){
                dp[i] = dp[i-1] + 1;
            }else{
                dp[i] = 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};