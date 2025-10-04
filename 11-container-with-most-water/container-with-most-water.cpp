class Solution {
public:
    int maxArea(vector<int>& arr) {
        int ans = 0;
        int i = 0,j = arr.size()-1;
        while(i < j){
            int temp = min(arr[i],arr[j]) * (j-i);
            if(arr[i] == arr[j]){
                i++;
                j--;
            }
            else if(arr[i] > arr[j]){
                j--;
            }
            else{
                i++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};