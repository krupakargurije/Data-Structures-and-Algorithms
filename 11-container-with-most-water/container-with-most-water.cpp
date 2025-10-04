class Solution {
public:
    int maxArea(vector<int>& h) {
        int area = 0;
        int left = 0,right = h.size()-1;
        while(left < right){
            int currArea = (right - left)  * min(h[left],h[right]);
            
            if(h[left] == h[right]){
                left++;
                right--;
            }
            else if(h[left] < h[right]) left++;
            else right--;
            area = max(area,currArea);
        }
        return area;
    }
};