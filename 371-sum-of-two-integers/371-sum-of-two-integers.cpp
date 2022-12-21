class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int tmp = (uint32_t)(a&b)<<1;
            a = a^b;
            b = tmp;
        }
        return a;
    }
};