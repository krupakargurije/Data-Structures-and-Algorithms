class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>>mp;
        for(int i = 0;i<n;i++)
            mp[nums[i]].push_back(i);
        
        int ans = INT_MAX;

        for(auto &it : mp){
            vector<int> &vec = it.second;
            if(vec.size() < 3)continue;

            for(int i = 0;i + 2 < vec.size();i++){
                int dis = 2 * (vec[i + 2] - vec[i]);
                ans = min(ans , dis);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};