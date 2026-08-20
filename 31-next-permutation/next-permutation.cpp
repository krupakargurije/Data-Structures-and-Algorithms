class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 2;

        while(i >= 0 && nums[i] >= nums[i + 1])i--;

        if(i >= 0){
            int j = n - 1;

            while(j >= 0 && nums[i] >= nums[j])j--;
            swap(nums[i] , nums[j]);
        }
        reverse(nums.begin() + i + 1 , nums.end());
    }
};


// 1 2 3 6 5 4 ->  1 2 4 5 6 3
//     p

// 1 2 4 6 5 3 -> 1 2 4 3 5 6

