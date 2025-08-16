Problem: https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2025-07-21

Solution:
class Solution {
public:
    string makeFancyString(string s) {
        string res = s.substr(0, 2);
        for(int i=2; i<s.length(); i++){
            if(s[i] != s[i-2] || s[i] != s[i-1]) res += s[i];
        }
        return res;
    }
};
