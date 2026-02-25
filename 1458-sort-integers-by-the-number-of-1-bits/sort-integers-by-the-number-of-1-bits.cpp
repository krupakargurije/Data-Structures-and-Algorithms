class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int ,int> ,vector<pair<int,int>> , greater<pair<int, int>>>pq;
        for(int i : arr){
            int bits = __builtin_popcount(i);
            pq.push({bits , i});
        }

        vector<int>ans;

        while(!pq.empty()){
            auto[bits , num] = pq.top();
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};