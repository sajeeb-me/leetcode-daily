// Problem: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/?envType=daily-question&envId=2025-07-03

// Solution:
class Solution {
private:
    char findKth(string word, int k){
        if(word.length() >= k) return word[k-1];

        string temp = word;
        for(int i=0; i<temp.length(); i++){
            if(temp[i] == 'z') temp[i] = 'a';
            else temp[i] = temp[i]+1;
        }
        return findKth(word+temp, k);
    }

public:
    char kthCharacter(int k) {
        if (k == 1) return 'a';
        string word = "a";
        return findKth(word, k);
    }
};
