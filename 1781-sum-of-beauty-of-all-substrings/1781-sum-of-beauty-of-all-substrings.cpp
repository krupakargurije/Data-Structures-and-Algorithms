class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            vector<int>mp(26 , 0);

            for(int j = i;j < n;j++){
                mp[s[j] - 'a']++;

                int mx = 0 , mn = INT_MAX;

                for(int k = 0;k < 26;k++){
                    if(mp[k] == 0)
                        continue;
                    
                    mx = max(mx , mp[k]);
                    mn = min(mn , mp[k]);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};