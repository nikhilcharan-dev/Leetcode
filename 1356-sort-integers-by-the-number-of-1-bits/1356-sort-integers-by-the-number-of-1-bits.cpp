class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int ba = __builtin_popcount(a);
            int bb = __builtin_popcount(b);
            if(ba == bb) {
                return a < b;
            }
            return ba < bb;
        });
        return arr;
    }
};