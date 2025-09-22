class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int freq = 0;
        for(int i : nums){
            mp[i]++;
        }
        for(auto i : mp){
            freq = max(freq,i.second);
        }
        int ans = 0;
        for(auto i : mp)if(i.second == freq)ans += i.second;
        return ans;
    }
};