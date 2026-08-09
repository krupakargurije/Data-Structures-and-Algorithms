class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        
        //finish Time , Positio , start Time
        priority_queue<tuple<int , int , int>,
            vector<tuple<int , int , int>>,
            greater<tuple<int , int , int>>
        >pq;
        
        for(int i = 0;i<n;i++){
            pq.push({f[i] , i + 1 , s[i]});
        }
        
        vector<int>ans;
        int pEnd = -1;
        
        while(!pq.empty()){
            auto [end , pos , start] = pq.top();
            pq.pop();
            
            if(start > pEnd){
                ans.push_back(pos);
                pEnd = end;
            }
        }
        
        sort(ans.begin() , ans.end());
        return ans;
    }
};