class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int j = 0,i = 0;
        
        while(i < n && j < m){
            if(g[i] <= s[j]){
                i++;
                j++;
            }else j++;
        }
        return i;
    }
};