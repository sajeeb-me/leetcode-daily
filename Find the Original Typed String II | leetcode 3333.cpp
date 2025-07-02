// https://leetcode.com/problems/find-the-original-typed-string-ii/description/?envType=daily-question&envId=2025-07-02

class Solution
{
    int MOD = 1e9 + 7;

private:
    // This function will give you TLE. I used it for brute-force approach. I just commented where I called it.
    long long countInvalid(int idx, int length, vector<int> &freq, int k)
    {
        long long result = 0;

        // cout << "idx: " << idx << ", length: " << length << endl;

        if (idx >= freq.size())
        {
            if (length < k)
                return 1;
            return 0;
        }

        for (int i = 1; i <= freq[idx]; i++)
        {
            if (i + length < k)
                result = (result + countInvalid(idx + 1, i + length, freq, k)) % MOD;
            else
                break;
        }

        return result;
    }

public:
    int possibleStringCount(string word, int k)
    {
        if (k > word.length())
            return 0;
        if (k == word.length())
            return 1;

        vector<int> freq;
        int count = 1;
        for (int i = 1; i < word.length(); i++)
        {
            if (word[i - 1] == word[i])
                count++;
            else
            {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long total = 1;
        for (int f : freq)
            total = (total * f) % MOD;

        int freqSz = freq.size();
        if (freqSz >= k)
            return total;

        // long long invalid = countInvalid(0, 0, freq, k);
        vector<vector<int>> t(freqSz + 1, vector<int>(k + 1, 0));
        for (int count = k - 1; count >= 0; count--)
        {
            t[freqSz][count] = 1;
        }

        for (int i = freqSz - 1; i >= 0; i--)
        {
            vector<int> prefix(k + 1, 0);
            for (int h = 1; h <= k; h++)
            {
                prefix[h] = (prefix[h - 1] + t[i + 1][h - 1]) % MOD;
            }

            for (int count = k - 1; count >= 0; count--)
            {
                int l = count + 1;
                int r = count + freq[i];

                if (r + 1 > k)
                    r = k - 1;
                if (l <= r)
                    t[i][count] = (prefix[r + 1] - prefix[l] + MOD) % MOD;
            }
        }

        long long invalid = t[0][0];
        return (total - invalid + MOD) % MOD;
    }
};