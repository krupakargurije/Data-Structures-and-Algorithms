class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mp;

        for(int i : nums){
            mp[i]++;
        }

        priority_queue<pair<int , int>, 
            vector<pair<int , int>>, 
            greater<pair<int , int>>
        >pq;
        vector<int>ans;
        
        for(auto &it : mp){
            pq.push({it.second , it.first});

            while(pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};