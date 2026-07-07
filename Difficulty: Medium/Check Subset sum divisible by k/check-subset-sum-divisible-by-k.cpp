class Solution {
    private:
    bool helper(vector<int>& arr, int k , int idx , int rem , vector<vector<int>> &dp){
        if(idx == 0){
            return (arr[0] + rem) % k == 0 ;
        }
        
        if(dp[idx][rem] != -1)
            return dp[idx][rem];
        
        if((rem + arr[idx]) % k == 0)
            return dp[idx][rem] = true;
        
        bool pic = helper(arr , k , idx - 1 , (rem + arr[idx]) % k, dp);
        bool nonPic = helper(arr , k , idx - 1 , rem , dp);
        
        return dp[idx][rem] = pic || nonPic;
    }
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>>dp(n , vector<int>(k , -1));
        return helper(arr , k , n-1 , 0 , dp);
    }
};