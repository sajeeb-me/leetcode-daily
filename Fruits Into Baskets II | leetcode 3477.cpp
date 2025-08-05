problem: https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05

solution:
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int total = fruits.size();
        for(int fr : fruits){
            for(int j=0; j<baskets.size(); j++){
                if(fr <= baskets[j]){
                    baskets[j] = 0;
                    total--;
                    break;
                }
            }
        }
        return total;
    }
};
