// Problem: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/?envType=daily-question&envId=2025-06-29

// Solution:

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int MOD = 1e9 + 7;
        int n = nums.size(), l = 0, r = n - 1, res = 0;
        vector<int> arr(n, 1);
        for (int i = 1; i < n; i++)
            arr[i] = (arr[i - 1] * 2) % MOD;

        while (l <= r)
        {
            if (nums[l] + nums[r] > target)
                r--;
            else
            {
                res = (res + arr[r - l]) % MOD;
                l++;
            }
        }

        return res;
    }
};