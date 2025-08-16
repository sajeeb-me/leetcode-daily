problem: https://leetcode.com/problems/range-product-queries-of-powers/description/?envType=daily-question&envId=2025-08-11

solution: 
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bint;
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) bint.push_back(1 << i);
        }

        int len = bint.size();
        vector<long long> prefix(len + 1, 1);
        for (int i = 0; i < len; ++i) {
            prefix[i + 1] = (prefix[i] * bint[i]) % MOD;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long num = prefix[r + 1];
            long long denomInv = modPow(prefix[l], MOD - 2);
            ans.push_back((num * denomInv) % MOD);
        }
        return ans;
    }
};
