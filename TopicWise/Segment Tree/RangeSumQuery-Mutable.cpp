// [LC 307] Range Sum Query - Mutable

class NumArray {
private:
    int n;
    vector<int> nums;
    vector<int> segmentTree;

    void construct(int root, int low, int high) {
        if (low > high) return;
        if (low == high) {
            segmentTree[root] = nums[low];
            return;
        }

        int mid = (high + low) / 2;
        construct(2*root+1, low, mid); // left child
        construct(2*root+2, mid+1, high); // right child
        segmentTree[root] = segmentTree[2*root+1] + segmentTree[2*root+2];
    }


    void updateInRange(int root, int low, int high, int index, int delta) {
        if (index < low || index > high) return;
        if (low > high) return;
        if (low == high) {
            segmentTree[root] += delta;
            return;
        }

        int mid = (high + low) / 2;
        updateInRange(2*root+1, low, mid, index, delta);
        updateInRange(2*root+2, mid+1, high, index, delta);
        segmentTree[root] += delta;
    }

    int getSumRange(int root, int low, int high, int qLow, int qHigh) {
        // If totally inside
        if (qLow <= low && high <= qHigh) return segmentTree[root];

        // If totally outside
        if (qHigh < low || high < qLow) return 0;

        // Partial overlap
        int mid = (high + low) / 2;
        int leftSum = getSumRange(2*root+1, low, mid, qLow, qHigh);
        int rightSum = getSumRange(2*root+2, mid+1, high, qLow, qHigh);
        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();

        // Initialize segment tree
        int segmentTreeSize = 2 * pow(2, ceil(log2(n))) - 1;
        segmentTree.resize(segmentTreeSize, 0);

        // Construct
        construct(0, 0, n-1);
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        updateInRange(0, 0, n-1, index, delta);
    }

    int sumRange(int qLow, int qHigh) {
        return getSumRange(0, 0, n-1, qLow, qHigh);
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */