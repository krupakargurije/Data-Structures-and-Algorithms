class Solution {
public:
    int maxIceCream(vector<int>& nums, int coins) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int ans = 0;
        for(int i : nums){
            if(coins >= 1 && i <= coins){
                ans++;
                coins -= i;
            }
            else
                break;
        }
        return ans;
    }
};