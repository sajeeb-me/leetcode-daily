problem: https://leetcode.com/problems/power-of-three/description/?envType=daily-question&envId=2025-08-13

solution:
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) n /= 3;
        return n == 1;
    }
};
