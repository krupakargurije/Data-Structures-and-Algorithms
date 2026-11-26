class Solution {
    // private:
    // int helper(int idx , vector<int> &coins , int target , vector<vector<int>> &dp){
    //     if(idx == 0){
    //         if(target % coins[0] == 0)
    //             return target / coins[0];
    //         else 
    //             return 1e9;
    //     }

    //     if(dp[idx][target] != -1)
    //         return dp[idx][target];

    //     int skip = helper(idx - 1 , coins , target , dp);
    //     int pic = 1e9;
        
    //     if(coins[idx] <= target)
    //         pic = 1 + helper(idx , coins , target - coins[idx] , dp);

    //     return dp[idx][target] = min(pic , skip);
    // }
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<int>prev(amount+1 , 1e9) , curr(amount + 1 , 1e9);

        for(int i = 0;i<=amount;i++){
            if(i % coins[0] == 0)
                prev[i] = i / coins[0];
        }
        
        for(int idx = 1;idx < n;idx++){
            for(int target = 0;target<=amount;target++){

                int skip = prev[target];
                int pic = 1e9;

                if(target >= coins[idx]){
                    pic = 1 + curr[target - coins[idx]];
                }

                curr[target] = min(pic , skip);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9)return -1;
        return prev[amount];
    }
};