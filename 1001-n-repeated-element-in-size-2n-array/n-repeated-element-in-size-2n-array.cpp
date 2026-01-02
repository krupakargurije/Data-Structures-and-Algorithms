class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i : nums){
            mp[i]++;
            if(mp[i] == n/2)return i;
        }
        return 0;
    }
};