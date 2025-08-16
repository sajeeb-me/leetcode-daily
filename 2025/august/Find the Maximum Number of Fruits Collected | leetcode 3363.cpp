problem: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/?envType=daily-question&envId=2025-08-07

solution:
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size(), ans = 0, pass=1;

        for(int i=0; i<n; i++) ans += fruits[i][i];

        while(pass <= 2){
            vector<int> prev(n, -1);
            prev[n-1] = fruits[0][n-1];

            for(int row=1; row<n-1; row++){
                vector<int> curr(n, -1);
                for(int i=0; i<n; i++){
                    if(prev[i] < 0) continue;
                    if(i > 0) curr[i-1] = max(curr[i-1], prev[i] + fruits[row][i-1]);
                    if(i < n-1) curr[i+1] = max(curr[i+1], prev[i] + fruits[row][i+1]);
                    curr[i] = max(curr[i], prev[i] + fruits[row][i]);
                }
                swap(prev, curr);
            }
            ans += prev[n-1];

            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    swap(fruits[i][j], fruits[j][i]);
                }
            }
            pass++;
        }
        return ans;
    }
};
