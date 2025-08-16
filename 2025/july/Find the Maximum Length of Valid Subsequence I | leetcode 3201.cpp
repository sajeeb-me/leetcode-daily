problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0, alt = 0, mod = nums[0]%2;
        for(int num : nums){
            if(num % 2 == 0) even++;
            else odd++;
            if(num % 2 == mod){
                alt++;
                mod = 1 - mod;
            }
        }
        return max({even, odd, alt});
    }
};
