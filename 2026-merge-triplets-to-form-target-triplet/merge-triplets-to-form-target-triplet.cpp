class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int x = target[0];
        int y = target[1];
        int z = target[2];

        vector<int>ans(3 , 0);
        for(auto &it : triplets){
            int a = it[0];
            int b = it[1];
            int c = it[2];

            if(a <= x && b <= y && c <= z){
                ans[0] = max(ans[0] , a);
                ans[1] = max(ans[1] , b);
                ans[2] = max(ans[2] , c);
            }

            if(ans == target)return true;
        }
        return false;
    }
};