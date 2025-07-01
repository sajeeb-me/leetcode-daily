// https://leetcode.com/problems/find-the-original-typed-string-i/description/?source=submission-noac

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int res = 1;
        for (int i = 1; i < word.length(); i++)
        {
            if (word[i - 1] == word[i])
                res++;
        }
        return res;
    }
};