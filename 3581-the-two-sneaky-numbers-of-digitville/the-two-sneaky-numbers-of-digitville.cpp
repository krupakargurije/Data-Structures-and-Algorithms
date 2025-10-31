class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i : nums){
            mp[i]++;
            if(mp[i] > 1)ans.push_back(i);
        }
        return ans;
    }
};