problem: https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/description/?envType=daily-question&envId=2025-07-26

solution:
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> conflicts(n+1);
        for(const auto& it : conflictingPairs) conflicts[max(it[0], it[1])].push_back(min(it[0], it[1]));

        long long ans = 0;
        pair<long long, long long> length = {0, 0};
        vector<long long> gain(n+1, 0);

        for(int i=1; i<=n; i++){
            for(int st : conflicts[i]){
                if(st > length.first) length = {(long long)st, length.first};
                else if(st > length.second) length = {length.first, (long long)st};
            }

            ans += i-length.first;
            if(length.first > 0) gain[length.first] += length.first-length.second;
        }

        long long maxGain = 0;
        for(long long g : gain) maxGain = max(maxGain, g);
        return ans + maxGain;
    }
};
