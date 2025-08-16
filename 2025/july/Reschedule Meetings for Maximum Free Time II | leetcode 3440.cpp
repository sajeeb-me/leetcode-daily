// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/?envType=daily-question&envId=2025-07-10

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n+1);

        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];
        for(int i=1; i<n; i++) gaps[i] = startTime[i] - endTime[i-1];

        vector<int> maxRight(n+1);
        for(int i=n-1; i>=0; i--) maxRight[i] = max(gaps[i+1], maxRight[i+1]);

        int ans=0, maxLeft=0;
        for(int i=1; i<=n; i++){
            int duration = endTime[i-1] - startTime[i-1];
            if(duration <= max(maxRight[i], maxLeft)) ans = max(ans, gaps[i]+gaps[i-1]+duration);
            else ans = max(ans, gaps[i]+gaps[i-1]);

            maxLeft = max(maxLeft, gaps[i-1]);
        }
        return ans;
    }
};
