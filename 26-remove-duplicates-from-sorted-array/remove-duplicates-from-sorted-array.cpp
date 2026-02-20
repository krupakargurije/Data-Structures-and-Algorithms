class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1,k = 1;
        int n = nums.size();

        while(i < n){
            if(nums[i] == nums[k-1])i++;
            else{
                nums[k] = nums[i];
                i++;
                k++;
            }
        }
        return k;
    }
};