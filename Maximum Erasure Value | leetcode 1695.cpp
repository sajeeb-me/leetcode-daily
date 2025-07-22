problem: https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

solution:
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> numSet;
        int l=0, r=0, sum=0, mx=0;
        while(r < nums.size()){
            while(numSet.count(nums[r])){
                numSet.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            numSet.insert(nums[r]);
            sum += nums[r];
            mx = max(mx, sum);
            r++;
        }
        return mx;
    }
};
