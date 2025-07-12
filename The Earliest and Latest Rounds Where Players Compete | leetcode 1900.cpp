// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/?envType=daily-question&envId=2025-07-12

class Solution {
private:
    int earliest = INT_MAX, latest = INT_MIN;

    void dfs(int playersMask, int round, int left, int right, int firstPlayer, int secondPlayer) {
        // Base case: no more pairs to compare in this round — move to next round
        if (left >= right) {
            dfs(playersMask, round + 1, 0, 27, firstPlayer, secondPlayer);
            return;
        }

        // Skip inactive player on left
        if ((playersMask & (1 << left)) == 0) {
            dfs(playersMask, round, left + 1, right, firstPlayer, secondPlayer);
            return;
        }

        // Skip inactive player on right
        if ((playersMask & (1 << right)) == 0) {
            dfs(playersMask, round, left, right - 1, firstPlayer, secondPlayer);
            return;
        }

        // If firstPlayer and secondPlayer meet
        if (left == firstPlayer && right == secondPlayer) {
            earliest = min(earliest, round);
            latest = max(latest, round);
            return;
        }

        // Simulate both possible outcomes for this match
        if (left != firstPlayer && left != secondPlayer)
            dfs(playersMask ^ (1 << left), round, left + 1, right - 1, firstPlayer, secondPlayer);

        if (right != firstPlayer && right != secondPlayer)
            dfs(playersMask ^ (1 << right), round, left + 1, right - 1, firstPlayer, secondPlayer);
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int initialMask = (1 << n) - 1;  // All n players are active
        dfs(initialMask, 1, 0, n - 1, firstPlayer - 1, secondPlayer - 1);  // Convert to 0-indexed
        return { earliest, latest };
    }
};
