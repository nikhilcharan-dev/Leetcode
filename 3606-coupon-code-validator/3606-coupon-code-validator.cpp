class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> ans;
        static const unordered_set<string> valid = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<int> idx(n, 0);
        for(int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](const int a, const int b) {
            if(businessLine[a] == businessLine[b]) {
                return code[a] < code[b];
            }
            return businessLine[a] < businessLine[b];
        });

        for(int i = 0; i < n; i++) {
            if(isValid(code[idx[i]]) && isActive[idx[i]] && valid.find(businessLine[idx[i]]) != valid.end()) {
                ans.push_back(code[idx[i]]);
            }
        }
        
        return ans;
    }

    bool isValid(string& s) {
        static const regex p("^[a-zA-Z0-9_]+$");
        return regex_match(s, p);
    }
};