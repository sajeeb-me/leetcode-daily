// problem link: https://leetcode.com/problems/longest-subsequence-repeated-k-times/?envType=daily-question&envId=2025-06-27

class Solution
{
private:
    bool helper(string s, int k, string str)
    {
        int count = 0, i = 0;
        for (char ch : s)
        {
            if (ch == str[i])
            {
                if (++i == str.size())
                {
                    i = 0;
                    count++;
                    if (count == k)
                        return true;
                }
            }
        }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        string res = "";
        queue<string> q;
        q.push("");
        while (!q.empty())
        {
            string str = q.front();
            q.pop();
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                string newStr = str + ch;
                if (helper(s, k, newStr))
                {
                    res = newStr;
                    q.push(newStr);
                }
            }
        }
        return res;
    }
};