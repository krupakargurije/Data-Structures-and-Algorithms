class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr;
        string ans = "";
        for(int i = 0;i<n;i++){
            arr.push_back(to_string(nums[i]));
        }

        sort(arr.begin(), arr.end(), [](const string& x, const string& y) {return (y + x) < (x + y);});
        if (arr[0] == "0") {
            return "0";
        }

        for(string i : arr){
            ans += i;
        }

        return ans;
    }
};