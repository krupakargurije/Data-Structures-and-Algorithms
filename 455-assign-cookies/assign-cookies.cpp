class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();
        if(n == 0 || m == 0)return 0;
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