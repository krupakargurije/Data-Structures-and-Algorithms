class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i = 0,j = nums.size()-1;
        
        for(int i = 0;i<nums.size();i++){
           if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int k = i+1,j= nums.size()-1;
            while(k<j){
                if(nums[i]+nums[k]+nums[j] == 0){
                    ans.push_back({nums[i],nums[k],nums[j]});
                    while(k<j && nums[k] == nums[k+1])k++;
                    k++;
                    j--;
                }
                else if(nums[i]+nums[k]+nums[j] < 0)k++;
                else j--;
            }
        }
        return ans;
    }
};