class Solution {
public:
    int n, m;
    vector<vector<int>> res;
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rS, int cS) {
        int max_size = rows * cols;
        n = rows, m = cols;

        res.push_back({ rS, cS });

        int r = 1, d = 1, u = 2, l = 2;

        int R, C;
        R = res.back()[0];
        C = res.back()[1];

        while(res.size() < max_size) {
            // Right
            for(int i = 1; i <= r; i++) {
                int nc = C + 1;
                if(isValid(R, nc)) {
                    res.push_back({ R, nc });
                }
                else {
                    cout << "Skipping Right: " << R << ", " << nc << endl;
                }

                C = nc;
            }

            // Down
            for(int i = 1; i <= d; i++) {
                int nr = R + 1;
                if(isValid(nr, C)) {
                    res.push_back({ nr, C });
                }
                else {
                    cout << "Skipping Down: " << nr << ", " << C << endl;
                }

                R = nr;
            }

            // Left
            for(int i = 1; i <= l; i++) {
                int nc = C - 1;
                if(isValid(R, nc)) {
                    res.push_back({ R, nc });
                }
                else {
                    cout << "Skipping Down: " << R << ", " << nc << endl;
                }

                C = nc;
            }


            // Down
            for(int i = 1; i <= u; i++) {
                int nr = R - 1;
                if(isValid(nr, C)) {
                    res.push_back({ nr, C });
                }

                else {
                    cout << "Skipping Up: " << nr << ", " << C << endl;
                }

                R = nr;
            }

            r = l + 1;
            d = u + 1;
            l = r + 1;
            u = d + 1;
        }

        return res;
    }

    bool isValid(int i, int j) {
        return !(
            i < 0 || i >= n ||
            j < 0 || j >= m
        );
    }
};