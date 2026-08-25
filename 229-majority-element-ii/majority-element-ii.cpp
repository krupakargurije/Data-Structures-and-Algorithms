class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int , int>mp;
        int n = nums.size();

        for(int it : nums)
            mp[it]++;
        
        vector<int>ans;
        int k = n / 3;

        for(auto &it : mp){
            if(it.second > k)ans.push_back(it.first);
        }
        return ans;
    }
};