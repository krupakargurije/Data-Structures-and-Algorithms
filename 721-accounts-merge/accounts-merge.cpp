class Disjoint {
    vector<int> size, parent;
    
public:
    Disjoint(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findultparent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findultparent(parent[node]);
    }
    
    void unionbysize(int u, int v) {
        int ult_u = findultparent(u);
        int ult_v = findultparent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        Disjoint ds(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                }
                else {
                    ds.unionbysize(i, mp[mail]);
                }
            }
        }
        
        vector<string> maillist[n];
        for(auto it : mp) {
            string mail = it.first;
            int node = ds.findultparent(it.second);
            maillist[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(maillist[i].size() == 0) continue;
            sort(maillist[i].begin(), maillist[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : maillist[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};