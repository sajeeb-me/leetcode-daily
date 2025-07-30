problem: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

solution:
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int length = 1, tempLength = 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        for(const int num : nums){
            if(num == maxNum) tempLength++;
            else{
                length = max(length, tempLength);
                tempLength = 0;
            }
        }
        return max(length, tempLength);
    }
};
