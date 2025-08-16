problem: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2025-07-23

solution:
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        int highVal = max(x, y);
        int lowVal = min(x, y);
        string highStr = x > y ? "ab" : "ba";
        string lowStr = x > y ? "ba" : "ab";
        vector<char> highValSt, lowValSt;

        for(char ch : s){
            if(ch == highStr[1] && !highValSt.empty() && highValSt.back() == highStr[0]){
                res += highVal;
                highValSt.pop_back();
            } else highValSt.push_back(ch);
        }

        for(char ch : highValSt){
            if(ch == lowStr[1] && !lowValSt.empty() && lowValSt.back() == lowStr[0]){
                res += lowVal;
                lowValSt.pop_back();
            } else lowValSt.push_back(ch);
        }

        return res;
    }
};
