// https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15

class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool vowel = false, consonant = false;
        for(char ch : word){
            char newCh = tolower(ch);
            if(!vowel || !consonant){
                if(newCh == 'a' || newCh == 'e' || newCh == 'i' || newCh == 'o' || newCh == 'u')  vowel = true;
                else if(newCh >= 'b' && newCh <= 'z') consonant = true;
            }
            if((newCh < '0' || newCh > '9') && (newCh < 'a' || newCh > 'z')) return false;
        }
        return (vowel && consonant);
    }
};
