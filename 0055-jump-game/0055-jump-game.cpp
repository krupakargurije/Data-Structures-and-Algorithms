class Solution {
    // private:
    // bool helper(int idx , vector<int> &nums){
    //     int n = nums.size();

    //     if(idx >= n - 1)
    //         return true;
        
    //     for(int i = 1;i<= nums[idx];i++){
    //         if(helper(idx + i , nums))
    //             return true;
    //     }
    //     return false;
    // }
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)return true;

        int maxReach = 0;

        for(int i = 0;i<nums.size();i++){
            if(i > maxReach)return false;

            if(maxReach >= nums.size() - 1)return true;
            
            maxReach = max(maxReach , nums[i] + i);
        }
        return true;
    }
};