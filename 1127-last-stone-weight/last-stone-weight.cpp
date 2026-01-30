class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>q;
        for(int i : stones)q.push(i);

        while(q.size() > 1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();

            int res = abs(x - y);
            q.push(res);
        }
        return q.top();
    }
};