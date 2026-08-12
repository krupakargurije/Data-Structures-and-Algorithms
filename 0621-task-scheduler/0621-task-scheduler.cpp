class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
        int len = tasks.size();
        vector<int>mp(26 , 0);
        int maxFreq = 0;

        for(char c : tasks){
            mp[c - 'A']++;
            maxFreq = max(maxFreq , mp[c - 'A']);
        }

        int maxCount = 0;
        for(int i : mp){
            if(i == maxFreq)maxCount++;
        }

        int total = len;
        int ans = (maxFreq - 1) * (n + 1) + maxCount;
        return max(ans , total);
    }
};