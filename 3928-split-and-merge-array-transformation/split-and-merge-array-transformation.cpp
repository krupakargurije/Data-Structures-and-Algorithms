class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> dub = nums1;
        int n = nums1.size();

        queue<pair<vector<int>,int>> q;
        set<vector<int>> vis;

        q.push({nums1,0});
        vis.insert(nums1);

        while(!q.empty()){
            vector<int> cur = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(cur == nums2)return steps;
            for(int i = 0;i<n;i++){
                for(int j = i;j<n;j++){

                    vector<int> arr(cur.begin()+i,cur.begin()+j+1);

                    vector<int> rArr;
                    for(int r = 0;r<i;r++){
                        rArr.push_back(cur[r]);
                    }
                    for(int l = j+1;l<n;l++){
                        rArr.push_back(cur[l]);
                    }

                    for(int p = 0;p <= (int)rArr.size();p++){
                        vector<int> nxt = rArr;
                        nxt.insert(nxt.begin() + p,arr.begin(),arr.end());

                        if(!vis.count(nxt)){
                            vis.insert(nxt);
                            q.push({nxt,steps+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};