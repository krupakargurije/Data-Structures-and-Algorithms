class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            tuple<int , int , int>,
            vector<tuple<int , int , int>>,
            greater<tuple<int , int , int>>
        >pq;

        for(auto &it : points){
            int x = it[0];
            int y = it[1];

            long long res = 1LL * x * x + 1LL * y * y;
            pq.push({(int)res , x , y});
        }

        vector<vector<int>>ans;
        while(k--){
            auto [dis , x , y] = pq.top();
            pq.pop();
            ans.push_back({x , y});
        }
        return ans;
    }
};