class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // {position, index}
        vector<pair<int,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        
        // sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // store indices of robots moving right
        
        for(auto &it : robots) {
            int i = it.second;
            
            if(directions[i] == 'R') {
                st.push(i);
            } else {
                // current robot is moving left
                while(!st.empty() && healths[i] > 0) {
                    int j = st.top();
                    
                    if(healths[j] < healths[i]) {
                        // right robot dies
                        st.pop();
                        healths[j] = 0;
                        healths[i] -= 1;
                    }
                    else if(healths[j] > healths[i]) {
                        // left robot dies
                        healths[i] = 0;
                        healths[j] -= 1;
                        break;
                    }
                    else {
                        // both die
                        st.pop();
                        healths[i] = 0;
                        healths[j] = 0;
                        break;
                    }
                }
            }
        }
        // collect survivors in original order
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};