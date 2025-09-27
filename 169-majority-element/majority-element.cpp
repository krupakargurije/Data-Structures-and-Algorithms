class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans = 0,freq = 0;
        for(auto i : mp){
            if(i.second > freq){
                ans = i.first;
                freq = i.second;
            }
        }
        return ans;
    }
};