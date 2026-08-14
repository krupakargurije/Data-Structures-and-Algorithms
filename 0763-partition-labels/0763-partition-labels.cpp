class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>mp(26 , -1);

        for(int i = 0;i<n;i++){
            mp[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;
        vector<int>ans;

        for(int i = 0;i<n;i++){
            char curr = s[i];

            end = max(end , mp[curr - 'a']);

            if(end == i){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

// ababcbaca defegdehijhklij

// a = 8
// b = 4
// c = 7