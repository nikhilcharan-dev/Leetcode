class Solution {
public:
    int fib(int n) {
        double pve = pow((1 + sqrt(5)) / 2, n);
        double nve = pow((1 - sqrt(5)) / 2, n);
        return (pve - nve ) / sqrt(5);
    }
};