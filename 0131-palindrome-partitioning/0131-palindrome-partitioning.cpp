class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> cur(1, string(1, s[0]));
        helper(s, 1, cur, s.size(), 1);
        return ans;
    }

    void helper(string& s, int i, vector<string> cur, int n, bool pip) {
        if(i == n && pip) {
            ans.push_back(cur);
            return;
        }
        
        if(i > n - 1) return;

        cur.push_back(string(1, s[i]));
        if(pip) helper(s, i + 1, cur, n, pip);
        cur.pop_back();

        cur.back() += s[i];
        pip = isPalindrome(cur.back());
        helper(s, i + 1, cur, n, pip);
    }

    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
};