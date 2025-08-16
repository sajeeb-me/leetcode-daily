problem: https://leetcode.com/problems/fruit-into-baskets/description/?envType=daily-question&envId=2025-08-04

solution:
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>freq;
        int ans = 0, l = 0;
        for(int r=0; r<fruits.size(); r++){
            freq[fruits[r]]++;
            while(freq.size() > 2){
                if(--freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
