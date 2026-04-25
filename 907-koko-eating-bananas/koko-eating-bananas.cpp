using ll = long long;
class Solution {
    private:
    ll time(vector<int> &arr , int h){
        int n = arr.size();
        ll time = 0;

        for(int i : arr){
            time += (i + h - 1) / h;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        ll low = 1 , high = (ll)*max_element(piles.begin() , piles.end());

        while(low <= high){
            ll mid = low + (high - low) /2;
            ll t = time(piles , mid);

            if(t <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};