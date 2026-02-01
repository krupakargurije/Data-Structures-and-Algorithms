class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];

        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 1;i<n;i++)pq.push(nums[i]);

        int b = pq.top();
        pq.pop();
        int ans = a + b + pq.top();

        return ans;
    }
};