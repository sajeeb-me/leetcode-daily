problem: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25

solution:
class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int maxNum = INT_MIN;
        for(const int num : nums){
            maxNum = max(maxNum, num);
            if(num > 0) st.insert(num);
        }

        if(maxNum <= 0) return maxNum;
        int res = 0;
        for(const int el : st) res += el;
        return res;
    }
};
