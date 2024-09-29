class Solution {
public:
    int trailingZeroes(int n) {
       int count = 0;
        // Count how many multiples of 5, 25, 125, etc. are there in n
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
        return count;
    }
};