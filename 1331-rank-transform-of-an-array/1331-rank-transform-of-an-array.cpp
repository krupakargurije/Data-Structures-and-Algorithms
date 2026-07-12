class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            pq.push({arr[i], i});

        int rank = 0;
        int prev = INT_MIN;

        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            if (num != prev) {
                rank++;
                prev = num;
            }
            ans[idx] = rank;
        }
        return ans;
    }
};