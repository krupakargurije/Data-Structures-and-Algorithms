class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2)return n;

        int i = 2 , k = 2;
        while(i < n){
            if(nums[k - 2] != nums[i]){
                nums[k] = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};