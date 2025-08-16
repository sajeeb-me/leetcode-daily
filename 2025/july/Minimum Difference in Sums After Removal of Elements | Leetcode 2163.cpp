problem: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/?envType=daily-question&envId=2025-07-18

solution:
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> L;
        priority_queue<int, vector<int>, greater<int>> R;
        long long size = nums.size();
        long long n = size/3, left = 0, right = 0, ans = LLONG_MAX;
        vector<long long> arr(size, 0);

        for(int i=size-1; i>=n; i--){
            R.push(nums[i]);
            right += nums[i];
            if(R.size() > n){
                right -= R.top(); R.pop();
            }
            if(R.size() == n) arr[i] = right;
        }

        for(int i=0; i<size-n; i++){
            L.push(nums[i]);
            left += nums[i];
            if(L.size() > n){
                left -= L.top(); L.pop();
            }
            if(L.size() == n) ans = min(ans, left - arr[i+1]);
        }

        return ans;
    }
};
