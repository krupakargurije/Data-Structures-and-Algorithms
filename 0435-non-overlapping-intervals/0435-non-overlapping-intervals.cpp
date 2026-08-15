class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end(), 
        [](const auto &a , const auto &b){
            return a[1] < b[1];
        });

        int ans = 0;
        int start = INT_MIN;
        int end = INT_MIN;

        for(auto &it : intervals){

            if(end > it[0]){
                end = min(end , it[1]);
                ans++;
            }
            else{
                start = it[0];
                end = it[1];
            }
        }
        return ans;
    }
};

// [1,2],[1,3],[2,3],[3,4]

// 1,2  1,3  2,3  3,4

// 1,2 2,3 3,4