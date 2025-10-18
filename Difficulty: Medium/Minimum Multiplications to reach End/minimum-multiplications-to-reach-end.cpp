// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)return 0;
        
        int MOD = 100000;
        queue<pair<int,int>> q;
        vector<int> dis(MOD,INT_MAX);
        q.push({start,0});
        dis[start] = 0;
        
        while(!q.empty()){
            auto [num,steps] = q.front();
            q.pop();
            
            for(int it : arr){
                int nNum =( num * it) % MOD;
                
                if(steps + 1 < dis[nNum]){
                    dis[nNum] = steps+1;
                    if(nNum == end)return dis[nNum];
                    q.push({nNum,dis[nNum]});
                }
            }
        }
        return -1;
    }
};
