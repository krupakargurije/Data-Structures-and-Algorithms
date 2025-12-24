class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int n = cap.size();
        int total = 0;
        sort(cap.begin(),cap.end());
        for(int i : apple)total += i;

        int ans = 0;
        int curr = 0;
        for(int i = n - 1;i >= 0;i--){
            if(curr >= total){
                return ans;
            }
            curr += cap[i];
            ans++;
        }
        return ans;
    }
};