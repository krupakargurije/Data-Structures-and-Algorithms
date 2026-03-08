class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        if(n < p.size())return {};

        vector<int>freq(26) , currFreq(26);
        for(char c : p)
            freq[c - 'a']++;

        vector<int>ans;
        int k = p.size();
        for(int j = 0;j<n;j++){
            currFreq[s[j] - 'a']++;

            if(j >= k){
                currFreq[s[j - k] - 'a']--;
            }
            
            if(freq == currFreq)
                ans.push_back(j - k + 1);
        }
        return ans;
    }
};