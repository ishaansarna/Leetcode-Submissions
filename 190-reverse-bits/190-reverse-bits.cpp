class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 0;
        while (n != 0) {
            uint32_t bit = n & 1;
            ans |= bit << (31-i);
            n >>= 1;
            i++;
        }
        return ans;
    }
};