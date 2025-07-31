problem: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/?envType=daily-question&envId=2025-07-31

solution:
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> res, temp;
        temp.insert(0);
        for(int i : arr){
            set<int> temp2;
            temp2.insert(i);
            for(int j : temp) temp2.insert(i | j);
            temp = temp2;
            res.insert(temp.begin(), temp.end());
        }
        return res.size();
    }
};
