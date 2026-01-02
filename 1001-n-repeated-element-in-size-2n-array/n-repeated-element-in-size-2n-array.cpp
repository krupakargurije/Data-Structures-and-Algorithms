class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i : nums)mp[i]++;

        int ans;

        for(auto it : nums){
            if(mp[it] == n/2)return it;
        }
        return 0;
    }
};