class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        // {end, value}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int best = 0;
        int ans = 0;

        for (auto &e : events) {
            int start = e[0];
            int end   = e[1];
            int val   = e[2];

            // pop all events that ended before current starts
            while (!pq.empty() && pq.top().first < start) {
                best = max(best, pq.top().second);
                pq.pop();
            }

            ans = max(ans, best + val);
            pq.push({end, val});
        }
        return ans;
    }
};
