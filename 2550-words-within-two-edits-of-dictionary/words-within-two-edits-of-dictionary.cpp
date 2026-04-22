class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& directions) {
        int n = queries.size();
        int m = directions.size();
        vector<string>ans;

        for(int it = 0;it<n;it++){
            string q = queries[it];

            for(int k = 0;k<m;k++){
                string dir = directions[k];

                if(q == dir){
                    ans.push_back(q);
                    break;
                }
                
                int diff = 0;

                for(int i = 0;i<q.size();i++){
                    if(q[i] != dir[i])
                        diff++;
                }

                if(diff < 3){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};