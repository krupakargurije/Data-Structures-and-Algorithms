class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n-1;
        int lMax = 0 , rMax = 0;
        int ans = 0;

        while(left < right){
            lMax = max(lMax , nums[left]);
            rMax = max(rMax , nums[right]);

            if(lMax < rMax){
                ans += lMax - nums[left];
                left++;
            }
            else{
                ans += rMax - nums[right];
                right--;
            }
        }
        return ans;
    }
};