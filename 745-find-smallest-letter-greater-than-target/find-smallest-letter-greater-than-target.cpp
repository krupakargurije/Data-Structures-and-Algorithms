class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int n = arr.size();
        char ans = arr[0];

        int left = 0,right = n-1;

        while(left <= right){
            int mid = left + (right - left) /2;
            
            if(arr[mid] > target){
                ans = arr[mid];
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};