problem: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/?envType=daily-question&envId=2025-07-08


class Solution {
private:
    int helper(vector<vector<int>>& dp, vector<vector<int>>& events, int k, int n, int idx){
        if(k == 0 || idx >= n) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];

        // find the next events index
        int i = idx+1;
        while(i < n && events[idx][1] >= events[i][0]) i++;

        // return max(take, noTake)
        return dp[idx][k] = max(events[idx][2]+helper(dp, events, k-1, n, i), helper(dp, events, k, n, idx+1));
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

        return helper(dp, events, k, n, 0);
    }
};
