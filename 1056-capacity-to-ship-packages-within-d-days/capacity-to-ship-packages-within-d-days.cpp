class Solution {
    private:
    bool helper(vector<int> &nums , int days , int capacity){
        int n = nums.size();
        int rDays = 1,curr = 0;

        for(int i = 0;i<n;i++){
            if(curr + nums[i] > capacity){
                rDays++;
                curr = nums[i];
            }
            else
                curr += nums[i];
        }
        return rDays <= days;
    }
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();

        int left = 0,right = 0;

        for(int i : nums){
            right += i;
            left = max(left , i);
        }

        while(left <= right){
            int mid = left + (right - left) /2;

            if(helper(nums , days , mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};