class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end(),
            [](const vector<int> &a , const vector<int> &b){
                return a[1] < b[1];
            }
        );
        int n = points.size();

        int arrows = 1;
        int prev = points[0][1];
        for(int i = 1;i<n;i++){
            if(prev < points[i][0]){
                arrows++;
                prev = points[i][1];
            }
        }
        return arrows;
    }
};