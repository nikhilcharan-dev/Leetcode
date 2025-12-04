class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        int i = 0, j = n - 1;

        while (i < n && dir[i] == 'L') i++;
        while (j >= 0 && dir[j] == 'R') j--;

        int collisions = 0;
        unordered_map<char, vector<int>> mp;
        for (int k = i; k <= j; k++) {

            if (dir[k] == 'S') {
                int right = mp['R'].size();
                int prev = mp['S'].size();
                if(right == 0) continue;
                
                int stPos = prev ? mp['S'].back() : -1;
                if(mp['R'].back() < stPos) continue;

                mp['R'].clear();
                collisions += right;
            } else if(dir[k] == 'L') {
                int right = mp['R'].size();
                int st = mp['S'].size();

                // if(right + st == 0) continue;

                int rtPos = right ?  mp['R'].back() : -1;
                int stPos = st ? mp['S'].back() : -1;

                if(rtPos > stPos) {
                    int right = mp['R'].size();
                    mp['R'].clear();
                    mp['S'].push_back(k);
                    collisions += right + 1;
                    // cout << "Collision at: " << k << endl;
                } else {
                    mp['S'].push_back(k);
                    collisions += 1;
                }

            } else {
                mp['R'].push_back(k);
            }

            // cout << "Collisions till: " << k << " " << collisions << '\n';
        }

        return collisions;
    }
};