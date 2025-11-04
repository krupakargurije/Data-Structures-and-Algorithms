class Solution {
public:
    void swapChars(string &s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    string nextPermutation(string s) {
        int n = s.size(), i = n - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i < 0) return s;

        int j = n - 1;
        while (j > i && s[j] <= s[i]) {
            j--;
        }

        swapChars(s, i, j);
        reverse(s.begin() + i + 1, s.end());
        return s;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0, odd = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                odd = i;
                if (oddCount > 1)
                    return "";
            }
        }

        string sb = "";
        bool appendFrom0 = false, appendFromN = false;
        int i = 0;

        while (i < n) {
            char c = target[i];
            if (appendFrom0) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (freq[j - 'a'] > 1) {
                        sb.push_back(j);
                        freq[j - 'a'] -= 2;
                        break;
                    }
                }
            } else if (appendFromN) {
                for (char j = 'z'; j >= 'a'; j--) {
                    if (freq[j - 'a'] > 1) {
                        sb.push_back(j);
                        freq[j - 'a'] -= 2;
                        break;
                    }
                }
            } else {
                bool foundVal = false;
                for (char j = c; j <= 'z'; j++) {
                    if (freq[j - 'a'] > 1) {
                        sb.push_back(j);
                        freq[j - 'a'] -= 2;
                        foundVal = true;
                        if (j > c) appendFrom0 = true;
                        break;
                    }
                }
                if (!foundVal) appendFromN = true;
            }
            i++;
        }

        string computedString = sb;
        if (odd != -1)
            computedString.push_back(char(odd + 'a'));

        string revSb = sb;
        reverse(revSb.begin(), revSb.end());
        computedString += revSb;

        if (computedString > target)
            return computedString;

        // Try next permutation
        string nextPermutationString = nextPermutation(sb);
        if (nextPermutationString.empty())
            return "";

        computedString = nextPermutationString;
        if (odd != -1)
            computedString.push_back(char(odd + 'a'));

        revSb = nextPermutationString;
        reverse(revSb.begin(), revSb.end());
        computedString += revSb;

        if (computedString > target)
            return computedString;

        return "";
    }
};