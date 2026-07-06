class Solution {
  public:
    int maxCharGap(string &s) {
        int n = s.length();
        
        // char , freq , init position
        unordered_map<char , pair<int , int>>mp;
        int ans = -1;
        
        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {1 , i};
            }
            else{
                mp[s[i]].first++;
                ans = max(ans , i - mp[s[i]].second - 1);
            }
        }
        return ans;
    }
};