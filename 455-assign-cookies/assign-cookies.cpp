class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int ans = 0,j = 0,i = 0;
        
        while(i < n && j < m){
            if(g[i] <= s[j]){
                ans++;
                i++;
                j++;
            }else j++;
        }
        return ans;
    }
};