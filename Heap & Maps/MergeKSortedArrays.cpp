// https://www.interviewbit.com/problems/merge-k-sorted-arrays/

struct Item {
    int val, i, j;
};

struct CompareItem {
    bool operator() (Item i1, Item i2) {
        return i1.val > i2.val;
    }
};


vector<int> Solution::solve(vector<vector<int> > &A) {
    
    priority_queue<Item, vector<Item>, CompareItem> pq;
    for (int i=0; i<A.size(); i++) {
        Item it = {A[i][0], i , 0};
        pq.push(it);
    }

    vector<int> ret;
    while (!pq.empty()) {
        Item top = pq.top(); pq.pop();
        ret.push_back(top.val);
        if(top.j + 1 < A[0].size()) {
            Item it = {A[top.i][top.j + 1], top.i , top.j+1};
            pq.push(it);
        }
    }
    return ret;
}
