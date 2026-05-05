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

        int left = *max_element(nums.begin() , nums.end()),right = accumulate(nums.begin() , nums.end() , 0);

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