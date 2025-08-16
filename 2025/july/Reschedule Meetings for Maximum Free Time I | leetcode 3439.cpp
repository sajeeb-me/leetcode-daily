https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/?envType=daily-question&envId=2025-07-09

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n+1);

        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];
        for(int i=1; i<n; i++) gaps[i] = startTime[i] - endTime[i-1];

        int window = 0;
        for(int i=0; i<=k; i++) window += gaps[i];

        int maxGap = window;
        for(int i=k+1; i<=n; i++){
            window += (gaps[i] - gaps[i - (k+1)]);
            maxGap = max(maxGap, window);
        }
        return maxGap;
    }
};
