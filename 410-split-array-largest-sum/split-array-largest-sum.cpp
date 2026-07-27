class Solution {
    private:
    bool helper(vector<int>& nums, int k , int sum){
        int subArrays = 1;
        int currSum = 0;
        for(int i : nums){
            if(currSum + i > sum){
                subArrays++;
                currSum = i;
            }
            else
                currSum += i;
        }
        return subArrays <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = 0;

        for(int i : nums){
            low = max(low , i);
            high += i;
        }

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(helper(nums , k , mid)){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};