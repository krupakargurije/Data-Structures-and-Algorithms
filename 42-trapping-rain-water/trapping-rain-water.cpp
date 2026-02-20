class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int left = 0,right = n-1;
        int leftMax = 0,rightMax = 0;
        int ans = 0;
        while(left<right){
            leftMax = max(leftMax,h[left]);
            rightMax = max(rightMax,h[right]);

            if(leftMax < rightMax){
                ans += leftMax - h[left];
                left++;
            }
            else{
                ans += rightMax - h[right];
                right --;
            }
        }
        return ans;
    }
};