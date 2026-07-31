class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums[0]);

        for(int i = 1 ; i<n;i++){
            auto &prev = ans.back();
            auto &curr = nums[i];

            if(prev[1] >= curr[0]){
                prev[1] = max(prev[1] , curr[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

// [[1,3],[2,6],[8,10],[15,18]]

// ans = [1 , 6]
// [1 , 6] [8,10] [15 , 18]