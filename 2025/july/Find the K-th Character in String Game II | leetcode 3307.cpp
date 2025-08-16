// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/?envType=daily-question&envId=2025-07-04

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long dist = 0, curr = 1;
        vector<long long> arr;

        for(int it: operations){
            curr *= 2;
            arr.push_back(curr);
            if(curr >= k) break;
        }

        for(int i=arr.size()-1; i>=0; i--){
            long long mid = arr[i]/2;
            if(k > mid){
                k -= mid;
                dist += operations[i];
            }
        }

        return 'a' + (dist%26);
    }
};
