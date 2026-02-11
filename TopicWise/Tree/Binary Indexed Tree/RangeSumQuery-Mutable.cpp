// [LC 307] Range Sum Query - Mutable

class NumArray {
private:
    int n;
    vector<int> nums;
    vector<int> bit; // 1 based index

public:
    NumArray(vector<int>& _nums) {
        // Prepare Binary Indexed Tree vector
        n = _nums.size();
        nums.resize(n, 0);
        bit.resize(n + 1, 0);
        
        // Fill values
        for (int i=0; i<n; i++)
            update(i, _nums[i]);
    }
    
    void update(int index, int val) {
        int delta = val - nums[index]; // get delta
        nums[index] = val; // save updated value in nums

        for (int i=index+1; i<=n; i+=(i&(-i)))
            bit[i] += delta;
    }
    
    int sumRange(int left, int right) {
        int sumRight = 0, sumLeft = 0;

        for (int i=right+1; i>0; i-=(i&(-i)))
            sumRight += bit[i];

        for (int i=left; i>0; i-=(i&(-i)))
            sumLeft += bit[i];

        return sumRight - sumLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */