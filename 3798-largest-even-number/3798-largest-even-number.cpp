class Solution {
public:
    string largestEven(string s) {
        int i = s.size() - 1;
        while(i >= 0 && (s[i] - '0') % 2) {
            s.pop_back();
            i--;
        }
        return s;
    }
};