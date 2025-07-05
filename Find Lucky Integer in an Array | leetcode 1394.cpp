// https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxFreq = -1;
        unordered_map<int, int> freq;
        for(int num : arr) freq[num]++;

        for(auto& [a, b] : freq){
            if(a == b) maxFreq = max(maxFreq, a);
        }

        return maxFreq;
    }
};
