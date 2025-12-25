class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(auto& num: happiness) pq.push(num);

        long long maxi = 0;
        int turn = 0;
        while(k--) {
            maxi += max(0, pq.top() - turn);
            pq.pop();
            turn++;
        }

        return maxi;
    }
};