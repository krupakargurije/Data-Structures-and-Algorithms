class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int j = 0,i = 0;

        while(j < n && i < n){
            while(i < n && nums[i] < 0)i++;
            while(j < n && nums[j] > 0)j++;

            ans.push_back(nums[i]);
            i++;

            ans.push_back(nums[j]);
            j++;
        }
        return ans;
    }
};



//    3 1 -2 -5 2 -4
//    i
//    j
//    [3 -2 1 -5 2 -4]