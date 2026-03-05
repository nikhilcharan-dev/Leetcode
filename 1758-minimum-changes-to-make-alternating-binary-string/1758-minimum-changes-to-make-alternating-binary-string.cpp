class Solution {
public:
    int minOperations(string s) {
        int min_0 = 0, min_1 = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            char exp_0 = (i % 2 == 0) ? '1' : '0';
            char exp_1 = (i % 2 == 0) ? '0' : '1';

            if(exp_0 != s[i]) {
                min_0++;
            }
            if(exp_1 != s[i]) {
                min_1++;
            }
        }

        return min(min_0, min_1);
    }
};