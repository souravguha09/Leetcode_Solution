class Solution {
public:
    bool canAliceWin(int n) {
        return lround(sqrt(110 - 2 * n)) % 2 == 1;
    }
};