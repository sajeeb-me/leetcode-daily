problem: https://leetcode.com/problems/soup-servings/description/?envType=daily-question&envId=2025-08-08

solution:
class Solution {
    vector<vector<double>> dp;
private:
    double helper(int A, int B){
        if(A <= 0 && B <= 0) return 0.5;
        if(A <= 0) return 1.0;
        if(B <= 0) return 0;

        if(dp[A][B] != -1) return dp[A][B];
        return dp[A][B] = 0.25 * (
            helper(A-4, B) +
            helper(A-3, B-1) +
            helper(A-2, B-2) +
            helper(A-1, B-3)
        );
    }

public:
    double soupServings(int n) {
        if(n >= 5000) return 1;
        n = (n+24)/25;
        dp.assign(n+1, vector<double>(n+1, -1));
        int A = n, B = n;
        return helper(A, B);
    }
};
