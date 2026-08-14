class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>mp(26 , -1);

        for(int i = 0;i<n;i++){
            mp[s[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;
        vector<int>ans;

        for(int i = 0;i<n;i++){
            char curr = s[i];

            right = max(right , mp[curr - 'a']);

            if(right == i){
                ans.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return ans;
    }
};

// ababcbaca defegdehijhklij

// a = 8
// b = 4
// c = 7