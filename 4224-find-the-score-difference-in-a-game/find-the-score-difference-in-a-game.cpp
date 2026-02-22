class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        bool p1 = true,p2 = false;
        int p1Score = 0,p2Score = 0;
        int flag = 0;

        for(int i = 0;i<n;i++){
            flag++;
            
            if(nums[i] % 2 != 0)swap(p1 , p2);
            if(flag == 6){
                swap(p1 , p2);
                flag = 0;
            }

            if(p1)p1Score += nums[i];
            else p2Score += nums[i];

        }
        return p1Score - p2Score;
    }
};