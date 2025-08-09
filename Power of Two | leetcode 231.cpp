problem: https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2025-08-09

solution:
// Bit Manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};


// Loop
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};
