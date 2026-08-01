class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mp;
        vector<vector<int>>bucket(n + 1);

        for(int i : nums){
            mp[i]++;
        }

        for(auto &it : mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int>ans;
        for(int i = n;i>=0;i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k)return ans;
            }
        }
        return ans;
    }
};