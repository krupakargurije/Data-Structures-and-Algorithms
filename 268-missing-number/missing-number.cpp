class Solution {
public:
    int missingNumber(vector<int>& nums) {
        priority_queue<int, vector<int> ,greater<int>> pq;
        int n = nums.size();
        for(int i: nums){
            pq.push(i);
        }

        for(int i = 0;i<n;i++){
            if(pq.top() != i)return i;
            pq.pop();
        }
        return n;
    }
};