class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> x, y;

        sort(buildings.begin(), buildings.end());
        for (auto& b : buildings) {
            x[b[0]].push_back(b[1]);
            y[b[1]].push_back(b[0]);
        }

        int cnt = 0;

        for (int yi = 2; yi < n; yi++) {
            auto& row = y[yi];
            if (row.size() < 3)
                continue;

            for (int j = 1; j + 1 < row.size(); j++) {
                int xcoord = row[j];
                auto& col = x[xcoord];

                if (col.size() >= 3 && yi != col.front() && yi != col.back()) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
