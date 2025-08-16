problem: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/?envType=daily-question&envId=2025-07-24

solution:
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj_list(n);
        for (auto& e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        vector<int> xorTree(n);
        vector<int> in(n), out(n);
        int time = 0;

        function<void(int, int)> dfs = [&](int node, int par) {
            xorTree[node] = nums[node];
            in[node] = time++;

            for (int nei : adj_list[node]) {
                if (nei != par) {
                    dfs(nei, node);
                    xorTree[node] ^= xorTree[nei];
                }
            }
            out[node] = time++;
        };

        dfs(0, -1);
        auto isAncestor = [&](int u, int v) {
            return in[u] < in[v] && out[u] > out[v];
        };

        int res = INT_MAX;
        int totalXor = xorTree[0];

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j, x, y, z;
                if (isAncestor(a, b)) {
                    x = xorTree[b];
                    y = xorTree[a] ^ xorTree[b];
                    z = totalXor ^ xorTree[a];
                } else if (isAncestor(b, a)) {
                    x = xorTree[a];
                    y = xorTree[b] ^ xorTree[a];
                    z = totalXor ^ xorTree[b];
                } else {
                    x = xorTree[a];
                    y = xorTree[b];
                    z = totalXor ^ xorTree[a] ^ xorTree[b];
                }
                res = min(res, max({x, y, z}) - min({x, y, z}));
            }
        }
        return res;
    }
};
