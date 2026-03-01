class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0)return 0;
        vector<int>prev(amount + 1 , 1e9) , curr(amount + 1 ,1e9);

        for(int target = 0;target<=amount ;target++){
            if(target % coins[0] == 0)prev[target] = target / coins[0];
        }

        for(int idx = 1;idx < n;idx++){
            for(int target = 0;target <= amount;target++){
                int nonPic = prev[target];

                int pic = 1e9;
                if(coins[idx] <= target)
                    pic = 1 + curr[target - coins[idx]];

                curr[target] = min(pic , nonPic);
            }
            prev = curr;
        }
        return (prev[amount] == 1e9) ? -1 : prev[amount];
    }
};