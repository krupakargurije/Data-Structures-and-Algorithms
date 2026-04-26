using ll = long long;
class Solution {
    private:
    bool helper(vector<int>& nums, int threshold , ll divisor){
        int n = nums.size();

        ll sum = 0;
        for(int i = 0;i<n;i++){
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return (sum <= threshold) ? true : false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        ll low = 1 , high = (ll)*max_element(nums.begin() , nums.end());

        while(low <= high){
            ll mid = low + (high - low) / 2;

            if(helper(nums , threshold , mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};