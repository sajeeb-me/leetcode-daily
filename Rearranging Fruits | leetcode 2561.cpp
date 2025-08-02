problem: https://leetcode.com/problems/rearranging-fruits/description/?envType=daily-question&envId=2025-08-02

solution:
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        vector<int>arr;
        unordered_map<int, int> count;
        for(int num : basket1) count[num]++;
        for(int num : basket2) count[num]--;

        for(auto& [key, val] : count){
            if(val % 2 == 1) return -1;
            for(int i=0; i<abs(val)/2; i++) arr.push_back(key);
        }
        
        int minNum = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        nth_element(arr.begin(), arr.begin() + (arr.size()/2), arr.end());
        return accumulate(arr.begin(), arr.begin() + (arr.size()/2), 0ll, 
            [&](long long s, int x) -> long long {
                return s + min(2 * minNum, x);
            }
        );
    }
};
