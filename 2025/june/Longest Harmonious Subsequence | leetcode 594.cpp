// https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30

// Solution 1:
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        int maxL = 0;
        for (auto &[num, count] : freq)
        {
            if (freq.count(num + 1))
            {
                maxL = max(maxL, freq[num + 1] + count);
            }
        }
        return maxL;
    }
};

// Solution 2:
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0, j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] - nums[j] > 1)
                j++;
            if (nums[i] - nums[j] == 1)
                res = max(res, i - j + 1);
        }
        return res;
    }
};