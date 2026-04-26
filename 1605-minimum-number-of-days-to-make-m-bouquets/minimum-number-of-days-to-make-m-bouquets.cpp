using ll = long long;
class Solution {
    private:
    bool helper(vector<int>& arr, int m, int k , ll day){
        int n = arr.size();

        int req = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] <= (int)day && req < k){
                req++;
                if(req == k){
                    req = 0;
                    count++;
                }
            }
            else{
                req = 0;
            }
        }
        return (count >= m ) ? true : false;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if((long long)m * k > (long long)n)return -1;

        ll low = *min_element(arr.begin() , arr.end());
        ll high = *max_element(arr.begin() , arr.end());

        while(low <= high){
            ll mid = low + (high - low) /2;

            if(helper(arr , m , k , mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};