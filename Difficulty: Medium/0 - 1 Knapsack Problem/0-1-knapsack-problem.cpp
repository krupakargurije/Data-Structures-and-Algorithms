class Solution {
  public:
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int>prev(w + 1 , 0) , curr( w + 1, 0);
        
        for(int i = wt[0];i<=w;i++)prev[i] = val[0];
        
        for(int idx = 1;idx < n ;idx++){
            for(int bagWeight = 0;bagWeight <= w;bagWeight++){
                int notPic = prev[bagWeight];
                
                int pic = 0;
                if(wt[idx] <= bagWeight)
                    pic = val[idx] + prev[bagWeight - wt[idx]];
                
                curr[bagWeight] = max(pic , notPic);
            }
            prev = curr;
        }
        return prev[w];
    }
};