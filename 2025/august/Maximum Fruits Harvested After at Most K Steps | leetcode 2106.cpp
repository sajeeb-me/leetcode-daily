problem: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/?envType=daily-question&envId=2025-08-03

solution:
class Solution {
private:
    int steps(int left, int right, int pos){
        int leftDist = abs(pos - left) + (right - left);
        int rightDist = abs(pos - right) + (right - left);
        return min(leftDist, rightDist);
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left=0, right=0, maxFruits = 0, currFruits = 0;
        while(right < fruits.size()){
            currFruits += fruits[right][1];
            while(left <= right && steps(fruits[left][0], fruits[right][0], startPos) > k){
                currFruits -= fruits[left][1];
                left++;
            }
            maxFruits = max(maxFruits, currFruits);
            right++;
        }
        return maxFruits;
    }
};
