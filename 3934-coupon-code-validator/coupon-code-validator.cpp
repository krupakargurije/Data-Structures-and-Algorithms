class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> electronics, grocery, pharmacy, restaurant;

        for (int i = 0; i < n; i++) {

            if (!isActive[i]) continue;
            if (code[i].empty()) continue;

            // Validate characters
            bool isValid = true;
            for (char ch : code[i]) {
                if (!(isalnum(ch) || ch == '_')) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) continue;

            // Categorize
            const string& bl = businessLine[i];
            if (bl == "electronics") electronics.push_back(code[i]);
            else if (bl == "grocery") grocery.push_back(code[i]);
            else if (bl == "pharmacy") pharmacy.push_back(code[i]);
            else if (bl == "restaurant") restaurant.push_back(code[i]);
        }

        // sort each category (preserve duplicates)
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        // combine
        vector<string> ans;
        ans.insert(ans.end(), electronics.begin(), electronics.end());
        ans.insert(ans.end(), grocery.begin(), grocery.end());
        ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
        ans.insert(ans.end(), restaurant.begin(), restaurant.end());

        return ans;
    }
};
