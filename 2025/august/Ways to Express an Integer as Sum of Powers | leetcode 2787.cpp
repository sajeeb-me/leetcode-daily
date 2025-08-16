problem: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/?envType=daily-question&envId=2025-08-12

solution: 
class Solution {
    const int MOD = 1e9+7;
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for(int i=1; ;i++){
            long long p = pow(i, x);
            if(p > n) break;
            powers.push_back((int)p);
        }

        int sz = powers.size();
        vector<vector<int>> dp(sz+1, vector<int>(n+1, 0));
        for(int i=0; i<=sz; i++) dp[i][0] = 1;

        for(int i=1; i<=sz; i++){
            for(int s=1; s<=n; s++){
                dp[i][s] = dp[i-1][s];
                int currPower = powers[i-1];
                if(s >= currPower){
                    dp[i][s] = (dp[i][s] + dp[i-1][s - currPower]) % MOD;
                }
            }
        }

        return dp[sz][n];
    }
};
