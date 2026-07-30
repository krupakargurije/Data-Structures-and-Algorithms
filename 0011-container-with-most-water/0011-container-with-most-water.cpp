class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n-1;
        int ans = 0;

        while(left < right){
            int width = right - left;
            ans = max(ans , min(nums[left] , nums[right]) * width);

            if(nums[left] > nums[right])right--;
            else left++;
        }
        return ans;
    }
};