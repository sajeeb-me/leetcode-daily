problem: https://leetcode.com/problems/reordered-power-of-2/?envType=daily-question&envId=2025-08-10

solution:
class Solution {
private:
    string helper(int n){
        string str = to_string(n);
        sort(str.begin(), str.end());
        return str;
    }

public:
    bool reorderedPowerOf2(int n) {
        string target = helper(n);
        for(int i=0; i<=30; i++)
            if(helper(1 << i) == target) return true;
        return false;
    }
};
