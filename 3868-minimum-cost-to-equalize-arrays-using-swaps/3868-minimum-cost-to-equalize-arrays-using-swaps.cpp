class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a, b, mp;
        for(auto& num: nums1) {
            a[num]++;
            mp[num]++;
        }

        for(auto& num: nums2) {
            b[num]++;
            mp[num]++;
        }
        int cnt = 0;
        for(auto& [k, v]: mp) {
            if(v & 1) return -1;
            if(a[k] != b[k]) {
                cnt += abs(a[k] - b[k]);
            }
        }
        return (cnt / 4);
    }
};