problem: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/?envType=daily-question&envId=2025-07-27

solution:
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0, prev = nums[0];

        for(int i=1; i<nums.size()-1; i++){
            if((nums[i] > prev && nums[i] > nums[i+1]) || (nums[i] < prev && nums[i] < nums[i+1])){
                count++;
                prev = nums[i];
            }
        }

        return count;
    }
};
