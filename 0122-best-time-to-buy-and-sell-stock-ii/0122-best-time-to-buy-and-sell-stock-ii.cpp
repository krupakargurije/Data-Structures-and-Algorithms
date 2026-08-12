class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int minStock = nums[0];
        int ans = 0 , i = 0;

        while(i < n){
            if(minStock < nums[i]){
                ans += nums[i] - minStock;
                minStock = nums[i];
            }
            minStock = min(minStock , nums[i]);
            i++;
        }
        return ans;
    }
};