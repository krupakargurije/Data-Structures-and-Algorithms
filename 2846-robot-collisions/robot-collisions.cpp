class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<pair<int,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        
        sort(robots.begin(), robots.end());
        
        stack<int> st;
        
        for(auto &it : robots){
            int idx = it.second;

            if(directions[idx] == 'R'){
                st.push(idx);
            }
            else{
                while(!st.empty() && healths[idx] > 0){
                    int j = st.top();

                    if(healths[j] == healths[idx]){
                        st.pop();
                        healths[j] = 0;
                        healths[idx] = 0;
                        break;
                    }
                    else if(healths[j] < healths[idx]){
                        st.pop();
                        healths[j] = 0;
                        healths[idx] -= 1;
                    }
                    else{
                        healths[idx] = 0;
                        healths[j] -= 1;
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};