class Solution {
    private:
    long long helper(vector<int>& arr,int i,vector<long long>& dp){
        if(i >= arr.size()-1)return 1;
        if(dp[i] != -1)return dp[i];

        if(arr[i+1] == arr[i]-1){
            return dp[i] = 1 + helper(arr,i+1,dp);
        }
        return dp[i] = 1;
    }
public:
    long long getDescentPeriods(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        vector<long long>dp(n,-1);
        
        for(int i = 0;i<n;i++){
            ans += helper(arr,i,dp);
        }
        return ans;
    }
};