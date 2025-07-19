problem: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2025-07-19

solution:
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> arr;
        arr.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string currFolder = arr.back();
            currFolder += '/';
            // string1.compare(pos, len, string2)
            if(folder[i].compare(0, currFolder.length(), currFolder) != 0)
                arr.push_back(folder[i]);
        }

        return arr;
    }
};
