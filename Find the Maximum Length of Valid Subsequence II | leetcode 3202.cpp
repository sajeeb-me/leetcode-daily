Problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int mxL = 0;
        for(int num : nums){
            int remainder = num % k;
            for(int j=0; j<k; j++){
                dp[remainder][j] = dp[j][remainder] + 1;
                mxL = max(mxL, dp[remainder][j]);
            }
        }
        return mxL;
    }
};
