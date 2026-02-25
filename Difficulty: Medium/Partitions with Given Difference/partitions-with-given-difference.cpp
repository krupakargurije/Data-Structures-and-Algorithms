class Solution {
    private:
    int helper(vector<int> &arr , int target , int idx ,vector<vector<int>> &dp){
        if(idx < 0)return 0;
        if(idx == 0){
            if(target == 0 && arr[0] == 0)return 2;
            if(target == 0 || arr[0] == target)return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1)return dp[idx][target];
        
        int notPic = helper(arr, target , idx - 1, dp);
        int pic = 0;
        if(target >= arr[idx])
            pic = helper(arr , target - arr[idx] , idx - 1, dp);
            
        return dp[idx][target] = pic + notPic;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for(int i : arr)sum += i;
        
        if(sum - diff < 0 || (sum - diff) % 2)return 0;
        
        int target = (sum - diff)/2;
        vector<vector<int>>dp(n , vector<int>(target +1 , -1));
        
        return helper(arr, target , n-1,dp);
    }
};