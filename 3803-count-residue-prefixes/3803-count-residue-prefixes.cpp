class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            if(mp.size() == (i + 1) % 3) {
                ans++;
            }
        }
        return ans;
    }
};