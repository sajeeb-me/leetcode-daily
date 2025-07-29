problem: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/

solution:
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nearest(32, -1), ans(n);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<32; j++){
                if(nums[i] & (1<<j)) nearest[j] = i;
            }
            int setBit = i;
            for(int j=0; j<32; j++){
                setBit = max(setBit, nearest[j]);
            }
            ans[i] = setBit - i + 1;
        }
        return ans;
    }
};
