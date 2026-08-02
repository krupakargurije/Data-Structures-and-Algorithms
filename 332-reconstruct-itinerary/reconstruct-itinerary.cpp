class Solution {
    private:
    vector<string>ans;
    void helper(string node ,unordered_map<string , vector<string>> &adj){
        while(!adj[node].empty()) {
            string next = adj[node].back();
            adj[node].pop_back();

            helper(next , adj);
        }
        ans.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();

        unordered_map<string , vector<string>>adj;
        for(auto &it : tickets){
            string u = it[0];
            string v = it[1];

            adj[u].push_back(v);
        }

        for(auto &it : adj){
            sort(it.second.begin() , it.second.end() , greater<>());
        }
        helper("JFK" , adj);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};