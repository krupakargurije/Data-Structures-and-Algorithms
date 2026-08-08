class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n2 = word2.size();

        vector<int> dp2(n2, -1);
        int j = n2 - 1;

        for (int i = (int)word1.size() - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                dp2[j] = i;
                j--;
            }
        }

        int changed = 0;
        j = 0;

        vector<int> res;

        for (int i = 0; i < (int)word1.size(); i++) {
            if (j >= n2) {
                break;
            }

            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } else if (changed == 0) {
                if (j == n2 - 1 || i + 1 <= dp2[j + 1]) {
                    changed = 1;
                    res.push_back(i);
                    j++;
                }
            }
        }
        return j == n2 ? res : vector<int>{};
    }
};