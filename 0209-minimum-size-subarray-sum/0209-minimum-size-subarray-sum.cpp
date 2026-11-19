class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLenWindow = INT_MAX;
        int left = 0 , currentSum = 0;

        for(int right = 0;right<nums.size();right++){
            if(nums[right] == target)return 1;

            currentSum += nums[right];

            while(currentSum >= target){
                minLenWindow = min(minLenWindow , right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        return minLenWindow != INT_MAX ? minLenWindow : 0;
    }
};