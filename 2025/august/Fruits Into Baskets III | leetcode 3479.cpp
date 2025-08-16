problem: https://leetcode.com/problems/fruits-into-baskets-iii/description/?envType=daily-question&envId=2025-08-06

solution:
class Solution {
private:
    void buildSegTree(int i, int l, int r, vector<int>& baskets, vector<int>& segTree){
        if(l == r){
            segTree[i] = baskets[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildSegTree(2*i+1, l, mid, baskets, segTree);
        buildSegTree(2*i+2, mid+1, r, baskets, segTree);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }

    bool isBasketFound(int i, int l, int r, int fruit, vector<int>& segTree){
        if(segTree[i] < fruit) return false;
        if(l == r){
            segTree[i] = -1;
            return true;
        }

        int mid = l + (r-l)/2;
        bool placed = false;

        if(segTree[2*i+1] >= fruit) placed = isBasketFound(2*i+1, l, mid, fruit, segTree);
        else placed = isBasketFound(2*i+2, mid+1, r, fruit, segTree);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return placed;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), unplaced = 0;
        vector<int> segTree(4*n, -1);

        buildSegTree(0, 0, n-1, baskets, segTree);

        for(int fruit : fruits){
            if(!isBasketFound(0, 0, n-1, fruit, segTree)) unplaced++;
        }
        return unplaced;
    }
};
