using ll = unsigned long long;
class Solution {
public:
    int change(int money, vector<int>& coins) {
        int n = coins.size();

        vector<ll> curr(money + 1 , 1) , prev(money + 1 , 0);

        for(int idx = 0; idx < n; idx++){
            for(int amount = 1; amount <= money; amount++){

                ll nonpick = (idx > 0) ? curr[amount] : 0;

                ll pick = 0;
                if(coins[idx] <= amount)
                    pick = curr[amount - coins[idx]];

                curr[amount] = pick + nonpick;
            }
            prev = curr;
        }
        return (int)prev[money];
    }
};