class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)return 0;

        int jumps = 0 , maxJumps = 0 , currEnd = 0;

        for(int i = 0;i<n;i++){
            maxJumps = max(maxJumps , nums[i] + i);

            if(i == currEnd){
                jumps++;
                currEnd = maxJumps;
            }
            if(currEnd >= n-1)return jumps;
        }
        return jumps;
    }
};