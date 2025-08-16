problem: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2025-07-28

solution:
class Solution {
private:
    void findCount(vector<int>& nums, int& count, int maxOR, int currOR, int idx){
        if(currOR == maxOR) count++;
        for(int i=idx; i<nums.size(); i++)
            findCount(nums, count, maxOR, currOR | nums[i], i+1);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(const int num : nums) maxOR |= num;

        int count = 0;
        findCount(nums, count, maxOR, 0, 0);
        return count;
    }
};
