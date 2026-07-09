class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n , 0);
        int curr = 0;

        for(int i = 1;i<n;i++){
            if(nums[i] - nums[i - 1] > maxDiff)
                curr++;
            
            group[i] = curr;
        }

        vector<bool>ans;
        for(auto it : queries){
            int u = it[0] , v = it[1];
            ans.push_back(group[u] == group[v]);
        }
        return ans;
    }
};